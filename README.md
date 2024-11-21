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
   - **Report**: [Download Report]([https://github.com/khanthapak-thaipakdee-perseus/Microprocessor-Systems-Real-Time-Operating-System-Implementation-on-FRDM-K64F/blob/main/Microprocessor-Systems-Assignment-3-Report.pdf](https://github.com/khanthapak-thaipakdee-perseus/CMOS/blob/main/Single-Stage-and-Two-Stage-Amplifiers/Single-Stage-and-Two-Stage-Amplifiers-Report.pdf))

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
   - **Repository**: [View Code-PartA](https://github.com/khanthapak-thaipakdee-perseus/Digital-System-Design-MIPS-Processor/tree/main/MIPS_System_Students_Part_A)
   - [View Code-PartB](https://github.com/khanthapak-thaipakdee-perseus/Digital-System-Design-MIPS-Processor/tree/main/MIPS_System_Students_Part_B)
   - [View Code-PartC](https://github.com/khanthapak-thaipakdee-perseus/Digital-System-Design-MIPS-Processor/tree/main/MIPS_System_Students_Part_C_loop)
   - **Report**: [Download Report]([https://github.com/khanthapak-thaipakdee-perseus/Microprocessor-Systems-Real-Time-Operating-System-Implementation-on-FRDM-K64F/blob/main/Microprocessor-Systems-Assignment-3-Report.pdf](https://github.com/khanthapak-thaipakdee-perseus/Digital-System-Design-MIPS-Processor/blob/main/MIPS-Processor-Report.pdf)

