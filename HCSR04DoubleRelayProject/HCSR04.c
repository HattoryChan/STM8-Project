#include "iostm8s003f3.h"

#define Trig_Pin PD_ODR_bit.ODR2
#define Echo_Pin PD_IDR_bit.IDR3

int TimeCount(void);


//=======================================================       Range calculate
int Ranging(void)
{  
  int range = 0;
  
  range = TimeCount()/12;                       //Calculate to sentimeters
  
  return range;
}
//===================================================      Impulse Echo pin time
int TimeCount(void)
{  
  int time = 0;
  
      Trig_Pin = 1;          //TRIG PIN - Start pulse
   for(int i = 30; i >= 0; i--);
      Trig_Pin = 0;         //TRIG PIN - Off pulse
  while(Echo_Pin==0);  
  while(Echo_Pin==1)
    {
      time++;
    }
  
  return time;
}
