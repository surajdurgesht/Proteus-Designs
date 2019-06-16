
//-----Fosc = 11.592MHz, Baud Rate = 9600-------//
#include<reg51.h>
 
 
void uart_init();
void timer_init();
void uart_tx(unsigned char x);
unsigned char uart_rx();
void uart_msg(unsigned char *c);
void n_line();
 
void delay(unsigned int ms);
 
unsigned char tx_data;
 
void main()
{
    uart_init();
    uart_msg("Initializzing Serial Communication");
    n_line();
    delay(10);
    uart_msg("Processing.....");
    delay(1000);
    n_line();
    uart_msg("Connected");
    n_line();
    while(1)
    {
        uart_msg("<<");
        tx_data = uart_rx();
        n_line();
        n_line();
        uart_msg(">>");
        uart_tx(tx_data);
        n_line();
        n_line();
    }
}
 
void uart_init()
{
    SCON = 0x50;
    timer_init();
}
 
void timer_init()
{
    TMOD = 0x20;
    TH1 = 0xFD;
    TR1 = 1;
}
 
void uart_tx(unsigned char x)
{
    SBUF = x;
    while(!TI);
    TI = 0;
}
 
unsigned char uart_rx()
{
    unsigned char z;
    while(!RI);
    z = SBUF;
    RI = 0;
    return(z);
}
 
void uart_msg(unsigned char *c)
{
    while(*c != 0)
    {
        uart_tx(*c++);
    }
}
 
void delay(unsigned int ms)
{
    int i,j;
    for(i=0;i<=ms;i++)
        for(j=0;j<=120;j++);
}
 
void n_line()
{
    uart_tx(0x0d);
}