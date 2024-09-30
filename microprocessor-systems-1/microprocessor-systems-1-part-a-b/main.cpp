#include "mbed.h"
#include <stdio.h>
#include <stdlib.h>
#include "C12832A1Z.h"

// Define digital inputs for switches connected to pins A2, A3, A4, and A5
DigitalIn SW_UP(A2);
DigitalIn SW_DOWN(A3);
DigitalIn SW_LEFT(A4);
DigitalIn SW_RIGHT(A5);

// Define timer object for 
Timer timer1; 


// Initialize the LCD display with the specified pins
// C12832A1Z(PinName mosi, PinName sck, PinName reset, PinName a0, PinName cs)
C12832A1Z lcd(D11, D13, D12, D7, D10);

// Declare external assembly language function (in a *.s file)
extern "C" int simple_sqrt(int value);
extern "C" int square_root_fpu(int value);


int random(int input)
{
    int output = 0;
    if (input > 99999999 && input <= 999999999){
        output = (10000000 + rand() % 90000000);
    }
    else if (input > 9999999 && input <= 99999999){
        output = (1000000 + rand() % 9000000);
    }
    else if (input > 999999 && input <= 9999999){
        output = (100000 + rand() % 900000);
    }
    else if (input > 99999 && input <= 999999){
        output = (10000 + rand() % 90000);
    }
    else if (input > 9999 && input <= 99999){
        output = (1000 + rand() % 9000);
    }
    else if (input > 999 && input <= 9999){
        output = (100 + rand() % 900);
    }
    else if (input > 0 && input <= 999){
        output = (rand() % 100);
    }

    return output;
}

// main() runs in its own thread in the OS
int main()
{
    
    lcd.cls();
    int id = 201750406;
    int sqrt_val = 0;
    long long unsigned  simple_sqrt_time,square_root_fpu_time;


    /* // Uncomment to test random function
    printf("\n x= %d random = %d\n",999999999, random(999999999));
    printf("\n x= %d random = %d\n",100000000, random(100000000));
    printf("\n x= %d random = %d\n",10000000, random(10000000));
    printf("\n x= %d random = %d\n",1000000, random(1000000));
    printf("\n x= %d random = %d\n",100000, random(100000));
    printf("\n x= %d random = %d\n",10000, random(10000));
    printf("\n x= %d random = %d\n",1000, random(1000));
    printf("\n x= %d random = %d\n",100, random(100));
    printf("\n x= %d random = %d\n",10, random(10));
    printf("\n x= %d random = %d\n",1, random(1));
    // */

    /* //Uncomment to test simple_sqrt assembly code
    printf("\n square root of %d is %d",999999999, simple_sqrt(999999999));
    printf("\n square root of %d is %d",100000000, simple_sqrt(100000000));
    printf("\n square root of %d is %d",10000000, simple_sqrt(10000000));
    printf("\n square root of %d is %d",100000, simple_sqrt(100000));
    printf("\n square root of %d is %d",10000, simple_sqrt(10000));
    printf("\n square root of %d is %d",5000, simple_sqrt(5000));
    printf("\n square root of %d is %d",900, simple_sqrt(900));
    printf("\n square root of %d is %d",122, simple_sqrt(122));
    printf("\n square root of %d is %d",10, simple_sqrt(10));
    printf("\n square root of %d is %d",4, simple_sqrt(4));
    printf("\n square root of %d is %d",2, simple_sqrt(2));
    // */

    /* //Uncomment to test square_root_fpu assembly code
    printf("\n square root fpu of %d is %d",999999999, square_root_fpu(999999999));
    printf("\n square root fpu of %d is %d",100000000, square_root_fpu(100000000));
    printf("\n square root fpu of %d is %d",10000000, square_root_fpu(10000000));
    printf("\n square root fpu of %d is %d",100000, square_root_fpu(100000));
    printf("\n square root fpu of %d is %d",10000, square_root_fpu(10000));
    printf("\n square root fpu of %d is %d",5000, square_root_fpu(5000));
    printf("\n square root fpu of %d is %d",900, square_root_fpu(900));
    printf("\n square root fpu of %d is %d",122, square_root_fpu(122));
    printf("\n square root fpu of %d is %d",10, square_root_fpu(10));
    printf("\n square root fpu of %d is %d",4, square_root_fpu(4));
    printf("\n square root fpu of %d is %d",2, square_root_fpu(2));
    // */

    while (true) {
        if (SW_UP.read()){
            id = id + random(id);
            lcd.cls();
                if (id > 999999999){
                    id = 999999999;
                    lcd.locate(0,20);
                    lcd.printf("Value cannot > 999999999");
                    ThisThread::sleep_for(10s);
                    lcd.cls();
                }
        }
        if (SW_DOWN.read()){
            id = id - (random(id));
            lcd.cls();
                if (id < 0){
                    id = 1;
                    lcd.locate(0,20);
                    lcd.printf("Value cannot < 1");
                    ThisThread::sleep_for(10s);
                    lcd.cls();
                }
        }

        if (SW_LEFT.read()){
        // Uncomment to test exceuted time //
        // timer1.start(); //
        sqrt_val = simple_sqrt(id);
        // timer1.stop(); //
		simple_sqrt_time = timer1.elapsed_time().count();
        // timer1.reset(); //
        // printf("\n simple_sqrt_time = %llu us",simple_sqrt_time); //
        lcd.cls();
        }

        if (SW_RIGHT.read()){
        // timer1.start(); //
        sqrt_val = square_root_fpu(id);
        // timer1.stop(); //
        square_root_fpu_time = timer1.elapsed_time().count();
        // timer1.reset(); //
        // printf("\n square_root_fpu_time = %llu us",square_root_fpu_time); //
        lcd.cls();
        }


        lcd.locate(0,0);
        lcd.printf("Khanthapak Thaipakdee");
        lcd.locate(0,10);
        lcd.printf("ID: %d", id);
        
        lcd.locate(0,20);
        lcd.printf("Square root of ID is %d", sqrt_val);
    }
}
