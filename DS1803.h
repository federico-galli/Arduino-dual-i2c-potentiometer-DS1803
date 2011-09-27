/*
  Library for controlling the DS1803 ic with Arduino
  Tested with arduino-0018
  22/02/2010 Release 0.1
  Written by Federico and Riccardo Galli
  http://www.sideralis.org
*/

#ifndef DS1803_h
#define DS1803_h
#include "WProgram.h"
#include <Wire.h>

#define WIPER_0 0xA9
#define WIPER_1 0xAA
#define WIPER_01 0xAF


class DS1803
{
  int8_t addr;
  public:
    DS1803(int8_t addr);
    void setPot(int value, int wiper);
    int8_t *getValue();
  //private:
    //;
};

#endif
