/*	Author: lab
 *  Partner(s) Name: Scott Vo
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
unsigned short MAX = 0x00FF;
void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    // DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
    unsigned short val = 0;
    unsigned char thresh = MAX / 8;

    ADC_init();

    while (1) {
        val = ADC;
        if(val < thresh) {
            PORTB = 0x01;
        } else if (val < 2 * thresh) {
            PORTB = 0x03;
        } else if (val < 3 * thresh) {
            PORTB = 0x07;
        } else if (val < 4 * thresh) {
            PORTB = 0x0F;
        } else if (val < 5 * thresh) {
            PORTB = 0x1F;
        } else if (val < 6 * thresh) {
            PORTB = 0x3F;
        } else if (val < 7 * thresh) {
            PORTB = 0x7F;
        } else {
            PORTB = 0xFF;
        }

    }
    return 1;
}
