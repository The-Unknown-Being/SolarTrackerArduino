#include <Servo.h>
Servo horizontal;
int servoh = 90;
int servohLimitHigh = 180;
int servohLimitLow = 0;

Servo vertical;
int servov = 45;
int servovLimitHigh = 180;
int servovLimitLow = 0;

void setup(){
	horizontal.attach(3);
	vertical.attach(5);
	vertical.write(servov);
	horizontal.write(servoh);
	
	delay(3000);
}

void loop(){
	int dtime = 10; int tol = 50;
int lt = analogRead(0);
int rt = analogRead(1);
int ld = analogRead(2);
int rd = analogRead(3);

int avt = (lt+rt)/2;
int avd = (ld+rd)/2;
int avl = (lt+ld)/2;
int avr = (rt+rd)/2;

int dvert = avt-avd;
int dhoriz = avl - avr;

if(-1*tol > dvert || dvert > tol){
	if(avt < avd){
		servov += 2;
		if(servov > servovLimitHigh)
			servov = servovLimitHigh;
		vertical.write(servov);
		delay(50);
	}
	else if(avt > avd){
		servov -= 2;
		if(servov < servovLimitLow)
			servov = servovLimitLow;
		vertical.write(servov);
		delay(50);
	}
	else if(avt == avd) {}
}
if(-1*tol > dhoriz || dhoriz > tol){
	if(avl < avr){
		servoh += 2;
		if(servoh > servohLimitHigh)
			servoh = servohLimitHigh;
		horizontal.write(servoh);
		delay(50);
	}
	else if(avl > avr){
		servoh -= 2;
		if(servoh < servohLimitLow)
			servoh = servohLimitLow;
		horizontal.write(servoh);
		delay(50);
	}
	else if(avl == avr) {}
}

delay(100);
}