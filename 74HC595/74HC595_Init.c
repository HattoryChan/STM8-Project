#include "iostm8s105c6.h"

void Init_74HC595(void)
{
// Initiall Legs
//------------------------------- SH_CP PD[2] - Leg for clocking impulse
  PD_DDR_bit.DDR2 = 1;         //Output
  PD_CR1_bit.C12 = 1;          //Push-pull
  PD_CR2_bit.C22 = 1;          // <10MHz
//------------------------------- DS    PD[3] - Output data leg 
  PD_DDR_bit.DDR3 = 1;         //Output
  PD_CR1_bit.C13 = 1;          //Push-pull
  PD_CR2_bit.C23 = 1;          // <10MHz
//------------------------------- ST_CP  PD[4] - Fixing data register  
  PD_DDR_bit.DDR4 = 1;         //Output
  PD_CR1_bit.C14 = 1;          //Push-pull
  PD_CR2_bit.C24 = 1;          // <10MHz
}