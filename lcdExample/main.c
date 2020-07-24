/*
 * lcdExample.c
 *
 * Created: 13/07/2020 11:44:24 am
 * Author : John
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"

int main(void)
{
    LCD_Init();
	LCD_setCursor(5, 0);
	LCD_print("hello");
	_delay_ms(1000);
	//LCD_autoscroll();
	LCD_print("w");
	_delay_ms(1000);
	LCD_print("o");
	_delay_ms(1000);
	LCD_print("r");
	_delay_ms(1000);
	LCD_print("l");
	_delay_ms(1000);
	LCD_print("d");
	_delay_ms(1000);
    while (1) 
    {
    }
}

