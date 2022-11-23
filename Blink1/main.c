#include <msp430.h> 


/**
 * main.c
 *
 * P1.0 = D1 Green LED
 * P1.6 = D2 Red LED
 */

//function declariations
void Blink_LED1();
void Delay(volatile unsigned long x);

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= 0x01; //set P1.0 to output
	P1DIR |= 0x40; //set P1.6 to output

	while(1)
	{
	    Blink_LED1();
	}
}

void Blink_LED1()
{
    P1OUT ^= 0x01; //toggle green led on/off
    P1OUT ^= 0x40; //toggle red led on/off
    Delay(10000);
}

void Delay(volatile unsigned long x)
{
    do x--;
    while(x != 0);
}
