Plush Gamecontroller with Adafruit Flora
================

Plush controller with USB for games with [Adafruit Flora](https://github.com/adafruit/adafruit_flora_game_controller).

The firmware uses the [CapPin Library](https://github.com/moderndevice/CapSense) for measure the capcaity on the 8 pins on the Adafruit Flora controller. The threshold is set to a minimum to boost the reaction time of the Flora.

 ![Image 1](https://raw2.github.com/eugenpirogoff/plush_controller/master/images/IMG_1322.jpg)
 ![Image 2](https://raw2.github.com/eugenpirogoff/plush_controller/master/images/IMG_1338.jpg)
 ![Image 3](https://raw2.github.com/eugenpirogoff/plush_controller/master/images/IMG_1342.jpg)
 ![Image 4](https://raw2.github.com/eugenpirogoff/plush_controller/master/images/IMG_1344.jpg)
 ![Image 5](https://raw2.github.com/eugenpirogoff/plush_controller/master/images/IMG_1346.jpg)
 

HowTo
=========

Please follow the [instructions on the Adafruit learningsystem](http://learn.adafruit.com/plush-game-controller/) and be aware of some [false pictures](https://github.com/adafruit/adafruit_flora_game_controller/issues/1) in it. (This issue may be fixed by then.)


Firmware
========
After compiling and uploading the [firmware.ino](https://github.com/eugenpirogoff/plush_controller/blob/master/firmware.ino) with the Adafruit IDE to the controller, it behaves like any other HID on Windows and Mac OSX systems and emits the given strings on event to the operating system or emulator used. I strongly suggest using [OpenEmu](http://openemu.org/).
