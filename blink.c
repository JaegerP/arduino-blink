#include"blink.h"

void set_output_pin(portpin_t *pp) {
	switch (pp->pn) {
        case 'a':
        //    pp->port = PORTA;
        //    DDRA |= 1 << pp->pin;
            break;
        case 'b':
            pp->port = PORTB;
            DDRB |= 1 << pp->pin;
            break;
        case 'c':
            pp->port = PORTC;
            DDRC |= 1 << pp->pin;
            break;
        case 'd':
            pp->port = PORTD;
            DDRD |= 1 << pp->pin;
            break;
        default:
            break;
    }
	//*pp->ddrx |= 1 << pp->pinxn;	

}

void toggle_pin(portpin_t *pp) {
    pp->port ^= 1 << pp->pin;
}

void set_blink_frequency(portpin_t *pp, float __f);