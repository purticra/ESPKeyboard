# ESP32 Media Control Module

A compact, wireless media controller built with an ESP32 and BLE HID keyboard emulation. Designed and built as part of Georgia Tech's ECE 1100 Discovery Project.

![Media Control Module](rendered_images/rendered_photo.png)

## Features

- **Bluetooth Low Energy** — pairs wirelessly with any BLE-capable host machine
- **Three media controls** — play/pause, next track, previous track
- **Pocket-sized** — 70 × 40 × 45 mm, fits comfortably in one hand
- **No drivers needed** — appears as a standard HID keyboard

## Hardware

| Component | Details |
|-----------|---------|
| Microcontroller | ESP32 (Micro-USB) |
| Buttons | 3× momentary push buttons (GPIO 13, 12, 14) |
| Enclosure | 3D-printed (see `CAD/`) |
| Power | USB 5V via Micro-USB |

## Wiring

Each button connects between its GPIO pin and GND. The ESP32's internal pull-up resistors handle the logic — no external resistors required.

| Button | GPIO |
|--------|------|
| Play/Pause | 13 |
| Next Track | 12 |
| Prev Track | 14 |

## Repository Structure

```
ESPKeyboard/
├── CAD/                  # 3D model files (enclosure only)
├── firmware/             # ESP32 Arduino source code
├── rendered_images/      # Rendered images of the device
├── LICENSE
└── README.md
```

> **Note:** The tactile button and ESP32 development board 3D models are sourced from [GrabCAD](https://grabcad.com/) and are not included in this repository due to their licensing terms (CC BY-NC). Only the original enclosure design is included in `CAD/`.

## Getting Started

### Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software) or [PlatformIO](https://platformio.org/)
- [ESP32-BLE-Keyboard](https://github.com/T-vK/ESP32-BLE-Keyboard) library

### Upload

1. Clone this repository
2. Open the firmware sketch in Arduino IDE or PlatformIO
3. Install the `ESP32-BLE-Keyboard` library
4. Select your ESP32 board and port
5. Upload

## License

This project is open-sourced under the [MIT License](LICENSE).