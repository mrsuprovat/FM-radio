Advanced FM Radio with Arduino Nano

Overview

This project is an Advanced FM Radio built using Arduino Nano, TEA5767 FM module, LCD1602 (I2C), and 4 TTP223 touch switches. It allows you to manually tune frequencies or switch between preset Indian FM stations.

Features

Manual Frequency Control (Up/Down) using touch switches.

Preset Stations for quick access to common FM channels.

LCD Display shows the current frequency and preset station name.

TEA5767 FM Module ensures clear radio reception.

Components Required

Arduino Nano

TEA5767 FM Radio Module

LCD1602 (I2C)

4 x TTP223 Touch Switches

Jumper Wires

Breadboard (Optional)

Pin Configuration

Component


Frequency Tuning:

Touch D3 → Increase frequency by 0.05 MHz.

Touch D2 → Decrease frequency by 0.05 MHz.

Preset Stations:

Touch D5 → Move to the next preset station.

Touch D4 → Move to the previous preset station.

The LCD updates automatically with the current frequency and preset station name.

Installation & Setup

Install Arduino IDE (if not installed).

Install the required libraries in Arduino IDE:

Arduino Library Manager → Search & Install:
- TEA5767Radio
- LiquidCrystal_I2C

Upload the Code

Connect Arduino Nano to PC.

Select Board: Arduino Nano.

Select Port.

Upload the provided sketch.

Circuit Diagram

(To be added: Circuit diagram for reference)

License

This project is open-source under the MIT License. Feel free to modify and improve it!

Author

Suprovat KararData Entry Operator | Accountant | Electronics EnthusiastGitHub
