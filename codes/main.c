
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>


int main (void)
{bool P,Q,R,F;
DDRD = 0b00000000;
PORTD= 0b00111000;  // digital pins 3,4,5 as input
DDRB    |= ((1 << DDB5));  // digital pin 13 led as output

while(1)
{
	

    P = (PIND & (1<<PD3)) ? 1:0;
    Q = (PIND & (1<<PD4)) ? 1:0;
    R = (PIND & (1<<PD5)) ? 1:0;
    F = (P||Q||R)&(P||!Q||!R)&(!P||Q||R)&(!P||Q||!R);
    F=!F;
	PORTB |=(F<<5);	

}    return 0;
}
