# Lab 3: Matyáš Sedláček

Link to your `Digital-electronics-2` GitHub repository:

   [https://github.com/SedlacekMat/Digital-electronics-2/tree/main/Labs/03-gpio](https://github.com/SedlacekMat/Digital-electronics-2/tree/main/Labs/03-gpio)


### Data types in C

1. Complete table.

| **Data type** | **Number of bits** | **Range** | **Description** |
| :-: | :-: | :-: | :-- | 
| `uint8_t`  | 8 | 0, 1, ..., 255 | Unsigned 8-bit integer |
| `int8_t`   | 8 | 0, 1, ..., 255  | Signed 8-bit integer |
| `uint16_t` | 16 | 0, 1, ..., 65536  | Unsigned 16-bit integer |
| `int16_t`  | 16 | 0, 1, ..., 65536 | Signed 16-bit integer |
| `float`    | 32 | -3.4e+38, ..., 3.4e+38 | Single-precision floating-point |
| `void`     | 0 | - | Result of a function which returns no value |


### GPIO library

1. In your words, describe the difference between the declaration and the definition of the function in C.
   * Function declaration: Specifies what the inputs and outputs are and their types
   * Function definition: Specifies what the function actually does, the operations that are done with the inputs to get an output 

2. Part of the C code listing with syntax highlighting, which toggles LEDs only if push button is pressed. Otherwise, the value of the LEDs does not change. Use function from your GPIO library. Let the push button is connected to port D:

```c
int main(void)
{
    // Green LED at port B
    GPIO_config_output(&DDRB, LED_GREEN);
    GPIO_write_low(&PORTB, LED_GREEN);

    // Configure the second LED at port C
	GPIO_config_output(&DDRC, LED_RED);
	GPIO_write_low(&PORTC, LED_RED);

    // Configure Push button at port D and enable internal pull-up resistor
	GPIO_config_input_pullup(&DDRD, PUSH_BUTT);
	GPIO_write_high(&PORTD, PUSH_BUTT);

    // Infinite loop
    while (1)
    {
        if (GPIO_read(&DDRD,PUSH_BUTT) == 0)
        {
			_delay_ms(BLINK_DELAY);

			GPIO_toggle(&DDRB, LED_GREEN);
			GPIO_toggle(&DDRC, LED_RED);
		}
    }

    // Will never reach this
    return 0;
}
```


### Traffic light

1. Scheme of traffic light application with one red/yellow/green light for cars and one red/green light for pedestrians. Connect AVR device, LEDs, resistors, one push button (for pedestrians), and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![TrafficDia](Images/TrafficDia.png)
