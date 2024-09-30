# Microprocessor Programming with MBED and Kinetis SDK on FRDM-K64F
This project consists of three parts, aimed at enhancing embedded systems programming and assembly language skills on the FRDM-K64F development board using the MBED platform.

- Part A involves creating a program that interacts with the Application Shield to display the user's name and ID on an LCD screen. The program also enables the user to increment or decrement a displayed number using the cursor keys.

- Part B focuses on assembly language programming for the Cortex M4 processor by implementing two subroutines to calculate the square root of a positive integer. One subroutine utilizes the Floating-Point Unit (FPU), while the other does not. These subroutines are integrated into the Part A code, and performance comparisons determine the faster method.

- Part C introduces the implementation of peripheral access using the Kinetis Software Development Kit (KSDK). This part involves reading values from the analog-to-digital converter (ADC) inputs connected to Pot 1 and Pot 2 on the Application Shield. These values are transmitted to a PC via the serial port for display in a terminal program. Pot 1's value is sampled at a user-defined rate, while Pot 2's value is sampled upon pressing the joystick up. This part emphasizes the use of Freescale libraries for efficient peripheral access and communication in embedded systems development.

This assignment was part of the ELEC422 course, "Microprocessor Systems" , in the Department of Electrical Engineering and Electronics at the University of Liverpool.
