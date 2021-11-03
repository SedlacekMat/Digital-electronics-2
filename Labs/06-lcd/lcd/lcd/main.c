/***********************************************************************
 * 
 * Stopwatch with LCD display output.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2017-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include "lcd.h"            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for conversion function

/* Variables ---------------------------------------------------------*/
// Custom character definition using https://omerk.github.io/lcdchargen/
uint8_t customCharDown[8] = {
	0b01110,
	0b01110,
	0b00100,
	0b01110,
	0b10101,
	0b00100,
	0b01010,
	0b10001
};
uint8_t customCharUp[8] = {
	0b01110,
	0b01110,
	0b10101,
	0b01110,
	0b00100,
	0b00100,
	0b01010,
	0b10001
};



/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Update stopwatch value on LCD display when 8-bit 
 *           Timer/Counter2 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Initialize LCD display
    lcd_init(LCD_DISP_ON);

    // Load custom character 1
    lcd_command(1 << LCD_CGRAM);
    for (uint8_t i = 0; i < 8; i++){
        // Store all new chars to memory line by line
        lcd_data(customChar1[i]);
    }
    
    for (uint8_t i = 0; i < 8; i++){
        // Store all new chars to memory line by line
        lcd_data(customChar2[i]);
    }
    lcd_command(1 << LCD_DDRAM);
    
    // Display first custom character
    lcd_home();
    lcd_putc(0);
    lcd_gotoxy(0, 1);
    lcd_putc(1);

    

    // Put string(s) at LCD display
    //string
    lcd_gotoxy(1, 0);
    lcd_puts("00:00.0");
    //a char
    lcd_gotoxy(11, 0);
    lcd_putc('a');
    //b char
    lcd_gotoxy(1, 1);
    lcd_putc('b');
    //c char
    lcd_gotoxy(11, 1);
    lcd_putc('c');
    // Configure 8-bit Timer/Counter2 for Stopwatch
    // Set the overflow prescaler to 16 ms and enable interrupt
    TIM2_overflow_16ms();
    TIM2_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter2 overflow interrupt
 * Purpose:  Update the stopwatch on LCD display every sixth overflow,
 *           ie approximately every 100 ms (6 x 16 ms = 100 ms).
 **********************************************************************/
ISR(TIMER2_OVF_vect)
{   
    static uint8_t number_of_overflows = 0;
    static uint8_t time_tens = 0; //tenths
    static uint8_t time_secs = 0;   //seconds
    char lcd_string[2] = "  ";      // String for converting numbers by itoa()

    number_of_overflows++;
    if (number_of_overflows >= 6) //100ms 
    {
        // Do this every 6 x 16 ms = 100 ms
        number_of_overflows = 0;

        // WRITE YOUR CODE HERE
        time_tens++;
        //show tens
        itoa(time_tens, lcd_string, 10);     // Convert to str
        lcd_gotoxy(7,0); //set cursor
        lcd_puts(lcd_string); //update tens
        if(time_tens==9){ //happens every 1sec
            time_tens=0; //reset tenths
            time_secs++; //increment seconds
            //set correct cursor pos.    
            if(time_secs < 10){ lcd_gotoxy(5,0);
            } //...for one digit number
            else { lcd_gotoxy(4,0);   
            }//...for two digit number
            //show seconds
            itoa(time_secs, lcd_string, 10);     // Convert decimal value to string
            lcd_puts(lcd_string);
            if(time_secs == 59){
            time_secs=0;
            lcd_gotoxy(4,0);
            lcd_puts("00");
            }            
        }
    }
    // Else do nothing and exit the ISR
    
    
}