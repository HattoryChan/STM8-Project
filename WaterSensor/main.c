#include "iostm8l152c6.h"
/*-------------------================----------------==============-----------

====================------------------======================----------------*/

int main( void )
{
  
  //------------------------------------- PC[3,4,5] - input, push-pull
  PC_DDR_bit.DDR3 = 0;
  PC_DDR_bit.DDR4 = 0;
  PC_DDR_bit.DDR5 = 0;
  
  PC_CR1_bit.C13 = 1;
  PC_CR1_bit.C14 = 1;
  PC_CR1_bit.C15 = 1;
  //----------------------------------------- PC[7] - output,led
  PC_DDR_bit.DDR7 = 1;
  PC_CR1_bit.C17 = 1;
  //----------------------------------------- PE[7] - output, led
  PE_DDR_bit.DDR7 = 1;
  PE_CR1_bit.C17 = 1;
  
  while(1)
  {
    if(PC_IDR_bit.IDR3 == 0)
    {
      PC_ODR_bit.ODR7 = 1;
    }
    if(PC_IDR_bit.IDR5 == 0)
    {
      PE_ODR_bit.ODR7 = 1;
    }
    if(PC_IDR_bit.IDR3 == 1)
    {
      PC_ODR_bit.ODR7 = 0;
    }
    if(PC_IDR_bit.IDR5 == 1)
    {
      PE_ODR_bit.ODR7 = 0;
    }
  }
  return 0;
}
