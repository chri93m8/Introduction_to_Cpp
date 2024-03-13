#include <stdint.h>
#define F_CPU 8000000UL
#define __AVR_ATmega32A__
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

uint8_t counter = 0;

int main(void) {
  DDRB = 0xff;                         // Config PortB as output
  GICR = (1 << INT0);                  // Enables INT0 interrupt
  MCUCR = (1 << ISC00) | (1 << ISC01); // Generates interrupt on rising edge
  sei();                               // Enables Global interrupt
  PORTB = 0b10100000;
  while (1) {
  }
}

ISR(INT0_vect) {
  counter++;
  _delay_ms(100);
  switch (counter % 10) {
  case 0: {
    PORTB = 0b10100000;
    break;
  }
  case 1: {
    PORTB = 0b11110011;
    break;
  }
  case 2: {
    PORTB = 0b10010100;
    break;
  }
  case 3: {
    PORTB = 0b10010001;
    break;
  }
  case 4: {
    PORTB = 0b11000011;
    break;
  }
  case 5: {
    PORTB = 0b10001001;
    break;
  }
  case 6: {
    PORTB = 0b00001000;
    break;
  }
  case 7: {
    PORTB = 0b10110011;
    break;
  }
  case 8: {
    PORTB = 0b10000000;
    break;
  }
  case 9: {
    PORTB = 0b00000001;
    break;
  }
  default:
    PORTB = 0b10100000;
  }
}
