/*  Name     : main.c
 *  Purpose  : Main file for i2c code for AT89C51.
 *  Author   : M.Saeed Yasin
 *  Date     : 05-11-12
 *  Website  : saeedsolutions.blogspot.com
 *  Revision : None
 */
#include "Includes.h"

// Main function
void main()
{	
	unsigned char RxByte = 0;

	InitI2C();					// Initialize i2c pins								

	I2C_Start();				// Send start bit on i2c
	I2C_Write_Byte(0xB0);		// Send 0xA0 on i2c
	RxByte = I2C_Read_Byte();	// Read value from i2c
	I2C_Send_ACK();				// Send ACK bit on i2c
	I2C_Stop();					// Send stop bit on i2c
	
	while(1)
	{	
	}
}