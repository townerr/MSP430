#include <msp430.h> 


/**
 * main.c
 *
 * P1.0 = D1 Green LED
 * P1.6 = D2 Red LED
 */

#define DELAY 500 //roughly .5 sec delay
unsigned int counter;

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= BIT0; //set P1.0 to output

	//timer init
	TACCR0 = 0; //initially off
	TACCTL0 |= CCIE; //enable interrupt
	TACTL = TASSEL_2 + ID_0 + MC_1; //submain clock, no freq division, up mode

	__enable_interrupt(); //enable interrupts

	//start timer
	counter = 0;
	TACCR0 = 1000-1; //roughly 1 sec

	while(1);
}

//timer isr
#pragma vector=TIMER0_A0_VECTOR
__interrupt void timer(void)
{
    counter++;
    if(counter >= DELAY)
    {
        P1OUT ^= BIT0; // toggle green led
        counter = 0; //reset timer counter
    }
}
