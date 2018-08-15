#include "STM8_Uart.h"


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
     
  UART2_BRR2 = brr & 0x000F;
  UART2_BRR2 |= brr >> 12;
  UART2_BRR1 = (brr >> 4) & 0x00FF;   
  
  //�������� ���������
  UART2_CR1_PIEN = 0;
  //�������� �������� ��������
  UART2_CR1_PCEN = 0;
  //8-������ �����
  UART2_CR1_M = 0;
  //�������� UART
  UART2_CR1_UART0 = 0;
   
  //��������� ���������� �� ����������� ��������. ��������
  UART2_CR2_TIEN = 0;
  //��������� ���������� �� ���������� ��������
  UART2_CR2_TCIEN = 0;
  //��������� ���������� �� ���������� ��������� ��������
  UART2_CR2_RIEN = 1;
  //��������� ���������� �� ������������ �����
  UART2_CR2_ILIEN = 0;
  //���������� ��������
  UART2_CR2_TEN = 1;
  //�������� ��������
  UART2_CR2_REN = 1;
  //�� �������� break-������
  UART2_CR2_SBK = 0;
   
  //���� ����-���
  UART2_CR3_STOP = 0;
}


// �������� �����
void uart_tx_byte(unsigned char data)
{
    while(!UART2_SR_TXE);
    UART2_DR = data;
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
       
    while(!UART2_SR_RXNE);
    data = UART2_DR;
    return data;
}
 
// ����� ������� ������
void uart_rx_data(unsigned char * data, unsigned char len)
{
  while(len--){
      *data++ = uart_rx_byte();
  }
}