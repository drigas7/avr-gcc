#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>


int main (void)
{
bool F, P, Q, R;
DDRD = 0b00000000; 
PORTD= 0b00111000;  // digital pins 3,4,5 as input
DDRB    |= ((1 << DDB5));  // digital pin 13 led as output
while(1)

	 P = (PIND & (1 << PIND3)) == (1 << PIND3);	 
   Q = (PIND & (1 << PIND4)) == (1 << PIND4);	 
   R = (PIND & (1 << PIND5)) == (1 << PIND5);	
   
   
   F = (P||Q||R)&&(P||!Q||!R)&&(!P||Q||R)&&(!P||Q||!R);

PORTB = ((1 <<  PB5));  // turns led on
