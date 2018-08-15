#include "iostm8s003f3.h"

#define Led_Pin PC_ODR_bit.ODR4  //Define for ON\Off led on Port C[4]

void Delay(long Delay)
{
  for(unsigned long i = 0; i < Delay; i++);
}

int main( void )
{
  PC_DDR_bit.DDR4 = 1;   //Port c[7] -> Setting
  PC_CR1_bit.C14 = 1;   //Push-pull mode
  
  while(1)
  {
    // PC_ODR_bit.ODR4 = 1;   //High level on pins
    Led_Pin = 1;  //Define workind, Thats Greate!!!)
    Delay(30000);
    // PC_ODR_bit.ODR4 = 0;   //Low ledel pins
    Led_Pin = 0;
    Delay(30000);
  }    
}
