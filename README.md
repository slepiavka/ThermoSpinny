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
  - [Optional] Detect user's presence to only heat when present (via LAN ping?)
  - [Very optional] Fetch a user's GPS location to turn thermostat on if approaching home.

## Considerations
My recommendation will **always** be to integrate the device via the free and open-source [Home Assistant](home-assistant.io), potentially leveraging the super easy, open source, quasi-code-free [ESPHome](esphome.io) development system.
However, as an MVP, I recommend a ready-to-use interface like [Adafruit IO](https://io.adafruit.com), which frees the user from any aditional hardware like a Raspberry Pi, or a relatvely invasive Amazon Alexa.

## Bill of Materials
- **Microcontroller**
  - ESP8266 or ESP32: recommended, as they already integrate WiFi controllers and USB-to-serial converters. Wemos D1 clones are dirt cheap ($5 USD per unit would be considered expensive). Adafruit [Feather Boards](https://www.adafruit.com/category/946) are a nicer, but more expensive alternative.
  - Arduino/Teensy: the gold standard, but traditionally lack WiFi connectivity 
  - Raspberry Pi: huge overkill (it's a whole computer), but great option if already owned. Hard to come by after the Covid component shortage
- **Servo**: low torque - likely a cheapo Arduino starter kit type is enough. It should be able to rotate as much as the heater's knob does (or at least a useful amount, if the max isn't usually set). I'd suggest direct drive (avoid any gearing or transmission) to avoid complexity. If impossible, I suggest a GT2 belt and pulley system (or similar), or a 3D-printed gear pair.
- Relay: anything rated comfortably below the load (likely 120V 15A). Ideally in an [opto-isolated](https://en.wikipedia.org/wiki/Opto-isolator) breakout board ready for 3.3 or 5V logic (whatever the board uses)
- **Ambient sensor**: DHT11/DHT12 are kind of a piece of junk, so I recommend any other decent replacement like the AM2301B (see [Modern Replacements for DHT11 and DHT22 Sensors](https://learn.adafruit.com/modern-replacements-for-dht11-dht22-sensors))
- **Window sensor**: While the easiest thing is likely another wireless sensor (Zigbee, etc.), we can start with a normal, dumb reed switch. [This one](https://www.adafruit.com/product/375), for example, is wired and ready to be slapped on the window frame. Also, being "dumb" makes it less susceptible to interference from having a long wire run all the way to the window.
- **Input** can vary. Some suggestions: 
  - A couple of [push buttons](https://duckduckgo.com/?q=push+button+&t=newext&atb=v336-1&iar=images&iax=images&ia=images) for on/off/away state 
  - A [rotary encoder](https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/) to easily set temperature or time delays. Though buttons can do.
- **Output**: the basic decision will be either some sort of screen, or a set of status LEDs
  - LEDs are very cheap and simple to code (and less things can go wrong). You can very easily add a ton of LEDs with a [port expander](https://learn.adafruit.com/adafruit-pcf8575/overview) or a serial-to-parallel IC like the classic [74HC595](https://www.arduino.cc/en/Tutorial/Foundations/ShiftOut)
  - Classic LCDs can be dirt cheap and sometimes easier to code. THey need a ton of wires, so I recommend either one that communicates over I<sup>2</sup>C or SPI (which only take up a couple of digital pins), or a port expander so you don't run out of microcontroller pins. Examples [here](https://www.adafruit.com/category/96). 
  - OLED screens look amazing and are easy to wire through I<sup>2</sup>C ([example](https://www.adafruit.com/product/4650))
- **Power supply:** Servo will likely be the only high(er) current device, so a normal USB should do (5V 1A) 

## Possible Integrations
- AdafruitIO seems like an obvious choice to get the ball rolling. It has a free version which allows control, time-series reporting and alerts from a web app.
- [Twilio](https://www.twilio.com/) can handle SMS and call notifications straight from the Arduino code. It can be free, but $10USD goeas a long way and makes things nicer. Cool things can be done like replying via SMS to interact with the Arduino!
- Email notifications from Arduino code can be done, too, but will unlikely be seen on time 
- [IFTTT](https://ifttt.com/) can also take care of free calls and handle other cool integrations
- HomeAssistant would be, by far, the easiest and most flexible one. In that case, the firmware wold be dead easy/simple with ESPHome, and HA would handle all the rules, UI and integrations/alerts.

 ## Dealbreakers
 - Device should not do silly things like unnecessarily open router ports

## Future integrations
- ?
 
### Disclaimer
This repo contains a bunch of links to Adafruit. I'm in no way afiliated to them, but they are an amazing company that produces and documents components like no others that I've seen. Amazon and AlieExpress are always options, but they are hit-or-miss quality, and I see no particualt reason to futher strengthen them.
