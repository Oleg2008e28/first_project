/*
 * _12864B_v.c
 *
 * Created: 22.12.2020 11:47:46
 *  Author: User-HP
 */ 

#include <avr/io.h>
#include "main_config.h"
#include <util/delay.h>
#include <string.h>
#include <avr/pgmspace.h>

#include "Dis12864BV20.h"


int main(void)
{

initDisplay();
_delay_ms(2000);
setDisplayExtendedFunction(1,1,1);
selectDisplayScroollOrRamAddress(0);
clearDisplayGraphicMode();

_delay_ms(10);

int i=0;

while(1)
{
	
unsigned char a0[]={"  <ÍÀÑÒÐÎÉÊÈ>\0"};
unsigned char a1[]={"Äàòà/Âðåìÿ\0"};
unsigned char a2[]={"Ïîëèâ\0"};
unsigned char a3[]={"Îòêð./Çàêð.\0"};						//Òâ=+25°
printDisplayString(a0,0,0);
if (i==0)
{
	printDisplayString(a1,1,1);
	printDisplayString(a2,2,0);
	printDisplayString(a3,3,0);
}
if (i==1)
{
	printDisplayString(a1,1,0);
	printDisplayString(a2,2,1);
	printDisplayString(a3,3,0);
}
if (i==2)
{
	printDisplayString(a1,1,0);
	printDisplayString(a2,2,0);
	printDisplayString(a3,3,1);
}
i++;
if (i>2)
{
	i=0;
}
_delay_ms(5000);




	
}
	


}
