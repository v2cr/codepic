#include <16F628A.h>
#FUSES  XT,NOWDT,NOPROTECT
#use delay(clock=4000000)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#BYTE TRISA=0x85
#BYTE PORTA=0x05
#BYTE TRISB=0X86
#BYTE PORTB=0X06
#use rs232(baud=9600,xmit=PIN_B2,rcv=PIN_B1,bits=8,parity=N)
#include <input.c>

//char string[4];
char string[1];
//char *cad1;

//int valor;
//int8 temp1;
#int_rda
void serial_isr()
{

gets(string);
delay_ms(5);

return;
}

void main()
{
enable_interrupts(global);
enable_interrupts(int_rda);

for(;;)
{
bit_clear(TRISB,3);
bit_clear(PORTB,3);
puts("i");
delay_ms(100);
//ordenes de on/off de luces
//led1
if(string[0]=='1')
{
bit_clear(TRISA,1);
bit_clear(PORTA,1);
//puts("0n");
}
if(string[0]=='2')
{
bit_set(TRISA,1);
bit_set(PORTA,1);
//puts("off");
}

//led2
if(string[0]=='3')
{
bit_clear(TRISA,2);
bit_clear(PORTA,2);
//puts("0n");
}
if(string[0]=='4')
{
bit_set(TRISA,2);
bit_set(PORTA,2);
//puts("off");
}
//led3
if(string[0]=='5')
{
bit_clear(TRISA,3);
bit_clear(PORTA,3);
//puts("0n");
}
if(string[0]=='6')
{
bit_set(TRISA,3);
bit_set(PORTA,3);
//puts("off");
}
//led4
if(string[0]=='7')
{
bit_clear(TRISA,4);
bit_clear(PORTA,4);
//puts("0n");
}
if(string[0]=='8')
{
bit_set(TRISA,4);
bit_set(PORTA,4);
//puts("off");
}
//led5
if(string[0]=='9')
{
bit_clear(TRISB,5);
bit_clear(PORTB,5);
//puts("0n");
}
if(string[0]=='A')
{
bit_set(TRISB,5);
bit_set(PORTB,5);
//puts("off");
}
//led6
if(string[0]=='B')
{
bit_clear(TRISB,6);
bit_clear(PORTB,6);
//puts("0n");
}
if(string[0]=='C')
{
bit_set(TRISB,6);
bit_set(PORTB,6);
//puts("off");
}
//led7
if(string[0]=='D')
{
bit_clear(TRISB,7);
bit_clear(PORTB,7);
//puts("0n");
}
if(string[0]=='E')
{
bit_set(TRISB,7);
bit_set(PORTB,7);
//puts("off");
}
//led8
if(string[0]=='F')
{
bit_clear(TRISB,4);
bit_clear(PORTB,4);
//puts("0n");
}
if(string[0]=='G')
{
bit_set(TRISB,4);
bit_set(PORTB,4);
//puts("off");
}

//ordenes
bit_set(PORTB,3);
puts("F");
delay_ms(100);
}
}
