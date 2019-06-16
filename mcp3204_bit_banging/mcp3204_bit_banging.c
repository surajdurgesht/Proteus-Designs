												#include <reg52.h>
#include <stdio.h>
#include <intrins.h>

sbit cs=P1^7;    // to CS/SHDN of MCP3204
sbit miso=P1^6;  // to dout of MCP3204
sbit mosi=P1^5;  // to din of MCP3204
sbit clk=P1^4;   // to clk of MCP3204

void uart_init(void);
void delay_ms(unsigned int);
void delay_us(void);
float read_adc(unsigned int);

void main(void)
{

	uart_init();
	printf( "Welcome");
	printf("\n\r");

while(1)
{
	printf("voltage of channel 0 is : %f ",read_adc(0));
	printf("\n\r");
	delay_ms(100);
	printf("voltage of channel 1 is : %f ",read_adc(1));
	printf("\n\r");
	delay_ms(100);
	printf("voltage of channel 2 is : %f ",read_adc(2));
	printf("\n\r");
	delay_ms(100);
	printf("voltage of channel 3 is : %f ",read_adc(3));
	printf("\n\r");
	delay_ms(100);

}
}
float read_adc(unsigned int channel)
{
float result;
	unsigned int value;
	unsigned char i;
	value=0x00;

	if(channel==0)
	{
// for channel 0
// for startup
	cs=1;
	clk=1;
	mosi=1;
	miso=1;
// for start bit
	cs=0;
	mosi=1;
	clk=0;
	delay_us();
	clk=1;
//for single end/differential mode selection
  mosi=1;
	clk=0;
	delay_us();
	clk=1;

// for	d2
	 mosi=0;
	clk=0;
	delay_us();
	clk=1;

// for	d1
	 mosi=0;
	clk=0;
	delay_us();
	clk=1;

// for	d0
	 mosi=0;
	clk=0;
	delay_us();
	clk=1;
}
if(channel==1)
	{
		// for channel 1
// for startup
	cs=1;
	clk=1;
	mosi=1;
	miso=1;
// for start bit
	cs=0;
	mosi=1;
	clk=0;
	delay_us();
	clk=1;
//for single end/differential mode selection
  mosi=1;
	clk=0;
	delay_us();
	clk=1;

// for	d2
	 mosi=0;
	clk=0;
	delay_us();
	clk=1;

// for	d1
	 mosi=0;
	clk=0;
	delay_us();
	clk=1;

// for	d0
	 mosi=1;
	clk=0;
	delay_us();
	clk=1;
}
	if(channel==2)
	{
		// for channel 2
// for startup
	cs=1;
	clk=1;
	mosi=1;
	miso=1;
// for start bit
	cs=0;
	mosi=1;
	clk=0;
	delay_us();
	clk=1;
//for single end/differential mode selection
  mosi=1;
	clk=0;
	delay_us();
	clk=1;

// for	d2
	 mosi=0;
	clk=0;
	delay_us();
	clk=1;

// for	d1
	 mosi=1;
	clk=0;
	delay_us();
	clk=1;

// for	d0
	 mosi=0;
	clk=0;
	delay_us();
	clk=1;
}
	if(channel==3)
		{
		// for channel 3
// for startup
	cs=1;
	clk=1;
	mosi=1;
	miso=1;
// for start bit
	cs=0;
	mosi=1;
	clk=0;
	delay_us();
	clk=1;
//for single end/differential mode selection
  mosi=1;
	clk=0;
	delay_us();
	clk=1;

// for	d2
	 mosi=0;
	clk=0;
	delay_us();
	clk=1;

// for	d1
	 mosi=1;
	clk=0;
	delay_us();
	clk=1;

// for	d0
	 mosi=1;
	clk=0;
	delay_us();
	clk=1;
}
	// for t sample
  clk=0;
	delay_us();
	clk=1;

  // for ignoring null bit
  clk=0;
	delay_us();
	clk=1;

for(i=0;i<12;i++)
{
	value<<=1;
	clk=0;
	if(miso==1)
{
value=value+1;
}
 else
{
value=value+0;
}
clk=1;


}
cs=1;
result= ((value*5.0)/4096);
return (result);

}



void delay_ms(unsigned int time)
{
unsigned int i,j;
for(i=0;i<time;i++)
for(j=0;j<1275;j++);
}
void delay_us(void)
 {
  _nop_ ();  // generates delay of one machine cycle

 }
void uart_init(void)
{
          SCON = 0x52;   // setup serial port control
          TMOD = 0x20;   // hardware (9600 BAUD @11.05592MHZ)
          TH1 = 0xFD;   // TH1
          TR1 = 1;               // Timer 1 on
}
