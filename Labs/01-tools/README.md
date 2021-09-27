# Lab 1: Matyáš Sedláček

Link to your `Digital-electronics-2` GitHub repository:

   [DE2 Repository, Lab 1](https://github.com/SedlacekMat/Digital-electronics-2/tree/main/Labs/01-tools)


### Blink example

1. What is the meaning of the following binary operators in C?
   * `|` OR
   * `&` AND
   * `^` XOR
   * `~` NOT
   * `<<` shift bit to the left
   * `>>` shift bit to the right

2. Complete truth table with operators: `|`, `&`, `^`, `~`

| **b** | **a** |**b or a** | **b and a** | **b xor a** | **not b** |
| :-: | :-: | :-: | :-: | :-: | :-: |
| 0 | 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 1 | 0 | 1 | 1 |
| 1 | 0 | 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 | 0 |


### Morse code

1. Listing of C code which repeats "DE2" in Morse code by blinking an LED, delay variables included:

```c
#define LED_GREEN   PB5 
#define DELAY_DOT 250  // 1 "period"
#define DELAY_DASH 750 // 3 "periods"
#define DELAY_BLANK 250
#define DELAY_SYMBOLSPACE 750
#define DELAY_WORDSPACE 1750 // 7 "periods"

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

```


2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![your figure]()
