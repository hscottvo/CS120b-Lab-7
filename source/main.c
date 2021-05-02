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
unsigned char thresh = 0x1F;
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
    unsigned char tmpB = 0x00;

    ADC_init();

    while (1) {
        val = ADC; 
        tmpB = 0xFF;
        while (tmpB >= (val / 8)){
            tmpB = tmpB >> 1;
        }
        PORTB = tmpB;
    }
    return 1;
}
