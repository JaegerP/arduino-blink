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
#include<avr/interrupt.h>
#include"blink.h"

volatile uint8_t count = 0;

void set_timer_p1024_ms(uint16_t __t) {
	// enable compare and overflow interrupt
	TIMSK1 |= ((1 << OCIE1A) | (1 << TOIE1));

	// clear config registers
	TCCR1A = 0x00;
	TCCR1B = 0x00;

	// set CTC mode
	//TCCR1A |= ((1 << COM1A1) | (1 << COM1A0));
	TCCR1B |= 1 << WGM12;

	// 1024 prescaler
	TCCR1B |= ((1 << CS12) | (1 << CS10));

	// compare to this value
	OCR1A = __t * 16;

	sei();
}


void set_pwn_output(portpin_t *pp, uint16_t clk, float ratio);

int main (void) {
	portpin_t pp;
	pp.pn = 'b';
	pp.pin = PB5;
	set_output_pin(&pp);
	set_timer_p1024_ms(100);
	while (1) {

		if (count >= 1) {
			PORTB ^= 1<<PB5;
			count = 0;
		}
	}
	return 0;
}

ISR(TIMER1_COMPA_vect) {
	count++;

}
