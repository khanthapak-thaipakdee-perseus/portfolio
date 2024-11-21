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
     
### 2. [Real-time operating system implementation on FRDM-K64F](https://github.com/khanthapak-thaipakdee-perseus/Microprocessor-Systems-Real-Time-Operating-System-Implementation-on-FRDM-K64F)
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
