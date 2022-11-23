#include <msp430.h> 


/**
 * main.c
 *
 * P1.0 = D1 Green LED
 * P1.6 = D2 Red LED
 */

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= 0x01; //set P1.0 to output
	P1DIR |= 0x40; //set P1.6 to output

	while(1)
	{
	    P1OUT ^= 0x01; //toggle green led on/off
	    P1OUT ^= 0x40; //toggle red led on/off
	    __delay_cycles(100000);
	}
}
