# RFID-Based Gate Access Control System

This project implements an RFID-based gate access control system using an Arduino. The system utilizes an RFID reader (MFRC522) to identify authorized users, a servo motor to control the gate, and LEDs to indicate system status. The main objective is to ensure secure access to a restricted area by verifying the RFID tag of users.

## Components Used

- **Arduino**: Controls the entire system.
- **MFRC522 RFID Reader**: Reads RFID tags and sends the unique ID to the Arduino.
- **Servo Motor**: Opens and closes the gate based on RFID verification.
- **Red LED**: Signals when the gate is closed or an invalid RFID is detected.
- **Green LED**: Signals when the gate is open and valid access is granted.

## Features

1. **RFID Verification**: The system reads RFID tags and compares them to a predefined authorized tag.
2. **Gate Control**: The gate opens when an authorized tag is detected and automatically closes after a delay.
3. **LED Indicators**:
   - **Red LED**: On when the gate is closed or when access is denied.
   - **Green LED**: On when the gate is open (valid RFID).
4. **Invalid Access Feedback**: The red LED flashes three times when an unauthorized RFID tag is scanned.

## How It Works

1. The system waits for a new RFID card to be presented.
2. Once a card is detected, the system reads its unique ID.
3. If the RFID matches the predefined ID, the gate opens and the green LED turns on.
4. After 5 seconds, the gate closes and the red LED turns on.
5. If an invalid RFID is scanned, the red LED flashes, and the gate remains closed.

## Applications

- Secure entry systems for homes, offices, or restricted areas.
- Automated parking systems.
- Industrial access control systems.

## Circuit Diagram

- **RFID Reader**:
  - SS_PIN: Pin 10
  - RST_PIN: Pin 9
- **Servo Motor**: Pin 5
- **Red LED**: Pin 3
- **Green LED**: Pin 2

## Setup Instructions

1. Connect the components as per the circuit diagram.
2. Upload the Arduino code to the Arduino board.
3. Power the system and present an RFID tag to test access control.
