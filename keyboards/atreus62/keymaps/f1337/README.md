1. Install [CrossPack AVR](https://obdev.at/products/crosspack/download.html)
1. `util/docker_build.sh atreus62:f1337`
1. `docker run -e keymap=f1337 -e keyboard=atreus62 --rm -v ('pwd'):/qmk:rw edasque/qmk_firmware`
1. Queue up the following in your terminal, but do not hit Enter yet: `/usr/local/CrossPack-AVR-20131216/bin/avrdude -p atmega32u4 -P /dev/tty.usbmodem1411 -c avr109  -U flash:w:atreus62_f1337.hex`
1. Tap the reset button on the back of the Atreus62.
1. Quickly hit "Enter" to submit the command you queued up.
1. Profit.
