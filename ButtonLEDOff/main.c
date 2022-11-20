#include <msp430.h> 


/**
 * main.c
 *
 * P1.0 = D1 Green LED
 * P1.6 = D2 Red LED
 * P1.3 = Button
 */

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= 0x40; //set P1.6 to output
	P1REN |= 0x08; //enable P1.3 pullup/pulldown
	P1OUT |= 0x08; //set P1.3 output to 1

	while(1)
	{
	    if ((P1IN & BIT3)) //button is not pressed
	    {
	        P1OUT |= BIT6; //turn on led
	    }
	    else //button is pressed
	    {
	        P1OUT &= ~BIT6; //turn off led
	    }
	}
}

