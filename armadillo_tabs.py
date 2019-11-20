import time
import serial
from playsound import playsound

# configure the serial connections (the parameters differs on the device you are connecting to)
ser = serial.Serial(
	port='com3',
	baudrate=9600,
	parity=serial.PARITY_ODD,
	stopbits=serial.STOPBITS_TWO,
	bytesize=serial.SEVENBITS
)

if not ser.isOpen():
    ser.open()
ser.isOpen()

print ('Enter your commands below.\r\nInsert "exit" to leave the application.')

inp=1
while 1 :
    out = ''
    while ser.inWaiting() > 0:
    	out+= ser.readline().decode('ascii')
	if out!= '':
		print(out)
		if out=='R1':
			playsound('armadillotailtest.mp3')
		elif out== 'R2':
			playsound('armadillotest.mp3')
       		# playsound('armadillotest.mp3')
    time.sleep(1)
