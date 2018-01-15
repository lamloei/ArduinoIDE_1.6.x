/*
 * https://www.facebook.com/mcu4live
 * https://www.facebook.com/mcu4live/videos/pcb.1020493138090041/1020490501423638/?type=3&theater
 * 
 * https://github.com/lamloei/ArduinoIDE_1.6.x/Maker_faire_2018/attiny13_v10/attiny13_v10.ino
 * 
 */

#include <EEPROM.h>

volatile uint8_t mode, ledstep;
void readButton(void)
{
	EEPROM.get(0, mode);
	if(mode>7) mode=0;
	EEPROM.put(0, mode+1);
}

void setup() {
	DDRB |= 0x1F;
	mode = 0;
	readButton();
}

void loop()
{
	static uint32_t tms;
	
	if(millis() - tms >= 100)
	{
		tms = millis();
		if(mode == 0)
		{
			if(ledstep == 0) PORTB = ~0b00000001;
			if(ledstep == 1) PORTB = ~0b00000010;
			if(ledstep == 2) PORTB = ~0b00000100;
			if(ledstep == 3) PORTB = ~0b00001000;
			if(ledstep == 4) PORTB = ~0b00010000;
			if(++ledstep > 4)ledstep=0;
		}

		if(mode == 1)
		{
			if(ledstep == 0) PORTB = ~0b00010000;
			if(ledstep == 1) PORTB = ~0b00001000;
			if(ledstep == 2) PORTB = ~0b00000100;
			if(ledstep == 3) PORTB = ~0b00000010;
			if(ledstep == 4) PORTB = ~0b00000001;
			if(++ledstep > 4)ledstep=0;
		}
		
		if(mode == 2)
		{
			if(ledstep == 0) PORTB = ~0b00000001;
			if(ledstep == 1) PORTB = ~0b00010000;
			if(ledstep == 2) PORTB = ~0b00000010;
			if(ledstep == 3) PORTB = ~0b00001000;
			if(ledstep == 4) PORTB = ~0b00000100;
			if(++ledstep > 4)ledstep=0;
		}
		
		if(mode == 3)
		{
			if(ledstep == 0) PORTB = 0b00010000;
			if(ledstep == 1) PORTB = 0b00001000;
			if(ledstep == 2) PORTB = 0b00000100;
			if(ledstep == 3) PORTB = 0b00000010;
			if(ledstep == 4) PORTB = 0b00000001;
			if(ledstep == 5) PORTB = 0b00000010;
			if(ledstep == 6) PORTB = 0b00000100;
			if(ledstep == 7) PORTB = 0b00001000;
			if(++ledstep > 7)ledstep=0;
		}
		
		if(mode == 4)
		{
			if(ledstep == 0) PORTB = ~0b00010000;
			if(ledstep == 1) PORTB = ~0b00001000;
			if(ledstep == 2) PORTB = ~0b00000100;
			if(ledstep == 3) PORTB = ~0b00000010;
			if(ledstep == 4) PORTB = ~0b00000001;
			if(ledstep == 5) PORTB = ~0b00000010;
			if(ledstep == 6) PORTB = ~0b00000100;
			if(ledstep == 7) PORTB = ~0b00001000;
			if(++ledstep > 7)ledstep=0;
		}
		
		if(mode == 5)
		{
			if(ledstep == 0) PORTB = ~0b00000001;
			if(ledstep == 1) PORTB = ~0b00010010;
			if(ledstep == 2) PORTB = ~0b00001100;
			if(ledstep == 3) PORTB = ~0b00000000;
			if(ledstep == 4) PORTB = ~0b00001100;
			if(ledstep == 5) PORTB = ~0b00010010;
			if(ledstep == 6) PORTB = ~0b00000001;
			if(ledstep == 7) PORTB = ~0b00000000;
			if(++ledstep > 7)ledstep=0;
		}
/*
		if(mode == 6)
		{
			if(ledstep == 0) PORTB = 0b00000000;
			if(ledstep == 1) PORTB = 0b00011111;
			if(++ledstep > 1)ledstep=0;
		}
*/
		if(mode == 6)
		{
			PORTB = 0b00000000;
		}

    if(mode == 7)
    {
      PORTB = 0b00011111;
    }
    
	}
}
