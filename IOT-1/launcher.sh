##!/bin/bash

error()
{
	echo "error error"
	if [ "$verbose" == "1" ]; then
		cat verbose.log
		exit 1
	fi
	exit 1
}

verbose=0

optstring=hs:t:u:p:v

# Receive its parameters   (Task 1)
# $ getopt parse positional parameter to options
while getopts $optstring var; do 
	case $var in
	s) ip=$OPTARG ;;
	t) port=$OPTARG ;;
	u) user=$OPTARG ;;
	p) pass=$OPTARG ;;
	v) verbose=$(( $verbose + 1 )) ;;
	h) cat help.log
	   exit 0 
	   ;;
	*) error
	   ;;
	esac
done

# check verbose log file and delete it if the log file exists to prevent previous error details
if [ -f verbose.log ]; then
	rm verbose.log
fi

error_status=0

# check that these parameters are correct (Part of Task 1)
if [ "$ip" != "138.253.77.122" ]; then
	echo "IP is missing or incorrect" >> verbose.log
	error_status=1
fi
if [ "$port" != "8883" ]; then
	echo "Port is missing or incorrect" >> verbose.log
	error_status=1
fi
if [ "$user" != "iot" ]; then
	echo "User is missing or incorrect" >> verbose.log
	error_status=1
fi
if [ "$pass" != "ELEC423_2324." ]; then
	echo "Password is missing or incorrect" >> verbose.log
	error_status=1
fi
if [ "$error_status" == "1" ]; then
	error
else 
	echo "This is fine."
fi

echo -e "IP is $ip \tPORT is $port \nUSERNAME is $user \tPASSWORD is $pass"

#Store Unix time stamp in variable UNIX_TS (Task 2)
UNIX_TS=$(date +%s)

#Manually calculate the digit sum of my student ID and store in variable called DIGIT_SUM (Task 3)
DIGIT_SUM=25

echo "UNIX_TS is $UNIX_TS"


#Retrieve the MAC address of the Ethernet interface (Task 4)
# $ ifconfig "wlan0" states all the Ethernet information
# $ grep "ether" finds the line that has a word "ether"
# $ awk '{print $2}' displays only the second word
# $ tr -d "\:" deletes colon
# command 1 | command 2 | command 3 | command 4 means that the output of previous command will be the input of current command
MAC_Ethernet=$(ifconfig "eth0" | grep "ether" | awk '{print $2}' | tr -d "\:")

#Retrieve the MAC address of Wifi interface
MAC_Wifi=$(ifconfig "wlan0" | grep "ether" | awk '{print $2}' | tr -d "\:")

#Assign topic as following format
topic="/sensor/$MAC_Ethernet/$UNIX_TS/"

client_ID="$MAC_Wifi-$UNIX_TS"

echo "Topic is $topic and client ID is $client_ID"

#Launch the mosquitto MQTT subscriber using mosquitto_sub command and following arguments (Part of Task 4)
mosquitto_sub -h $ip -p $port -u $user -P $pass -t $topic -i "$client_ID-sub" &

#Receive PID of subscriber  (Part of Task 6)
PID_sub=$!

echo "Subscriber is launching"

#Wait 10 seconds (Task 5)
sleep 10s

#Assign a variable with the path to access the DHT11 sensor values via SysFS (Task 6)
IIO_DEVICE_PATH="/sys/bus/iio/devices/iio:device0"

#Reference_time
time_start=$(date +%s)
time_ref=$time_start
#5 minutes = 300 seconds
time_end=$(bc <<< "$time_start + 300")
time_check=$time_ref

if [ -f timecheck.log ]; then
	rm timecheck.log
fi

#Part of Task 6
while [ 1 ]; do

	#Current time
	time_current=$(date +%s)
	
	#Check that time pass 20 seconds, then receive values and publish
	if [ $time_current -ge $time_check ]; then
		#Store the temperature sensor value
		while [ 1 ]; do
			temp_value=$(cat $IIO_DEVICE_PATH/in_temp_input)
			if [ $? = 0 ]; then
				TEMPERATURE_VALUE=$(bc <<< "scale=2;$temp_value * 0.1")
				break
			fi
		done

		#Store the humidity sensor value
		while [ 1 ]; do
        		hum_value=$(cat $IIO_DEVICE_PATH/in_humidityrelative_input)
        		if [ $? = 0 ]; then
                		HUMIDITY_VALUE=$(bc <<< "scale=2;$hum_value * 0.1")
               			break
        		fi
		done

		#Create a message containing the UNIX time stamp, the temperature and humidity sensor values
		#and sum of student ID digits (Part of Task 6)
		message="$UNIX_TS, $TEMPERATURE_VALUE, C, $HUMIDITY_VALUE, %, $DIGIT_SUM"

		#Launch the mosquitto MQTT publisher with the following arguments
		mosquitto_pub -h $ip -p $port -u $user -P $pass -t $topic -i "$client_ID-pub" -m "$message" 
		
		#current time is more than or equals to 300 seconds (5 minutes)
		if [ $time_current -ge $time_end ];then
                	#Terminate the mosquitto MQTT subscriber and publisher after 5 minutes (Task 7)
                	#Publisher kill itself after sending message
                	kill $PID_sub
                	echo "$(date +%s)" >> timecheck.log
                	echo "end loop"
                	break
       		 fi


		time_ref=$(date +%s)
                time_check=$(bc <<< "$time_ref + 20")
		#Use to check that it publish every 20 seconds
		echo "$time_ref" >> timecheck.log
	fi

done

#Terminate the scipt with an appropriate exit code (Task 8)
#Return 0 means no error
exit 0

