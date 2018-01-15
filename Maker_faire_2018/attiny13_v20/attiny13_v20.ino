/*
 * https://www.facebook.com/mcu4live
 * https://www.facebook.com/mcu4live/videos/pcb.1020493138090041/1020490501423638/?type=3&theater
 * 
 * https://github.com/lamloei/ArduinoIDE_1.6.x/Maker_faire_2018/attiny13_v20/attiny13_v20.ino
 * 
 */

#define swPin 0
volatile uint8_t mode, ledstep, chkbutton;
void readButton(void)
{
	int val;
	val = analogRead(swPin);
	if(val > 200 && val < 600) {
    chkbutton = 1;
	}
  if(chkbutton == 1 && val > 600) {
    chkbutton = 0;
		mode++;
		if(mode > 8) mode=0;
	}
}

void setup() {
	DDRB |= 0x1F;
	mode = 0;
  chkbutton = 0;
}

void loop()
{

	static uint32_t tms;
	
	readButton();
	
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

		if(mode == 6)
		{
			if(ledstep == 0) PORTB = 0b00000000;
			if(ledstep == 1) PORTB = 0b00011111;
			if(++ledstep > 1)ledstep=0;
		}

		if(mode == 7)
		{
			PORTB = 0b00000000;
		}

    if(mode == 8)
    {
      PORTB = 0b00011111;
    }
    
	}
}
