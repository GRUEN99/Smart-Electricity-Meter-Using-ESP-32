# Smart-Electricity-Meter-Using-ESP-32

This project is a smart electricity meter using an ESP32 microcontroller. It measures voltage, current, and power consumption, then displays this information on an LCD screen and sends it to the Blynk IoT platform for remote monitoring.


FEATURES

=>Measures and displays voltage (Vrms), current (Irms), and power (W).

=>Calculates and displays energy consumption in kWh.

=>Sends real-time data to the Blynk platform for remote monitoring.

=>Displays data on a 16x2 I2C LCD screen.

COMPONENTS

-ESP32 microcontroller

-Voltage sensor (ZMPT101B)

-Current sensor (SCT-013-030 Non-invasive AC)

-16x2 I2C LCD display

-Connecting wires

-Breadboard

-	Resistor 10K -(2)

-	Resistor 100ohm

-	Capacitor 10uF

LIBRARIES

Ensure you have the following libraries installed in your Arduino IDE:

-EmonLib: Library for energy monitoring.

-BlynkSimpleEsp32: Blynk library for ESP32.

-LiquidCrystal_I2C: Library for I2C LCD displays.

BLYNK CONFIGURATION

1.Download and install the Blynk app on your smartphone.

2.Create a new project and add the following widgets:

-Gauge for Voltage (Vrms) connected to virtual pin V0.

-Gauge for Current (Irms) connected to virtual pin V1.

-Gauge for Power (W) connected to virtual pin V2.

-Gauge for Energy (kWh) connected to virtual pin V3.

3.Copy the Blynk Authentication Token from the app and update the cod


