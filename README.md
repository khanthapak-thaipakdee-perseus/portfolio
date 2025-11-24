# Portfolio of Khanthapak Thaipakdee

Welcome to the GitHub portfolio of **Khanthapak Thaipakdee**, showcasing academic work and projects. This portfolio is listed in **reverse chronological order**.

---

## Projects

### 1. [MSc Research Project: Laser-Induced Graphene-Based Wearable Sensors for Health Monitoring](https://github.com/khanthapak-thaipakdee-perseus/MSc-Project-Laser-induced-graphene-based-wearable-sensors-for-health-monitoring)
   - **Description**: The MSc project will focus on optimizing parameters for LIG-based sensor fabrication, including laser power, scanning speeds, and sensor patterns, to produce LIG on various composite substrates such as PI, protection tape, and medical tape. Additionally, the project aims to develop the capability of the strain sensor to detect physiological signals such as arterial pulse and human motion.
   - **Date**: Jun 2024 – Sep 2024
   - **Tech Stack**: MATLAB, FlexLogger
   - **Objectives**:
     - Objective 1: Determining the ideal parameters for producing LIG from PI involves optimizing laser power, scanning speed, and sensor patterns.
     - Objective 2: Identifying the optimal substrate for the LIG sensor involves evaluating various materials such as PI film, polyurethane (PU) tape, protection tape, bandage, and polyethylene (PE) nonwoven tape. The goal is to select a substrate that exhibits mechanical and electrical properties suitable for biomedical sensing applications.
     - Objective 3: Developing the capability for the strain sensor to detect physiological signals such as arterial pulse and human motion (finger bending, hand gripping, elbow bending) is the primary goal. If feasible, the sensor will also be designed to study other signals, including electrocardiography (ECG).
   - **Report**: [Download Report](https://github.com/khanthapak-thaipakdee-perseus/MSc-Project-Laser-induced-graphene-based-wearable-sensors-for-health-monitoring/blob/main/MScProject_Final_Report.pdf)
  
  ---
     
### 2. [Design and Simulation of Single-Stage and Two-Stage Amplifiers in 1.2 μm CMOS Technology](https://github.com/khanthapak-thaipakdee-perseus/CMOS/tree/main/Single-Stage-and-Two-Stage-Amplifiers)
   - **Description**: Design a single-stage operational amplifier (op-amp) using 1.2 μm CMOS technology, calculating the aspect ratios of all transistors to satisfy specified input and output conditions. Simulate the design using MultiSim and verify key performance metrics, including slew rate, rise/fall time response, gain, gain-bandwidth product, and phase margin. Additionally, design and simulate a two-stage op-amp incorporating a common-source stage and a compensation capacitor. Finally, investigate amplifier circuits with closed-loop gain, analyzing both inverting and non-inverting configurations through parameter sweeps.
   - **Date**: Mar 2024 – May 2024
   - **Tech Stack**: MultiSim
   - **Features**:
     - Feature 1: Design and simulate a single-stage op-amp, verifying key performance metrics such as slew rate, rise/fall time response, gain, gain-bandwidth product, and phase margin.
     - Feature 2: Design and simulate a two-stage op-amp incorporating a common-source stage and a compensation capacitor.
     - Feature 3: Investigate amplifier circuits with closed-loop gain by analyzing both inverting and non-inverting configurations through parameter sweeps.
   - **Report**: [Download Report](https://github.com/khanthapak-thaipakdee-perseus/CMOS/blob/main/Single-Stage-and-Two-Stage-Amplifiers/Single-Stage-and-Two-Stage-Amplifiers-Report.pdf)

  ---
     
### 3. [Real-time operating system implementation on FRDM-K64F](https://github.com/khanthapak-thaipakdee-perseus/Microprocessor-Systems-Real-Time-Operating-System-Implementation-on-FRDM-K64F)
   - **Description**: The project involves designing and developing a subsystem with a focus on text displaying, LED controlling, and ADC (Analog-to-Digital Conversion) functionalities. The subsystem features seven threads and two ISRs for managing PC-K64F communication, switch inputs, RGB LED control, and ADC readings. Threads handle communication, switch monitoring, and LED states using mailboxes and flags.
   - **Date**: Mar 2024 – May 2024
   - **Tech Stack**: Keil µVision
   - **Features**:
     - Feature 1: Feature 1 establishes four threads and integrates two ISRs. Thread 1 manages PC-K64F communication via a Virtual Communications Port, handling keyboard input, echoing messages, and decoding signals. Thread 2 handles K64F-PC communication using a Zero Copy Mailbox and displays echoed messages. ISRs linked with Thread 3 and Thread 4 monitor switch inputs (SW2 and SW3), signaling Thread 2 through the Mailbox.
     - Feature 2: Feature 2 adds Thread 5 to control the RGB LEDs based on commands from Thread 1. The LED states toggle according to user input, utilizing flag-based inter-thread communication.
     - Feature 3: Feature 3 introduces Thread 6 for periodic ADC readings from Pot 1 and Thread 7 for on-demand ADC readings from Pot 2. Thread 1 coordinates the sampling rate of Thread 6 and requests readings from Thread 7. Inter-thread communication is facilitated using flags and message passing.
   - **Repository**: [View Code](https://github.com/khanthapak-thaipakdee-perseus/Microprocessor-Systems-Real-Time-Operating-System-Implementation-on-FRDM-K64F/tree/main/code)
   - **Report**: [Download Report](https://github.com/khanthapak-thaipakdee-perseus/Microprocessor-Systems-Real-Time-Operating-System-Implementation-on-FRDM-K64F/blob/main/Microprocessor-Systems-Assignment-3-Report.pdf)
   - **Screenshots**:
     ![Screenshot](assets/images/project-screenshot.png)

  ---
     
### 4. [Design and Simulation of CMOS Inverters and NAND Gates: DC, Transient Response, and Power Dissipation](https://github.com/khanthapak-thaipakdee-perseus/CMOS/tree/main/CMOS-Inverters-and-NAND-Gates)
   - **Description**: This assignment relates to the simulation, verification, and analysis of CMOS gate performance, with a focus on speed and power efficiency. It includes the design and comprehensive analysis of the DC and transient responses of a CMOS inverter, the evaluation of power dissipation in a loaded CMOS inverter, and the design and analysis of the DC and transient responses of a 2-input NAND gate.
   - **Date**: Feb 2024 – Mar 2024
   - **Tech Stack**: MultiSim
   - **Report**: [Download Report](https://github.com/khanthapak-thaipakdee-perseus/CMOS/blob/main/CMOS-Inverters-and-NAND-Gates/CMOS-Inverters-and-NAND-Gates-Report.pdf)
  
  ---
  
### 5. [MIPS Processor Design and Implementation](https://github.com/khanthapak-thaipakdee-perseus/Digital-System-Design-MIPS-Processor)
   - **Description**: This project involves designing a MIPS processor module and implementing digital systems using Verilog HDL, divided into three parts. Part A focuses on modifying a MIPS assembly language program to display the last 8 digits of the student’s university ID on the 7-segment displays of the DE2 board. This is demonstrated with SignalTap Logic Analyzer screenshots showing the instruction and program counter. Part B extends the MIPS processor by implementing additional instructions: XOR, XORI, and LBU. Part C includes designing a Pulse Width Modulation (PWM) unit to drive an LED. The PWM is controlled by the MIPS processor via a register and adjusts the LED brightness based on the comparison between a counter and a register value. The LEDR5 is reassigned to the PWM unit, distinct from the existing GPIO, for precise control.
   - **Date**: Feb 2024 – Mar 2024
   - **Tech Stack**: Altera Quartus II
   - **Parts**:
     - Part 1: Write a MIPS assembly language program to display the last 8 digits of the student’s university ID on the 7-segment displays of the DE2 board.
     - Part 2: Extend the MIPS processor by implementing additional instructions: XOR, XORI, and LBU.
     - Part 3: Include a PWM unit to drive an LED.
   - **Repository**: [View Code-PartA](https://github.com/khanthapak-thaipakdee-perseus/Digital-System-Design-MIPS-Processor/tree/main/MIPS_System_Students_Part_A)   [View Code-PartB](https://github.com/khanthapak-thaipakdee-perseus/Digital-System-Design-MIPS-Processor/tree/main/MIPS_System_Students_Part_B)   [View Code-PartC](https://github.com/khanthapak-thaipakdee-perseus/Digital-System-Design-MIPS-Processor/tree/main/MIPS_System_Students_Part_C_loop)
   - **Report**: [Download Report](https://github.com/khanthapak-thaipakdee-perseus/Digital-System-Design-MIPS-Processor/blob/main/MIPS-Processor-Report.pdf)

  ---
  
### 6. [Microprocessor Programming with MBED and Kinetis SDK on FRDM-K64F](https://github.com/khanthapak-thaipakdee-perseus/Microprocessor-Systems-Microprocessor-Programming-with-MBED-and-Kinetis-SDK-on-FRDM-K64F)
   - **Description**: This project enhances embedded systems programming on the FRDM-K64F using MBED. It involves displaying the user’s name and ID on an LCD, implementing square root subroutines with and without the FPU, and using KSDK to read ADC values from Pot 1 and Pot 2, transmitting data to a PC via serial communication.
   - **Date**: Feb 2024 – Mar 2024
   - **Tech Stack**: Keil µVision
   - **Parts**:
     - Part 1: Write a program that interacts with the Application Shield to display the user's name and ID on an LCD screen. The program also allows incrementing or decrementing a displayed number using cursor keys.
     - Part 2: Develope assembly language programming for the Cortex M4 processor by implementing two subroutines to calculate the square root of a positive integer. One subroutine utilizes the Floating-Point Unit (FPU), while the other does not.
     - Part 3:Focus on reading values from the analog-to-digital converter (ADC) inputs connected to Pot 1 and Pot 2 on the Application Shield. These values are then transmitted to a PC via the serial port for display in a terminal program. Pot 1's value is sampled at a user-defined rate, while Pot 2's value is sampled when the joystick up button is pressed. This approach emphasizes the use of Freescale libraries to ensure efficient peripheral access and communication in embedded systems development.
   - **Repository**: [View Code-PartA&B](https://github.com/khanthapak-thaipakdee-perseus/Microprocessor-Systems-Microprocessor-Programming-with-MBED-and-Kinetis-SDK-on-FRDM-K64F/tree/main/microprocessor-systems-1-part-a-b)   [View Code-PartC](https://github.com/khanthapak-thaipakdee-perseus/Microprocessor-Systems-Microprocessor-Programming-with-MBED-and-Kinetis-SDK-on-FRDM-K64F/tree/main/microprocessor-systems-1-part-c)
   - **Report**: [Download Report](https://github.com/khanthapak-thaipakdee-perseus/Microprocessor-Systems-Microprocessor-Programming-with-MBED-and-Kinetis-SDK-on-FRDM-K64F/blob/main/Microprocessor-Systems-Assignment-1-Report.pdf)
   - **Screenshots**:
     ![Screenshot](assets/images/project-screenshot.png)
     
  ---
  
### 7. [Design and Implementation of Serial Communications Using Verilog](https://github.com/khanthapak-thaipakdee-perseus/Digital-System-Design-Verilog-Serial-Communications)
   - **Description**: This project focuses on designing UART and IR communication systems in Verilog on the DE2 board, utilizing the RS232 interface. UART, a crucial component in serial communication, is implemented using Verilog to manage tasks such as data transmission, reception, and precise timing. Key components like counters, shift registers, baud rate generators, RX-TX controllers, and a 7-segment display are employed to ensure seamless data transfer between the DE2 board and external devices, with the 7-segment display used for both sending and receiving parts to verify the accuracy of the results. Additionally, IR communication is integrated using the HSDL-3201 module for wireless transmission, enhancing the system's versatility. The project also includes parity check and framing error detection, which are displayed using LEDs on the DE2 board, ensuring robust error handling and communication reliability. The system is tested and validated using terminal software like "Putty" to display transmitted ASCII values.
   - **Date**: Dec 2023 - Feb 2024
   - **Tech Stack**: Altera Quartus II
   - **Repository**: [View Code](https://github.com/khanthapak-thaipakdee-perseus/Digital-System-Design-Verilog-Serial-Communications/tree/main/code)
   - **Report**: [Download Report](https://github.com/khanthapak-thaipakdee-perseus/Digital-System-Design-Verilog-Serial-Communications/blob/main/Digital-Systems-Design-Verilog-Serial-Communications-Report.pdf)
   - **Screenshots**:
     ![Screenshot](assets/images/project-screenshot.png)

  ---
  
### 8. [Design-and-Implementation-of-LoRaWAN-Based-IOT-Application](https://github.com/khanthapak-thaipakdee-perseus/IOT-2-Design-and-Implementation-of-LoRaWAN-Based-IOT-Application)
   - **Description**: In this assignment, an IoT solution will be crafted using the IoT kit with Raspberry Pi OS. The emphasis lies in employing the LoRa physical layer protocol for long-distance communication, alongside the LoRaWAN protocol executed by TTN. The chosen activation method is ABP, ensuring a secure activation process. Messages will be formatted using Cayenne LPP for efficient sensor data encapsulation. This IoT solution will seamlessly transmit temperature and humidity values from the DHT11 sensor module, along with a specific numerical output, over the LoRaWAN network.
   - **Date**: Nov 2023 - Dec 2023
   - **Tech Stack**: MobaXTerm
   - **Repository**: [View Code](https://github.com/khanthapak-thaipakdee-perseus/IOT-2-Design-and-Implementation-of-LoRaWAN-Based-IOT-Application/blob/main/IOT_Prototype_tx_rx_assignment2.py)
   - **Report**: [Download Report](https://github.com/khanthapak-thaipakdee-perseus/IOT-2-Design-and-Implementation-of-LoRaWAN-Based-IOT-Application/blob/main/IOT_2_IOT_Prototype_Report.pdf)
   - **Screenshots**:
     ![Screenshot](assets/images/project-screenshot.png)

---
  
### 9. [MATLAB Graphic User Interface (GUI) of electrical data](https://github.com/khanthapak-thaipakdee-perseus/MATLAB-GUI)
   - **Description**: In this assignment, it is imperative to develop a MATLAB GUI program designed to extract coordinate values from a text file and perform the necessary processing.
   - **Date**: Oct 2023 - Dec 2023
   - **Tech Stack**: MATLAB
   - **Features**:
     - Feature 1: Prompt the user to specify the file name from which the data will be retrieved.
     - Feature 2: Graphically represent two time-resolved electrical signals, namely the high voltage signal "Uapp" extracted from the "Uapp.txt" file and the charge "Q," extracted from the "Uc.txt" with the x-axis and y-axis.
     - Feature 3: Calculate various parameters for both signals, including peak-to-peak amplitude, root mean square (RMS) value, frequency, minimum value, and maximum value.
     - Feature 4: Illustrate the Lissajous figure (Q-U) and apply a smoothing operation.
     - Feature 5: Compute and present the discharge power.
   - **Repository**: [View Code]()
   - **Report**: [Download Report]()
   - **Screenshots**:
     ![Screenshot](assets/images/project-screenshot.png)

---
  
### 10. [System Event-Driven PID Control for DC Servo Drive & Model Reference Adaptive Control in a DC Electrical Drive](https://github.com/khanthapak-thaipakdee-perseus/Control-Systems-Event-Driven-PID-Control)
   - **Description**: This project involves designing MATLAB+SIMULINK programs. Part A focuses on simulating a robotic system for picking and dropping chocolate boxes, including PID tuning, random event handling, and continuous PID control. Part B uses MATLAB+SIMULINK to verify the controller, adjust the adaptation gain (𝛾), and compare Lyapunov and MIT MRAC models to assess their advantages and disadvantages.
   - **Date**: Oct 2023 - Dec 2023
   - **Tech Stack**: MATLAB, Simulink
   - **Repository**: [View Code](https://github.com/khanthapak-thaipakdee-perseus/Control-Systems-Event-Driven-PID-Control/blob/main/Control-Systems-Part-1/Assignment_1_full_system.slx)
   - **Report**: [Download Report](https://github.com/khanthapak-thaipakdee-perseus/Control-Systems-Event-Driven-PID-Control/blob/main/PID-DC-Servo-Control-%26-MRAC-Simulink-Report.pdf)
   - **Screenshots**:
     ![Screenshot](assets/images/project-screenshot.png)

---
  
### 11. [Design and Develop Shell Script to Receive Temperature and Humidity Using MQTT Protocol](https://github.com/khanthapak-thaipakdee-perseus/IOT-1-Design-and-Develop-Shell-Script-to-Receive-Temperature-and-Humidity-Using-MQTT-Protocol)
   - **Description**: In this assignment, an IoT solution based on M2M communications was designed and developed using the MQTT protocol. This solution enables an MQTT subscriber to independently acquire information from an MQTT publisher via an MQTT broker. The message comprised temperature and humidity values from the DHT11 sensor module. A shell script was created using shell commands to ensure that the program completed all tasks in the assignment and to prevent users from executing the program with invalid inputs.
   - **Date**: Oct 2023 - Nov 2023
   - **Tech Stack**: MobaXTerm
   - **Repository**: [View Code](https://github.com/khanthapak-thaipakdee-perseus/IOT-1-Design-and-Develop-Shell-Script-to-Receive-Temperature-and-Humidity-Using-MQTT-Protocol/blob/main/launcher.sh)
   - **Report**: [Download Report]()
   - **Screenshots**:
     ![Screenshot](assets/images/project-screenshot.png)

---
  
### 12. [BEng Research Project: Design and Development of Application for managing diabetes : mobile and web applications]()
   - **Description**: My thesis project is developing software for tracking diabetes patients by collecting data and encouraging them to improve their lifestyle. This project is divided into 2 parts; mobile application for patients and web application for medical staff which data is linked by database. Mobile application was designed by systemic data structure and proper software engineering tools for cross-platform application. Mobile application has 5 features which are 1 input process and 4 output processes. One of the features that added on the input process is image classification section that satisfy user to classify cuisine name.
   - **Date**: Sep 2020 - May 2021
   - **Tech Stack**: Python
   - **Repository**: [View Code]()
   - **Report**: [Download Report]()
   - **Screenshots**:
     ![Screenshot](assets/images/project-screenshot.png)

---
  
### 13. [PID Simulink: Design Simulation]()
   - **Description**: Designed lag-lead compensated systems and analogue circuits by Root-Locus method and the frequency response approach and applying Ziegler-Nichols rules for PID controller tuning.
   - **Date**: Mar 2020 - May 2020
   - **Tech Stack**: MATLAB
   - **Repository**: [View Code]()
   - **Report**: [Download Report]()

---
  
### 14. [Non-Invasive Blood Pressure Monitoring Device with Mobile Application]()
   - **Description**: Developed non-invasive blood pressure monitoring device which consists of pump, valves, sensors and electronic components. 
      - Designed and developed controller part which is RTOS system using ESP32.
      - Launched its mobile application which can received blood pressures through Bluetooth and had its clouding system to store data.
   - **Date**: Sep 2019 - Nov 2019
   - **Tech Stack**: Arduino IDE
   - **Repository**: [View Code]()
   - **Report**: [Download Report]()

---
  
### 15. [Electrocardiogram(ECG) and Phonocardiogram(PCG) Monitoring Device]()
   - **Description**: Developed ECG and PCG Monitoring Device. 
      - Designed analogue circuits with TL064 operational amplifiers.
      - Drew and designed a PCB Schematic.
     - Displayed signals on an oscilloscope and a computer using MATLAB interface.
   - **Date**: Feb 2019 - Apr 2019
   - **Tech Stack**: Proteus, MATLAB
   - **Repository**: [View Code]()
   - **Report**: [Download Report]()
