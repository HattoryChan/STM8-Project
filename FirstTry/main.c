//#include "iostm8s003f3.h"

#include "iostm8s105c6.h"
 
//#include "iostm8l152C6.h"

//delay
void Delay()
{
  for(unsigned long delay_count = 0; delay_count < 30000; delay_count++);
}

int main( void )
{ 
  //--------------------------------------------   Button for led  D
  PC_DDR_bit.DDR3 = 0;                          //PC[3] - input
  PC_CR1_bit.C13 = 1;                           //push-pull input
  PC_CR1_bit.C13 = 0;                           //disallow interrupt
 
  // For stm8S003
  PC_DDR_bit.DDR4 = 1;                  //C[4] - output
  PC_CR1_bit.C14 = 1;                   // push-pull mode
  /*
  // For STM8L152
  PC_DDR_bit.DDR7 = 1; //Настраиваем 7й пин порта C на выход
   PC_CR1_bit.C17 = 1;
  */
 
  while(1)
  {   
    if(PC_IDR_bit.IDR3 == 1)
    {
      PC_ODR_bit.ODR4 = 1;                        //ON
    }
      if(PC_IDR_bit.IDR3 == 0)
    {
      PC_ODR_bit.ODR4 = 0;                        //OFF
    }
   
    //For stm8s003
 //   PC_ODR_bit.ODR4 = 1;                        //ON
 //   Delay();
 //   PC_ODR_bit.ODR4 = 0;                        //OFF
 //   Delay();
    /*
    //For Stm8L152
    PC_ODR_bit.ODR7 = 1;
    Delay();
    PC_ODR_bit.ODR7 = 0;
    Delay();
    */
  }
  return 0;
}
