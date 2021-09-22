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

volatile uint8_t count = 0;

void set_timer_p1024_ms(uint16_t __t) {
	// enable compare and overflow interrupt
	TIMSK1 |= ((1 << OCIE1A) | (1 << TOIE1));

	// clear config registers
	TCCR1A = 0x00;
	TCCR1A = 0x00;

	// set CTC mode
	//TCCR1A |= ((1 << COM1A1) | (1 << COM1A0));
	TCCR1B |= 1 << WGM12;

	// 1024 prescaler
	TCCR1B |= ((1 << CS12) | (1 << CS10));

	// compare to this value
	OCR1A = __t * 16;

	sei();
}

int main (void) {
	DDRB = 1 << DDB5;
	set_timer_p1024_ms(2000);
	while (1) {

		if (count >= 1) {
			PORTB ^= 1<<PB5;
			count = 0;
		}
	}
	return 0;
}

ISR(TIMER1_COMPA_vect) {
	++count;
}
