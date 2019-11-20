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
		print (out)
		print (len(out))
		if 'R1' in out:
			print ("confirmed")
			playsound('tail_armadillo.mp3')
		elif 'R2' in out:
			playsound('armadillotest.mp3')
       		# playsound('armadillotest.mp3')
	time.sleep(1)
