/* Author:Christopher Chen
 * Partner(s) Name (if applicable):  
 * Lab Section:21
 * Assignment: Lab #7  Exercise #3
 * Exercise Description: [optional - include for your own benefit]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 *
 *  Demo Link:https://www.youtube.com/watch?v=jH6glrOWlWc
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
	if(x >= 200) tmpD = 1;
	else tmpD = 0;

	PORTD = tmpD;
	PORTC = tmpC;
    }
    return 1;
}
