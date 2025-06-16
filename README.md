# ⛏️ Mine Safety Device - IoT Based Air Quality Monitoring System

This is an **IoT-based Mine Safety Device** which monitors hazardous gases, dust particles, humidity, temperature, and water pH levels in underground mining areas using multiple sensors. The data is transmitted in real-time to ThingSpeak cloud for remote monitoring and live visualization.

---

## 🔧 Components Required

- Arduino UNO
- ESP8266 Wi-Fi Module
- MQ135 Gas Sensor (Air Quality)
- DHT11 Sensor (Temperature & Humidity)
- Dust Sensor
- 16x2 LCD Display (optional)
- Buzzer & LEDs (Alert system)
- Power supply and connecting wires

---

## 🏗️ System Architecture

![System Architecture](https://raw.githubusercontent.com/devjyoti0307/MINE-SAFETY_DEVICE/main/Images%20of%20Circuit%20Digram%20and%20others/pic7.jpg)


---

## 💻 Software Requirements

- [Arduino IDE](https://www.arduino.cc/)
> Used to write and upload code to Arduino and ESP8266 modules.

- [ThingSpeak IoT Cloud](https://thingspeak.com/)
> Cloud platform for IoT data aggregation, visualization, and alert generation.

---

## 📊 Measurement Parameters

| Parameter | Sensor Used |
| ---------- | ------------ |
| Air Quality (NH3, CO2, Alcohol, Benzene) | MQ135 |
| Temperature & Humidity | DHT11 |
| Dust Level (PM) | Dust Sensor |
| Gas Concentration (Calibrated) | Custom formula for sensor voltage-to-PPM conversion |

> Mathematical calculations for gas concentration are available in detailed report documentation.

---

## 📂 Project Directory Structure

```bash
Mine-Safety-Device-Project/
│
├── Code/               # All Arduino + ESP8266 source codes
├── Report/             # Final project report (PDF)
├── Presentation/       # PPT slides for project presentation
├── Circuit_Diagram/    # Circuit diagrams and connection images
├── Video/              # Project demonstration video file (or linked)
└── README.md           # This documentation file

