/*	Author: lab
 *  Partner(s) Name: 
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
	unsigned char min = 103;
	unsigned char step = 23;
	
	ADC_init();

    /* Insert your solution below */
    while (1) {
	x = ADC;
	//x -= 103; //take away min offset
	//x = x/23; 
	if(x <= min) tmpD = 0;
	else if(x <= min+step) tmpD = 1;
	else if(x <= min+(2*step)) tmpD = 3;
	else if(x <= min+(3*step)) tmpD = 7;
	else if(x <= min+(4*step)) tmpD = 0x0F;
	else if(x <= min+(5*step)) tmpD = 0x1F;
	else if(x <= min+(6*step)) tmpD = 0x3F;
	else if(x <= min+(7*step)) tmpD = 0x7F;
	else if(x <= min+(8*step)) tmpD = 0xFF;
	tmpD = (char)x;
	//tmpC = (char)(x>>8);
	PORTD = tmpD;
	//PORTC = tmpC;
    }
    return 1;
}
