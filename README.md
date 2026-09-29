# Vehicle Detection Parking System

Automatic parking gate using an IR sensor, a servo motor, a buzzer and an RGB LED. When a vehicle is detected, the gate opens, then closes again after a few seconds.

## How it works

1. When no vehicle is present, the gate is closed (servo at 0°) and the LED is **red**.
2. When the IR sensor detects a vehicle:
   - the buzzer beeps and the gate opens (servo at 90°),
   - the LED turns **green** for 2 seconds,
   - the LED shows the closing signal for 1 second,
   - the gate closes and the LED turns **red** again.

> Note: only the red and green LED pins are connected in the code, so the blue "closing" colour is not shown. Add a blue pin (e.g. pin 6) and an `analogWrite` for it in `setColor()` if you want it.

## Components

- Arduino Uno (or compatible)
- IR obstacle sensor
- Servo motor (SG90 or similar)
- Buzzer
- RGB LED + resistors (220 Ω)
- Jumper wires, breadboard

## Wiring

| Part | Pin | Arduino pin |
|---|---|---|
| IR sensor | OUT | 2 |
| Servo | Signal | 9 |
| Buzzer | + | 8 |
| RGB LED | Red | 3 |
| RGB LED | Green | 5 |
| IR sensor / Servo | VCC / GND | 5V / GND |

## Libraries

- Servo (built into the Arduino IDE)

## How to run

1. Open `Vehicle_Detection_Parking_System.ino` in the Arduino IDE.
2. Select your board and port.
3. Upload, then place an object in front of the IR sensor to open the gate.
