# ThermoSpinny
An IoT-enabled mechanical device to control and automate an old convection heater.

## Vision
A device that can:
  - Mechanically control the heater's knob, in a reproductible way
  - Turn on/off (and emergency kill) heater power, in case externally wired to mains electricity
  - Allow for a clean user input without having to physically override the heater
  - Provide clear information regarding system state
  - [Optional] Read ambient temperature to enable a digital thermostat, ideally closer to the user's location, rather than close to the heater
  - [Optional] Read man window state (closed/open) to prevent heating the earth
  - [Optional] Read ambient temperature (or import via API) to suggest ambient heating (free)
  - Connect to the any of
    - Intranet to enable mobile app control, OR
    - Internet to enable web app, OR
    - IoT hub (Home Assistant, Alexa, etc)
  - [Optional] Remotely alert user via push, SMS, email, etc. about dangerous/wasteful states 

## Considerations
My recommendation will **always** be to integrate the device via the free and open-source [Home Assistant](home-assistant.io), potentially leveraging the super easy, open source, quasi-code-free [ESPHome](esphome.io) development system.
However, as an MVP, I recommend a ready-to-use interface like [Adafruit IO](https://io.adafruit.com), which frees the user from any aditional hardware like a Raspberry Pi, or a relatvely invasive Amazon Alexa.

## Bill of Materials
- Microcontroller
  - ESP8266 or ESP32: recommended, as they already integrate WiFi controllers and USB-to-serial converters. Wemos D1 clones are dirt cheap ($5 USD per unit would be considered expensive). Adafruit [Feather Boards](https://www.adafruit.com/category/946) are a nicer, but more expensive alternative.
  - Arduino/Teensy: the gold standard, but traditionally lack WiFi connectivity 
  - Raspberry Pi: huge overkill (it's a whole computer), but great option if already owned. Hard to come by after the Covid component shortage
- Servo: low torque - likely a cheapo Arduino starter kit type is enough. It should be able to rotate as much as the heater's knob does (or at least a useful amount, if the max isn't usually set). I'd suggest direct drive (avoid any gearing or transmission) to avoid complexity. If impossible, I suggest a GT2 belt and pulley system (or similar), or a 3D-printed gear pair.
- Relay: anything rated comfortably below the load (likely 120V 15A). Ideally in an opto-isolated breakout board ready for 3.3 or 5V logic (whatever the board uses)
- Ambient sensor: DHT11/DHT12 are a bit of a piece of junk, so I recommend any other decent replacement (see [Modern Replacements for DHT11 and DHT22 Sensors](https://learn.adafruit.com/modern-replacements-for-dht11-dht22-sensors))
- 
  
  , in my opinion, a much nicer, well documented alternative that also supports a company with 
