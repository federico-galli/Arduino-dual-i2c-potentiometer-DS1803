/*
  Library for controlling the DS1803 ic with Arduino
  Tested with arduino-0018
  22/02/2010 Release 0.1
  Written by Federico and Riccardo Galli
  http://www.sideralis.org
*/

#include "WProgram.h"
#include "DS1803.h"
#include <Wire.h>

DS1803::DS1803(int8_t addr)
{
  this->addr=addr;
  Wire.begin();
}

/* Set the values of the wiper (potentiometers)
    wiper 0 is pot0, wiper 1 is pot1 and wiper2 is pot0 and pot1
    Value is between 0 and 255
*/
void DS1803::setPot(int value,int wiper)
{
    Wire.beginTransmission(this->addr);
    
    if (wiper==2) Wire.send(WIPER_01);
    else Wire.send(wiper ? WIPER_1 : WIPER_0);
    
    Wire.send(value);
    Wire.endTransmission();
}

// Return an array of two values read from the IC
int8_t *DS1803::getValue()
{
	Wire.requestFrom(this->addr,2);
	int8_t *values=(int8_t*)malloc(sizeof(int8_t)*2);
	
	int k=0;
	while (Wire.available()) {
		values[k]=Wire.receive();
	}

	return values;
}
