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
		if 'dist' in out:
			print ("dist confirmed")
			playsound("intro_armadillo.mp3")
			ser.write('done/n'.encode())
			print ("mp3 finished, message sent")
		elif 'R1' in out:
			print ("R1 confirmed")
			playsound('tail_armadillo.mp3')
			ser.write('done/n'.encode())
			print ("mp3 finished, message sent")
		elif 'R2' in out:
			print ("R2 confirmed")
			playsound('feet_armadillo.mp3')
			ser.write('done/n'.encode())
			print ("mp3 finished, message sent")
		elif 'R3' in out:
			print ("R3 confirmed")
			playsound('screaming_armadillo.mp3')
			ser.write('done/n'.encode())
			print ("mp3 finished, message sent")
		elif 'R4' in out:
			print ("R4 confirmed")
			playsound('back_armadillo.mp3')
			ser.write('done/n'.encode())
			print ("mp3 finished, message sent")
		
	time.sleep(1)
