# Real-Time Operating System Implementation on FRDM-K64F
This project develops a comprehensive subsystem for the K64F microcontroller, focusing on text display, LED control, and ADC functionalities for efficient user interaction and control.

- Part A establishes four threads and integrates two ISRs. Thread 1 manages PC-K64F communication via a Virtual Communications Port, handling keyboard input, echoing messages, and decoding signals. Thread 2 handles K64F-PC communication using a Zero Copy Mailbox. ISRs linked with Thread 3 and Thread 4 monitor switch inputs (SW2 and SW3), signaling Thread 2 via the Mailbox upon status changes to enhance user feedback.

- Part B adds Thread 5 to control the RGB LEDs based on commands from Thread 1. The LED states toggle according to user input, using flag-based inter-thread communication.

- Part C introduces Thread 6 for periodic ADC readings from Pot 1 and Thread 7 for on-demand ADC readings from Pot 2. Thread 1 coordinates Thread 6's sampling rate and requests readings from Thread 7. Inter-thread communication utilizes flags and message passing.

This assignment was part of the ELEC422 course, "Microprocessor Systems" , in the Department of Electrical Engineering and Electronics at the University of Liverpool.
