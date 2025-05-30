#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>

unsigned char dato_recivir = 0;


void config_USART (void){

  UCSR0C |= (1 << UCSR0C)|( 1 << UCSZ00);
  UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0); 
  UBRR0 = 103;

}

void send_char(char c){

  while(!(UCSR0A &(1 << UDR30)));

  udr0 = c;
}
ISR(USART_RX_vect) {
    dato_recivir = UDR0 - '0';
    switch (dato_recivir) {
        case 3:
            PORTB |= 0x01;
            break;
        case 4:
            PORTB &= ~(0x03);
            break;
            }
}
int main (void){

  
}
          
