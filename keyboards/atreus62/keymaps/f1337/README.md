docker run -e keymap=f1337 -e keyboard=atreus62 --rm -v ('pwd'):/qmk:rw edasque/qmk_firmware
/usr/local/CrossPack-AVR/bin/avrdude -p atmega32u4 -P /dev/tty.usbmodem1411 -c avr109  -U flash:w:atreus62_f1337.hex
