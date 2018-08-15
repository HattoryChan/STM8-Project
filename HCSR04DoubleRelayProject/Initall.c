#include "iostm8s003f3.h"

void Init(void)
{ 
 // Initiall legs
  //----------------------------------- TRIGGER PIN - PD[2]
  PD_DDR_bit.DDR2 = 1;         //Output
  PD_CR1_bit.C12 = 1;          //Push-pull
  PD_CR2_bit.C22 = 1;          // <10MHz
  //------------------------------------ ECHO PIN - PD[3]
  PD_DDR_bit.DDR3 = 0;         //Input
  PD_CR1_bit.C13 = 0;          //Floating input
  PD_CR2_bit.C23 = 0;          //disallow interrupt
  //----------------------------------- Led PIN first relay - PD[4]
  PD_DDR_bit.DDR4 = 1;          //Output
  PD_CR1_bit.C14 = 1;           //Push-pull
  PD_CR2_bit.C24 = 1;           // <10MHz
  //----------------------------------- Led PIN second relay - PD[5]
  PD_DDR_bit.DDR5 = 1;          //Output
  PD_CR1_bit.C15 = 1;           //Push-pull
  PD_CR2_bit.C25 = 1;           // <10MHz  
  //----------------------------------- First Relay pin - PC[3]
  PC_DDR_bit.DDR3 = 1;          //Output
  PC_CR1_bit.C13 = 1;           //Push-pull
  PC_CR2_bit.C23 = 1;           // <10MHz
  //----------------------------------- Second Relay pin - PC[4]
  PC_DDR_bit.DDR4 = 1;          //Output
  PC_CR1_bit.C14 = 1;           //Push-pull
  PC_CR2_bit.C24 = 1;           // <10MHz
  //------------------------------------ Button First Setting - PC[5]
  PC_DDR_bit.DDR5 = 0;         //Input
  PC_CR1_bit.C15 = 1;          //Push-Pull
  PC_CR2_bit.C25 = 0;          //disallow interrupt
  
}