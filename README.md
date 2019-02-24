# Sony Spresence (Arduino IDE)

This is my code for the IoT project (part of Hackster.io challenge), where I use Sony Spresence development board and various sensors to detect the storm front

## Part 1: Setup of Spresence board

This part was relatively easy, as it was simply following the steps on Sony Spresence's Web site, to enable integration with Arduino IDE
  https://developer.sony.com/develop/spresense/developer-tools/get-started-using-arduino-ide/set-up-the-arduino-ide#_spresense_arduino_library_getting_started_guide

## Part 2: Enabling light sensing via LM393 Light Sensor module

This part is now working in the code above, and system is able to detect spikes in the light intensity

## Part 3: Enabling sound sensing via MAX4466 Electret Microphone Amplifier

This part would require the use of Arturo Guadalupi's module for converting analog values from Microphone aplifier into the frequency ranges and check if there are any sounds in 100 Hz range within the first 5 seconds after the lightning. As per some reserch, 100 Hz is a predominant frequency of thunder, so we try to use as a part of danger zone assessment process.

![Schematics](https://github.com/LazaUK/SonySpresence-Arduino/blob/master/StormCatcher_Schematics.png)
