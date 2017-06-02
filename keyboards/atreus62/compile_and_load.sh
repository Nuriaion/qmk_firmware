

make atreus62-fabian
cp ../../atreus62_fabian.hex .
avrdude -p atmega32u4 -c avr109 -U flash:w:atreus62_fabian.hex -P /dev/cu.usbmodem1411
