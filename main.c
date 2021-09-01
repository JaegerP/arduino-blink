/*
 * Let the Arduino blink
 *
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Philipp Jaeger <philipp.jaeger@aeg-nb.de> wrote this file.  As long as you 
 * retain this notice you can do whatever you want with this stuff. If we meet 
 * some day, and you think this stuff is worth it, you can buy me a beer in 
 * return.
 *                                                              -Philipp Jaeger
 * ----------------------------------------------------------------------------
 */



#include<avr/io.h>
#include<util/delay.h>


int main (void) {
	DDRB = 1 << DDB5;
	while (1) {
		PORTB ^= 1<<PB5; 
		_delay_ms(1000);
	}
	return 0;
}
