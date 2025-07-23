# RFID-ATTENDENCE-PROTOTYPE

# Obstacle Avoiding Robot using Arduino 🚗🤖

This project is an **Obstacle Avoiding Robot** built using an **Arduino Uno**, an **HC-SR04 ultrasonic sensor**, **L298N motor driver (or equivalent H-bridge wiring)**, and a **servo motor**. The robot uses distance sensing to detect nearby obstacles and navigates around them.

## 🔧 Components Used

- Arduino Uno
- HC-SR04 Ultrasonic Distance Sensor
- L298N Motor Driver or equivalent (using 4 motor control pins)
- Servo Motor (SG90 or similar)
- 2 DC Motors + Wheels
- Chassis (2WD)
- Jumper Wires
- Power Supply (Battery Pack)
- Breadboard (optional)

## 🧠 Features

- Obstacle detection using ultrasonic sensor
- Forward motion with smooth acceleration and deceleration
- Obstacle scanning with servo-mounted ultrasonic sensor
- Intelligent reversing and left turn when obstacle is detected
- PWM-based speed control
- Serial Monitor output of distance data

## 📁 Arduino Code Overview

### Pin Definitions:

```cpp
#define trigPin 9     // Ultrasonic Trigger Pin
#define echoPin 8     // Ultrasonic Echo Pin
#define MLa 4         // Left Motor A
#define MLb 5         // Left Motor B
#define MRa 6         // Right Motor A
#define MRb 7         // Right Motor B
#define PWMPin 10     // Motor speed control via PWM
Core Logic:
If distance > 15 cm → Move forward with speed ramp-up and ramp-down

If obstacle < 10 cm:

Stop

Sweep servo to check for path

Move back slowly

Turn left slightly

📷 Demo
(Include GIF or YouTube link of robot in action if available)

🔌 Circuit Diagram
(Upload and link a Fritzing or image file of your wiring setup here)

⌨️ How to Run
Upload the Arduino sketch to your board.

Connect components as per the pin configuration.

Power the motors using an external power supply.

Place the robot in an open area and observe how it avoids obstacles.

📦 Future Improvements
Add autonomous decision-making (left vs right scan)

Use IR or additional ultrasonic sensors for 360° awareness

Incorporate Bluetooth/WiFi control for manual override

Add OLED/LCD display for real-time status

📜 License
MIT License

Made with ❤️ by [Your Name]

yaml
Copy
Edit

---

You can customize the `README.md` by:
- Replacing *[Your Name]* with your GitHub name.
- Adding links to demo videos or circuit diagrams if available.
Let me know if you'd like a Fritzing circuit or image for wiring too!







You said:
SAME WITH RFID ESP PROJECT


ChatGPT said:
Here’s a README.md file for your RFID + ESP8266 Access System Project that prints "Windows access granted" when a card is scanned:

markdown
Copy
Edit
# RFID Access Control System using ESP8266 🔐📶

This project is a simple RFID-based access system using an **ESP8266 (NodeMCU)** and **RFID-RC522 module**. It reads RFID cards and grants access by printing **"Windows access granted"** to the Serial Monitor when a valid card is scanned.

## 🔧 Components Used

- ESP8266 NodeMCU (or any ESP board)
- MFRC522 RFID Module
- RFID Tag or Card (UID: `B3 68 9F A7`)
- Jumper Wires
- Breadboard (optional)
- Micro USB Cable

## 🧠 Features

- Detects RFID card scan
- Checks UID for authorized access
- Prints `"Windows access granted"` for valid UID
- Can be expanded to control relays, buzzers, doors, etc.

## 📁 Arduino Code Overview

### Libraries Used

```cpp
#include <SPI.h>
#include <MFRC522.h>
Pin Configuration
cpp
Copy
Edit
#define SS_PIN D4     // SDA pin of RC522
#define RST_PIN D3    // RST pin of RC522
UID Validation
cpp
Copy
Edit
byte validUID[4] = { 0xB3, 0x68, 0x9F, 0xA7 };
Output on Serial Monitor
If the scanned UID matches the one above, the output is:

makefile
Copy
Edit
Card detected
UID: B3 68 9F A7
Windows access granted
Otherwise:

makefile
Copy
Edit
Card detected
UID: XX XX XX XX
Access denied
🔌 Wiring Diagram
RFID Module	ESP8266 (NodeMCU)
SDA	D4 (GPIO2)
SCK	D5 (GPIO14)
MOSI	D7 (GPIO13)
MISO	D6 (GPIO12)
RST	D3 (GPIO0)
GND	GND
3.3V	3.3V

⚠️ Do not connect the RFID module to 5V; it requires 3.3V.

⌨️ How to Run
Install MFRC522 library from Arduino Library Manager.

Upload the code to the ESP8266 board.

Open the Serial Monitor at 9600 baud.

Scan your RFID card or tag.

If it matches the predefined UID, access is granted.

🚀 Possible Upgrades
Add relay control to open a door or lock

Connect to Firebase or Thingspeak for logging

Display UID or messages on an OLED screen

Integrate with a web dashboard using ESP WiFi

📜 License
MIT License

Made with ❤️ by [Your Name]
