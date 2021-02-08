/* Author:Christopher Chen
 * Partner(s) Name (if applicable):  
 * Lab Section:21
 * Assignment: Lab #7  Exercise #1
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 *
 *  Demo Link:https://www.youtube.com/watch?v=8rAIXnoKHxI 
 *
 */

#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	//ADMUX |= (1<<REFS0);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRD = 0xFF;
	DDRC = 0x03;
	DDRA = 0x00;
	
	PORTD = 0x00;
	PORTC = 0x00;
	PORTA = 0x00;

	
	unsigned short x = ADC;
	unsigned short tmpD = 0;
	unsigned short tmpC = 0;

	ADC_init();

    /* Insert your solution below */
    while (1) {
	x = ADC;
	tmpD = (char)x;
	tmpC = (char)(x>>8);
	PORTD = tmpD;
	//PORTD = 0;
	//PORTC = 1;
	PORTC = tmpC;
    }
    return 1;
}
