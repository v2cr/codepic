#include <16F877A.h>
#FUSES  XT,NOWDT,NOPROTECT
#use delay(clock=4000000)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <lcd420.c>
#include <ds1307.c>
#BYTE TRISA=0x85
#BYTE PORTA=0x05
#BYTE TRISB=0X86
#BYTE PORTB=0X06
#use rs232(baud=9600,xmit=PIN_C6,rcv=PIN_C7,bits=8,parity=N)
#include <input.c>
#include "DTH11.c"
void setup();


void main()
{

   unsigned char state = 0;
   bit_clear(TRISB,5);
   bit_clear(PORTB,5);
   setup();
   //while(TRUE)
for(;;)
{

state = get_data();
    switch(state)
      {
            case 1:
            {
            puts("1");
            delay_ms(100);
            break;
            }
            case 2:
            {
               puts("2");
               //lcd_putc("\fNo Sensor Found!");
               delay_ms(100);
               break;
            }
            case 3:
            {
             puts("3");
             delay_ms(100);
             // lcd_putc("\fChecksum Error!");
               break;
            }
            default:
            {  bit_clear(TRISB,3);
               bit_clear(PORTB,3);
               puts("");
              printf("R.H:");
              printf("%3u",values[0]);
              printf(".");
              printf("%03u",values[1]);
              printf("/");
              printf("T:");
              printf("%3u",values[2]);
              printf(".");
              printf("%03u",values[3]);
              printf("C");



                //puts(values[1]);
                // puts(values[2]);
                 // puts(values[3]);
               delay_ms(100);
               bit_set(TRISB,3);
              
               delay_ms(100);
               break;
            }
      }



   };
bit_set(PORTB,5);
delay_ms(100);

}


void setup()
{
   //disable_interrupts(global);
   //port_B_pullups(FALSE);
   //setup_timer_0(T0_internal | T0_8_bit);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_2);
   set_timer0(0);
   DHT11_init();
}


//codigo





