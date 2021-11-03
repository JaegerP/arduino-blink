#ifndef __BLINK_H__
#define __BLINK_H__

#include<avr/io.h>
#include<avr/interrupt.h>

typedef struct portpin {
    char pn;
	uint8_t port;
	uint8_t pin;
	//uint8_t *ddrx;
	//uint8_t ddxn;
} portpin_t;


void set_output_pin(portpin_t *pp);
/**
 * Initialize a pin as output
 * @param pp: portpin struct
 */

void toggle_pin(portpin_t *pp);
/**
 * Toggle pin value
 * @param pp: portpin struct
 */

void set_blink_frequency(portpin_t *pp, float __f);

#endif // __BLINK_H__