#include "iostm8s003f3.h"
//#include "iostm8l152C6.h"
#include <intrinsics.h>  //����� ������� ������� __enable_interrupt ().


void uart_init(unsigned long baud_rate, unsigned long f_master);
void uart_tx_byte(unsigned char data);
void uart_tx_data(unsigned char * data, unsigned char len);
unsigned char uart_rx_byte();
void uart_rx_data(unsigned char * data, unsigned char len);


// ���������� ���������� �� ������ UART
#pragma vector=UART1_R_RXNE_vector 
__interrupt void uart_rx_interrupt(void)
{
  unsigned char data;
   
  data = UART1_DR;
   
  //�������� �������� ���� �������
  uart_tx_byte(data);
}

void Delay(long Delay)
{
  for(unsigned long i = 0; i < Delay; i++);
}

void uart_init(unsigned long baud_rate, unsigned long f_master)
{
   
  //�������� �������� BRR
  unsigned long brr;
   
  //����������� TX �� �����, � RX �� ����
  PD_DDR_bit.DDR5 = 1;  //TX
  PD_DDR_bit.DDR6 = 0;  //RX
   
  //RX - ��������� ����
  PD_CR1_bit.C16 = 0;
  //��������� ������� ���������� ��� RX
  PD_CR2_bit.C26 = 0;
   
  //��������� �������� ��������
  brr = f_master/baud_rate;
     
  UART1_BRR2 = brr & 0x000F;
  UART1_BRR2 |= brr >> 12;
  UART1_BRR1 = (brr >> 4) & 0x00FF;   
  
  //�������� ���������
  UART1_CR1_PIEN = 0;
  //�������� �������� ��������
  UART1_CR1_PCEN = 0;
  //8-������ �����
  UART1_CR1_M = 0;
  //�������� UART
  UART1_CR1_UART0 = 0;
   
  //��������� ���������� �� ����������� ��������. ��������
  UART1_CR2_TIEN = 0;
  //��������� ���������� �� ���������� ��������
  UART1_CR2_TCIEN = 0;
  //��������� ���������� �� ���������� ��������� ��������
  UART1_CR2_RIEN = 1;
  //��������� ���������� �� ������������ �����
  UART1_CR2_ILIEN = 0;
  //���������� ��������
  UART1_CR2_TEN = 1;
  //�������� ��������
  UART1_CR2_REN = 1;
  //�� �������� break-������
  UART1_CR2_SBK = 0;
   
  //���� ����-���
  UART1_CR3_STOP = 0;
}

int main()
{        
  unsigned char data;
  
   
 //uart_init(UART_BAUD_RATE, F_MASTER);
  uart_init(9600, 1000000);
  
   
  uart_tx_data("Hello, world!\r\n", 15); 
  __enable_interrupt();

   
  while(1)
  {
  //  uart_rx_data(&data, 1);
   //   uart_tx_data(&data, 1);   
  }
}

// �������� �����
void uart_tx_byte(unsigned char data)
{
    while(!UART1_SR_TXE);
    UART1_DR = data;
}
 
// �������� ������� ������
void uart_tx_data(unsigned char * data, unsigned char len)
{
  while(len--){
      uart_tx_byte(*data++);
  }
}
// ����� �����
unsigned char uart_rx_byte()
{
    unsigned char data;
       
    while(!UART1_SR_RXNE);
    data = UART1_DR;
    return data;
}
 
// ����� ������� ������
void uart_rx_data(unsigned char * data, unsigned char len)
{
  while(len--){
      *data++ = uart_rx_byte();
  }
}
