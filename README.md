This is a project from the discipline of Robotic at Electrical Engeneering course

Theory

≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣ 

Sonar: Considering tha the car run 10cm we have:
➜ Constant - soundSpeed = 340 m/s ∴ soundSpeed = 34 * 1000 cm/s

Techo = Tgo + Tback
Techo = 2 * Δs / soundSpeed
Techo = 2 * 0.1 / (34 * 1000)

∴ Techo = 5,7 us

This is done by NewPing.h library

≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣ 

Communication between Arduino Uno and Smartphone is done by HC-06 Bluetooth shield

including SofwareSerial.h library it's possible to send and received data from 
digital pins by <defined>.read() and <defined>.write()

≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣ 

Servo.h library controls the movement from the sonar, witch 
is driven by SG90 servomotor

≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣ 

Using my own application 
on git https://github.com/ghcosta87/ble_robot_controller_app.git or any
other android application, you can:
1) Control the car for the directions:
forward, forward-left, forward-right, backward, backward-left, backward-right
2) Read the distance between the car and an object in front of it in centimeters
3) Get battery health
4) Bluetooth connection status
5) Car direction feedback

≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣ 
Direction definitions

#define FORWARD 'F'
#define BACKWARD 'B'
#define FRONTNEUTRAL 'n'
#define LEFTSIDE 'L'
#define RIGHTSIDE 'R'
#define SIDENEUTRAL 'C'
#define STOP 'S'
#define STOPRELEASED 's'

≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣≣ 
Other reading settings

The ble on Arduino uno send an String Array with blank spaces, you can use it to
filter wich variable you want to grab

outputToWrite = "d <sonarValue> a <carDirection> v <batteryVoltage> b <bleConnectionStatus>"

Then you can just .split(' ')



