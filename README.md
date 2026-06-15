# arduino-radar-missile-launcher
Automatic Radar Missile Launcher using Arduino Uno, HC-SR04 ultrasonic sensor, and SG90 servo motors



# Automatic Radar Missile Launcher

An Arduino-based automated targeting system that detects objects using ultrasonic radar and launches projectiles.

## Features
- 180° continuous radar scanning
- Real-time distance measurement (2cm-400cm)
- Automatic target detection at 30cm threshold
- LED and buzzer alerts on target lock
- Servo-actuated rubber band launcher

## Components
| Component | Model |
|-----------|-------|
| Microcontroller | Arduino Uno |
| Distance Sensor | HC-SR04 |
| Servo Motors (2x) | SG90 |
| Buzzer | 5V Active |
| LED | 5mm with 220Ω resistor |

## Circuit Connections
| HC-SR04 | Arduino |
|---------|---------|
| VCC | 5V |
| GND | GND |
| TRIG | Pin 9 |
| ECHO | Pin 10 |

| Servo | Arduino |
|-------|---------|
| Pan Servo Signal | Pin 6 |
| Fire Servo Signal | Pin 5 |
| VCC (both) | 5V |
| GND (both) | GND |

| Other | Arduino |
|-------|---------|
| LED (+) | Pin 3 (via 220Ω) |
| Buzzer (+) | Pin 2 |

## How It Works
1. Pan servo rotates sensor from 0° to 180°
2. HC-SR04 measures distance at each angle
3. If object <30cm detected → target locked
4. LED flashes, buzzer sounds
5. Fire servo rotates 90°→0° to launch projectile
6. System resets and continues scanning

## Installation
1. Install [Arduino IDE](https://www.arduino.cc/en/software)
2. Clone this repository
3. Open `code/radar_missile_launcher.ino`
4. Select Board: Arduino Uno
5. Select correct COM port
6. Upload code

## Test Results
| Test | Status |
|------|--------|
| Distance Measurement | ✓ Pass |
| Pan Servo Rotation | ✓ Pass |
| Fire Servo Movement | ✓ Pass |
| Target Detection & Firing | ✓ Pass |
| Power Stability | ✓ Pass |

## Future Improvements
- Camera module (OV7670/ESP32-CAM) for visual identification
- ESP8266 Wi-Fi for IoT remote monitoring
- Precision IR/LIDAR sensor for faster detection
- HC-05 Bluetooth for manual mobile control

## Contributors
- Ritik Madhuman - Physical construction
- Bijay Kumar Yadav - Circuit wiring
- Nitisha Nepal - Code development
- Luniva Paneru - Testing & calibration
- Shreya Lama - Documentation

## License
Educational use only

## Acknowledgments
Supervisor: Mr. Jagannath Paudyal
