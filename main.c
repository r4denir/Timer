#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t count;

void init_timer() {
   TCCR0|=(1<<CS02)|(1<<CS00);
   TIMSK|=(1<<TOIE0);
   TCNT0=0;
   count=0;
}

int main() {
   init_timer();

   DDRB |= 0x0F;
   sei();

   while(1);
}

ISR(TIMER0_OVF_vect)
{
   count++;
   if(count==10) {
      PORTB = ~PORTB;
      count = 0;
   }
}
