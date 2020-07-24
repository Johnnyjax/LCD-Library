
//PORT AND PIN DECLARATIONS
#define CNTRDDR PORTD
#define DATA_DDR PORTB
#define EN PB3
#define RS PB4

// COMMAND CODES
#define CLEAR_DISPLAY  0b00000001 // clears the display
#define HOME_CURSOR    0b00000010 // Sets the cursor to the home position
#define FUNC_SET       0b00101000 // Sets 4bit length, No of lines to 2 and sets the Font size
#define ENTRY_MOD_SET  0b00000100 // Increment Screen address and enable shifting
#define DISPLAY_ON     0b00001111 // Turn on Display, Display Cursor, No Blinking
#define CUR_RIGHT_SHFT 0b00010100 //Shift cursor to the right by 1
#define CUR_LEFT_SHFT  0b00010000 //Shift cursor to the left by 1
#define SCROLL_LEFT    0b00011000 //Shift the entire display to the left by 1
#define SCROLL_RIGHT   0b00011100 //Shift the entire display to the right by 1

//Liquid Crystal init function
void LCD_Init();
void LCD_send4bits(uint8_t cmd, uint8_t mode);
void LCD_sendCmd(uint8_t cmd);
void LCD_sendData(uint8_t data);
void LCD_clear();
void LCD_home();
void LCD_setCursor(uint8_t col, uint8_t row);
void LCD_print(const char myString[]);
void LCD_shift_cursor();
void LCD_scrollDisplayLeft();
void LCD_scrollDisplayRight();
void LCD_autoscroll();
void LCD_noAutoscroll();

