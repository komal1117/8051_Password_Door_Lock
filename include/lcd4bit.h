#include <reg51.h>
#define Data P2// D4 to D7 connected to P2.0 to P2.3

sbit RS = P2^4;
sbit EN = P2^5;

void lcd_init(void);
void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char dat);
void lcd_string(unsigned char *str);
void delay(unsigned int t);

void delay(unsigned int t)
{
    unsigned int i, j;
    for(i = 0; i < t; i++)
        for(j = 0; j < 1275; j++);
}

void lcd_cmd(unsigned char cmd)
{
    Data = (cmd >> 4);   
    RS = 0;
    EN = 1;
    delay(1);
    EN = 0;

    Data = cmd;          
    RS = 0;
    EN = 1;
    delay(1);
    EN = 0;
}

void lcd_data(unsigned char dat)
{
    Data = (dat >> 4);
    RS = 1;
    EN = 1;
    delay(1);
    EN = 0;

    Data = dat;
    RS = 1;
    EN = 1;
    delay(1);
    EN = 0;
}

void lcd_init(void)
{
    lcd_cmd(0x28);   //4-bit, 2-line
    lcd_cmd(0x01);   //Clear display
    lcd_cmd(0x0F);   //Display ON, cursor blinking
    lcd_cmd(0x80);   //First row
}

void lcd_string(unsigned char *str)
{
    while(*str)
        lcd_data(*str++);
}