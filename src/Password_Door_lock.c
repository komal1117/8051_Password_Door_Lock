#include <reg51.h>
#include <string.h>
#include "lcd4bit.h"
#include "keypad.h"


sbit LED_OPEN  = P3^7;//Green LED for Door Open
sbit LED_CLOSE = P3^6;//Red LED for Door Closed

void main(void)
{
    char password[5] = "1234";
    char entered[5];
    char key;
    unsigned char i = 0;

    LED_OPEN  = 0;
    LED_CLOSE = 0;

    lcd_init();
    lcd_cmd(0x01); //Clear display
    lcd_cmd(0x80); //First row
    lcd_string("ENTER PASSWORD");
    lcd_cmd(0xC0); //Second row

    while(1)
    {
        key = keypad_scan();

        if(key != 0)
        {
            lcd_data('*');
            entered[i++] = key;
            delay(120);

            if(i == 4)
            {
                entered[4] = '\0';

                lcd_cmd(0x01);
                lcd_cmd(0x80);

                if(strcmp(password, entered) == 0)
                {
                    lcd_string("ACCESS GRANTED");
                    LED_OPEN  = 1;
                    LED_CLOSE = 0;
                }
                else
                {
                    lcd_string("ACCESS DENIED");
                    LED_OPEN  = 0;
                    LED_CLOSE = 1;
                }

                delay(1000);

                //Reset indicators 
                LED_OPEN  = 0;
                LED_CLOSE = 0;

                //Prepared for next entry
                lcd_cmd(0x01);
                lcd_cmd(0x80);
                lcd_string("ENTER PASSWORD");
                lcd_cmd(0xC0);

                i = 0;
            }
        }
    }
}