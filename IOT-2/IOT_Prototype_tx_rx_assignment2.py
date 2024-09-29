#!/usr/bin/env python3

from LoRaWAN_TTN import LoRaWANtxrx
from time import sleep
from SX127x.LoRa import *
from SX127x.board_config import BOARD

# Import the RPi module to work with the GPIOs
import RPi.GPIO as GPIO
# Import the DHT11 module to manage the sensor module
import dht11
# Import the system module
import sys

# Import the Cayenne LPP as the patload formattter for uplink messages
from cayennelpp import LppFrame, LppUtil
#import json

# Import random class
import random 


# 
GPIO.setwarnings(False)
BOARD.setup()

def retrieve_sensor_Cayenne(pin):
    
    # Manually calculate the digit sum of my student ID (Part of Task 3.(ii))
    DIGIT_SUM = 25
    
    # Initialise the DHT11 sensor module (Part of Task  3.(iii))
    dht11_sensor_module = dht11.DHT11(pin)
    
    # Retrieve the data from the sensors (check that data is valid)
    while True:
        data = dht11_sensor_module.read()
        # Validate the data retrieved
        if data.is_valid():
            # Extract the temperature and humidity values
            temperature = data.get_temperature() # Celsius
            humidity = data.get_humidity() # %
            print("The temperature is",temperature, "C and the humidity is", humidity,"%")
            break
        
    # Create a Cayenne LPP formatted message (Part of Task  3.(iv))
    
    # Create an empty frame 
    frame =LppFrame()
    
    # Add the temperature, humidity values and DIGIT_SUM to the frame
    frame.add_temperature(1,data.get_temperature()) # Celsius
    frame.add_humidity(2,data.get_humidity())# %
    frame.add_digital_output(3,DIGIT_SUM)# DIGIT_SUM
    
    # Create the message in CayenneLPP format
    msg_cayenne_lpp = bytes(frame)
    return msg_cayenne_lpp
    
    

def main():
    
    # Recive input from the terminal (Part of Task  3.(i))
    try:
        pin = int(sys.argv[1])
        if pin==26:
            # Access the GPIOs using the BCM numbering system 
            GPIO.setmode(GPIO.BCM)
            print("Pin is",pin)
        else:
            print("Invalid pin number!")
            sys.exit(1) #sys.exit(1) refers to invalid pin number for DHT11 module
        #Ask user the frame counter
        framecounter = int(sys.argv[2])
        print("Framecounter is",framecounter)
            
    except Exception as e:
        print("There was an exception of type", e.__class__.__name__)
        print("Error: expected an integer")
        sys.exit(2) #sys.exit(2) refers to incorrect type of input
        
    
    # Pre-configured details for ABP
    devaddr = [0x26, 0x0B, 0xCA, 0x05]
    nwkskey = [0x16, 0xA7, 0x91, 0x5B, 0x09, 0x67, 0x8C, 0x2B, 0xF9, 0xC9, 0x0F, 0xFD, 0xE9, 0xFB, 0xD4, 0x7F]
    appskey = [0xD4, 0x80, 0xC9, 0xA9, 0xAC, 0x94, 0xD8, 0x20, 0x60, 0xF1, 0x57, 0xFE, 0x98, 0x93, 0x3D, 0xDC]

    # Create the LoRaWANtxrx object
    lora = LoRaWANtxrx(False)
    
    # Confifure the module for TX
    lora.set_mode(MODE.SLEEP)
    lora.set_dio_mapping([1,0,0,0,0,0])
    lora.set_pa_config(pa_select=1, max_power=0x0F, output_power=0x0E)
    
    # Confifure the module for RX
    lora.set_sync_word(0x34)
    
    # Enable CRC
    lora.set_rx_crc(True)
    
    # Configure LoRa for RX1 (Part of Task 3.(v))
    
    # From Lecture 15, Rb (bits/s) = 1760, Configuration = SF9/125kHz, Data Rate Mode = DR3
    # SF9 refers to Spreading factor = 9,
    # The channel bandwidth is 125 kHz
    # Rb = SF * BW / chips * 4 / (CR+4)
    # We can find CR from above equation and CR = 1
    
    # Set the coding rate 
    lora.set_coding_rate(1)
    
    # Set the bandwitdth : 7 for 125 kHz
    lora.set_bw(7)
    
    # Set the spreading factor = 9
    lora.set_spreading_factor(9)
    
    # Configure LoRaWAN for TX with ABP
    lora.set_devaddr(devaddr)
    lora.set_nwkskey(nwkskey)
    lora.set_appskey(appskey)
    
    # variable use to count number of sending the messages
    number_sender = 0;
    while (number_sender < 5):
        
        # Task 3.(ii,iii,iv)
        msg_cayenne_lpp = retrieve_sensor_Cayenne(pin)
        
        # Create array of G1 frequency from the G1 group with a bandwidth of 125 kHz
        # (Task 3.(vi))
        freqG1=[868.1,868.3,868.5]
        freqrandm=random.choice(freqG1)
        print("The frequency is",freqrandm)
        # Set the channel frequency
        lora.set_freq(freqrandm)
        
        # Set the frame counter
        lora.set_tx_fcnt(number_sender + framecounter)
        
        # 
        print("\n\n",msg_cayenne_lpp)
        
        # Create a frame by setting the payload
        lora.set_tx_data(list((msg_cayenne_lpp)))
        
        
        
        assert(lora.get_agc_auto_on() == 1)
        
        try:
            print("Sending LoRaWAN message\n")
            lora.start()
            while True:
                sleep(.1)
                if lora.has_tx_done() == True:
                    print("TxDone")
                    break
                
            print("Receiving LoRaWAN message in RX1\n")
            
            # Handle received messages from the TTN and
            # Wait until two times the 'desired Rx1 delay' seconds
            # (Task 3.(vii))
            while True:
                sleep(10)
                if lora.has_rx_done() == True:
                    print("Downlink message is ",lora.get_rx_data_bytes(),"\n\n")
                    break
                else:
                    print("No downlink message\n\n")
                    break
                
        except KeyboardInterrupt:
            sys.stdout.flush()
            print("\nKeyboardInterrupt")
            sys.exit(3)
            
        finally:
            sys.stdout.flush()
            lora.set_mode(MODE.SLEEP)
            
            if (number_sender==4):
                
                # Clean up the GPIOs used and the SPI interface
                BOARD.teardown()
            
                # Clean up the channel
                GPIO.cleanup()
                
                # No error causes during program launching
                sys.exit(0)
        
        # Design the solution with the ETSI EU regulations and TTN policies
        # to limit the maximum number of messages that can be sent in a day.
        # Part 4
        # See more detail about this number in the report
        #sleep(20)
        sleep(593)
        
        # Update number of sending messages
        # Use thisto update frame counter
        number_sender = number_sender + 1;
    
if __name__ == '__main__':
    main()
