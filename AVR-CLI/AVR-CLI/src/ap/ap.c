#include "ap.h"

void apInit(void)
{
	uartOpen(_DEF_UART0, 115200);
}


void apMain(void)
{
	char *str = "Hello, World!";

	while(true)
	{
		
		gpioPinToggle(_DEF_GPIO0);
		_delay_ms(500);
		
		
		uartPrintf(_DEF_UART0, "uart0 : %s\n", str);
		//gpioPinToggle(_DEF_GPIO0);
		
	}
}