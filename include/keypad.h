#include <reg51.h>

// -------- ROW PINS -------- 
sbit R1 = P1^0;
sbit R2 = P1^1;
sbit R3 = P1^2;
sbit R4 = P1^3;

// -------- COLUMN PINS -------- 
sbit C1 = P1^4;
sbit C2 = P1^5;
sbit C3 = P1^6;
sbit C4 = P1^7;

char keypad_scan(void);
void delay(unsigned int t);

char keypad_scan(void)
{
    // Row 1 
    R1=0; R2=R3=R4=1;
    if(C1==0)
		{ 
			while(C1==0); 
			return '7'; 
		}
    if(C2==0)
		{ 
			while(C2==0); 
			return '8'; 
		}
    if(C3==0)
		{ 
			while(C3==0); 
			return '9'; 
		}
    if(C4==0)
		{ 
			while(C4==0); 
			return '/'; 
		}

    // Row 2 
    R2=0; R1=R3=R4=1;
    if(C1==0)
		{ while(C1==0); 
			return '4'; 
		}
    if(C2==0)
		{ 
			while(C2==0);
			return '5'; 
		}
    if(C3==0)
		{ 
			while(C3==0); 
			return '6'; 
		}
    if(C4==0)
		{ 
			while(C4==0); 
			return 'x'; 
		}

    // Row 3 
    R3=0; R1=R2=R4=1;
    if(C1==0)
		{ 
			while(C1==0); 
			return '1'; 
		}
    if(C2==0)
		{ 
			while(C2==0); 
			return '2'; 
		}
    if(C3==0)
		{ 
			while(C3==0); 
			return '3';
		}
    if(C4==0)
		{ 
			while(C4==0); 
			return '-'; 
		}

    // Row 4 
    R4=0; R1=R2=R3=1;
    if(C1==0)
		{ 
			while(C1==0); 
			return '*'; 
		}
    if(C2==0)
		{ 
			while(C2==0); 
			return '0'; 
		}
    if(C3==0)
		{
			while(C3==0); 
			return '#'; 
		}
    if(C4==0)
		{ 
			while(C4==0); 
			return '+'; 
		}

		return 0;// No key pressed
}