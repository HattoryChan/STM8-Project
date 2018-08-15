#include "iostm8s105c6.h"
/*------------------------------------------------
Засовыет в себя значение пина DS при появлении HIGH сигнала на ноге SH_CP
 записывает в регистр хранения при появлении HIGH level на ST.
-------------------------------------------------*/
// SH_CP PD[2] - Leg for clocking impulse
// DS    PD[3] - Output data leg 
// ST_CP  PD[4] - Fixing data register

#define SH_CP   PD_ODR_bit.ODR2
#define DS      PD_ODR_bit.ODR3
#define ST_CP   PD_ODR_bit.ODR4

void ShiftRegister(int value);
void Init_74HC595(void);

int main( void )
{
  Init_74HC595();  
  for(int i = 0; i <=6; i++)
  {
    ShiftRegister(0);
  }
  for(int i = 0; i <=8; i++)
  {
    ShiftRegister(1);
  }
  ST_CP = 1; // Fixing Data
  while(1); 
  
}

void ShiftRegister(int value)
{
   ST_CP = 0;    //Leg to Write data
   SH_CP = 1;   //Clocking Write Impulse
   DS = value;  //Writing bits
   SH_CP = 0;   //Clocking Ended impulse
  
}