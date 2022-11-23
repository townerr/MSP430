#include <msp430.h> 


/**
 * main.c
 *
 * P1.0 = D1 Green LED
 * P1.6 = D2 Red LED
 * P1.3 = Button
 */

//function declaration
void BlinkGreen(volatile int n);

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= 0x01; //set P1.6 to output
	P1REN |= 0x08; //enable P1.3 pullup/pulldown
	P1OUT |= 0x08; //set P1.3 output to 1
	P1OUT |= BIT0; //start p1.0 led on

	while(1)
	{
	    if (!(P1IN & BIT3)) //button is pressed
	    {
	        BlinkGreen(5); //blink n times
	        P1OUT |= BIT0; //turn p1.0 led back on if left off after blinking
	    }
	}
}

void BlinkGreen(volatile int n)
{
    int i = n * 2; //2x because each for loop cycle will be on then off
    for (; i > 0; i--)
    {
        P1OUT ^= BIT0; //toggle p1.0 led
        __delay_cycles(500000);
    }
}

