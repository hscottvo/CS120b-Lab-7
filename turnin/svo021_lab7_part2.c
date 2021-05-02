/*	Author: lab
 *  Partner(s) Name: Scott Vo
 *	Lab Section: 021
 *	Assignment: Lab 7  Exercise 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *  Demo Link: https://youtu.be/ygETB9QzSyU
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRD = 0xFF; PORTD = 0x00;
    /* Insert your solution below */
    unsigned short val = 0;

    ADC_init();

    while (1) {
        val = ADC; 
        PORTB = (char)val;
        PORTD = (char)((val >> 8) & 0x03);
    }
    return 1;
}
