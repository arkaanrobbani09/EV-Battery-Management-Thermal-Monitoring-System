# EV Battery Management & Thermal Monitoring System

[![Wokwi Simulator](https://img.shields.io/badge/Wokwi-Simulate_Online-blue?style=for-the-badge&logo=wokwi)](https://wokwi.com/projects/478860493813611521)

Embedded Electric Vehicle (EV) Battery Monitoring System (BMS) prototype built on ESP32 to monitor State of Charge (SoC) and battery temperature in real-time.

## 🚀 Live Simulation
Try the interactive circuit simulation directly in your browser:
👉 **[Open Wokwi Interactive Simulation](LINK_WOKWI_KAMU)**

## 📌 Features & Hardware Interfacing
- **SoC Monitoring:** Analog potentiometer mapping to simulate 0-100% battery capacity.
- **Thermal Safety Monitoring:** DHT22 sensor tracking temperature and detecting thermal runaway (>45°C).
- **Multi-Level Warning:** LED prompt for low battery (<20%) and 1000Hz buzzer alarm for high temperature (>45°C).
- **Dashboard Display:** 16x2 I2C LCD screen and Serial output.

## 🛠️ Circuit Setup
- **Microcontroller:** ESP32
- **Sensors:** DHT22 (Pin 15), Potentiometer (Pin 34)
- **Actuators & Displays:** 16x2 I2C LCD (0x27), Buzzer (Pin 13), LED (Pin 2)
