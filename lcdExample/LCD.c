#include <avr/io.h>
#include <util/delay.h>
#include "LCD.h"

//Function to send 4 bits
void LCD_send4bits(uint8_t cmd, uint8_t mode) {
	PORTD = cmd << 2;
	if(mode == 0) {
		PORTB &= ~(1 << RS);
	} else {
		PORTB |= (1 << RS);
	}
	_delay_us(100);
	PORTB &= ~(1 << EN);
	_delay_us(1);
	PORTB |= (1 << EN);
	_delay_us(1);
	PORTB &= ~(1 << EN);
	_delay_us(100);
}

//function to send commands
void LCD_sendCmd(uint8_t cmd) {
	LCD_send4bits(cmd >> 4, 0);
	LCD_send4bits(0x0f & cmd, 0);
}

//function to send data
void LCD_sendData(uint8_t data) {
	LCD_send4bits(data >> 4, 1);
	LCD_send4bits(0x0f & data, 1);
}

//LCD Initialization function
void LCD_Init() {
	DDRB = 0xFF;
	DDRD = 0xFF;
	//Initialization routine in datasheet figure 24
	_delay_ms(5);
	LCD_send4bits(3, 0);
	_delay_ms(5);
	LCD_send4bits(3, 0);
	_delay_ms(10);
	LCD_send4bits(3, 0);
	_delay_us(100);
	LCD_send4bits(2, 0);
	_delay_us(100);
	
	LCD_sendCmd(FUNC_SET);
	LCD_sendCmd(ENTRY_MOD_SET);
	LCD_sendCmd(DISPLAY_ON);
	LCD_sendCmd(CLEAR_DISPLAY);
	_delay_ms(2);
}

//Print a string on an LCD
void LCD_print(const char myString[]) {
	uint8_t i = 0;
	while (myString[i]) {
		LCD_sendData(myString[i]);
		i++;
	}
}

//Shift the LCD cursor to the right by 1
void LCD_shift_cursor() {
	LCD_sendCmd(CUR_RIGHT_SHFT);
}

//Set the LCD cursor to the location provided
void LCD_setCursor(uint8_t col, uint8_t row) {
	if(row == 0) {
		LCD_sendCmd(128 + col);
	} else {
		LCD_sendCmd(192 + col);
	}
}

//Move the LCD Cursor to the home position
void LCD_home() {
	LCD_sendCmd(HOME_CURSOR);
}

//scroll the display to the left by 1
void LCD_scrollDisplayLeft() {
	LCD_sendCmd(SCROLL_LEFT);
}

//scroll the display to the right by 1
void LCD_scrollDisplayRight() {
	LCD_sendCmd(SCROLL_RIGHT);
}