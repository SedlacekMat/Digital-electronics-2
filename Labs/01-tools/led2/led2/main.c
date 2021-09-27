/***********************************************************************
 * 
 * Blink a LED and use function from the delay library.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
/* The preprocessor will process directives that are inserted into the C
 * source code. These directives allow additional actions to be taken on
 * the C source code before it is compiled into object code. Directives
 * are not part of the C language itself.
 *
 * Preprocessor directives begin with a pound (#) symbol and may have 
 * several arguments. Do NOT put a semicolon character at the end of 
 * directives. This is a common mistake.
 */
#define LED_GREEN   PB5 
#define DELAY_DOT 250  // 1 "period"
#define DELAY_DASH 750 // 3 "periods"
#define DELAY_BLANK 250
#define DELAY_SYMBOLSPACE 750
#define DELAY_WORDSPACE 1750 // 7 "periods"
#ifndef F_CPU           
                        
# define F_CPU 16000000 
#endif                  

#include <util/delay.h> 
#include <avr/io.h>     


int main(void)
{
    
    DDRB = DDRB | (1<<LED_GREEN);

    PORTB = PORTB & ~(1<<LED_GREEN);

    while (1)
    {
		PORTB = PORTB |=(1<<LED_GREEN);  //PB5 high for three periods (letter D)
		_delay_ms(DELAY_DASH);
		
		PORTB = PORTB & ~(1<<LED_GREEN);  // PB5 low for one period
		_delay_ms(DELAY_BLANK);
		
		PORTB = PORTB |=(1<<LED_GREEN);  // PB5 high for one period (letter D)
		_delay_ms(DELAY_DOT);
		
		PORTB = PORTB & ~(1<<LED_GREEN); // PB5 low for one period
		_delay_ms(DELAY_BLANK);
		
		PORTB = PORTB |=(1<<LED_GREEN); // PB5 high for one period (letter D)
		_delay_ms(DELAY_DOT);
		
		PORTB = PORTB & ~(1<<LED_GREEN); // PB5 low for three periods (space between letters)
		_delay_ms(DELAY_SYMBOLSPACE);
		
		PORTB = PORTB |=(1<<LED_GREEN); // PB5 high for one period (letter E)
		_delay_ms(DELAY_DOT);
		
		PORTB = PORTB & ~(1<<LED_GREEN); // PB5 low for three periods (space between letters)
		_delay_ms(DELAY_SYMBOLSPACE);
		
		PORTB = PORTB |=(1<<LED_GREEN);  // PB5 high for one period (number 2)
		_delay_ms(DELAY_DOT);
		
		PORTB = PORTB & ~(1<<LED_GREEN); // PB5 low for one period
		_delay_ms(DELAY_BLANK);
		
		PORTB = PORTB |=(1<<LED_GREEN);  // PB5 high for one period (number 2)
		_delay_ms(DELAY_DOT);
		
		PORTB = PORTB & ~(1<<LED_GREEN); // PB5 low for one period
		_delay_ms(DELAY_BLANK);
		
		PORTB = PORTB |=(1<<LED_GREEN);  //PB5 high for three periods (number 2)
		_delay_ms(DELAY_DASH);
		
		PORTB = PORTB & ~(1<<LED_GREEN);  // PB5 low for one period
		_delay_ms(DELAY_BLANK);
		
		PORTB = PORTB |=(1<<LED_GREEN);  //PB5 high for three periods (number 2)
		_delay_ms(DELAY_DASH);
		
		PORTB = PORTB & ~(1<<LED_GREEN);  // PB5 low for one period
		_delay_ms(DELAY_BLANK);
		
		PORTB = PORTB |=(1<<LED_GREEN);  //PB5 high for three periods (number 2)
		_delay_ms(DELAY_DASH);
		
		PORTB = PORTB & ~(1<<LED_GREEN);  // PB5 low for seven periods (end of the word)
		_delay_ms(DELAY_WORDSPACE);
		
		
        
		
    }

    // Will never reach this
    return 0;
}
