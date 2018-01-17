/*
 * https://www.facebook.com/mcu4live
 * https://www.facebook.com/mcu4live/videos/pcb.1020493138090041/1020490501423638/?type=3&theater
 * 
 * https://github.com/lamloei/ArduinoIDE_1.6.x/Maker_faire_2018/attiny13_v10_russian_roulette/attiny13_v10_russian_roulette.ino
 * 
 */

void roulette(int i) {
  if(i%5 == 0) PORTB = ~0b00000001;
  if(i%5 == 1) PORTB = ~0b00000010;
  if(i%5 == 2) PORTB = ~0b00000100;
  if(i%5 == 3) PORTB = ~0b00001000;
  if(i%5 == 4) PORTB = ~0b00010000;
  delay(50);
}

void setup(){
  DDRB |= 0x1F;
}

void loop() {
  int i,randNumber;

  randomSeed(analogRead(5));
  randNumber = random(30, 300);
  for(i=randNumber; i>0; i--) {
    roulette(i);
  }
  for(i=randNumber; i>0; i--) {
    roulette(randNumber);
    PORTB = ~0b00000000;
    delay(50);
  }
}

