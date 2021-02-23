#include "atmega128_DRV.h"

#ifdef DRV_GPIO_MODULE_ENABLED

void gpioInit(uint8_t port, GPIO_InitTypeDef *GPIO_Init)
{
	switch(port)
	{
		case GPIOA:
			if(GPIO_Init->Mode == GPIO_MODE_INPUT)
			{
				CLRB(DDRA, GPIO_Init->Pin);
			}
			else if(GPIO_Init->Mode == GPIO_MODE_OUTPUT)
			{
				SETB(DDRA, GPIO_Init->Pin);
			}
			break;
		case GPIOB:
			if(GPIO_Init->Mode == GPIO_MODE_INPUT)
			{
				CLRB(DDRB, GPIO_Init->Pin);
			}
			else if(GPIO_Init->Mode == GPIO_MODE_OUTPUT)
			{
				SETB(DDRB, GPIO_Init->Pin);
			}
			break;
		case GPIOC:
			if(GPIO_Init->Mode == GPIO_MODE_INPUT)
			{
				CLRB(DDRC, GPIO_Init->Pin);
			}
			else if(GPIO_Init->Mode == GPIO_MODE_OUTPUT)
			{
				SETB(DDRC, GPIO_Init->Pin);
			}
			break;
		case GPIOD:
			if(GPIO_Init->Mode == GPIO_MODE_INPUT)
			{
				CLRB(DDRD, GPIO_Init->Pin);
			}
			else if(GPIO_Init->Mode == GPIO_MODE_OUTPUT)
			{
				SETB(DDRD, GPIO_Init->Pin);
			}
			break;
		case GPIOE:
			if(GPIO_Init->Mode == GPIO_MODE_INPUT)
			{
				CLRB(DDRE, GPIO_Init->Pin);
			}
			else if(GPIO_Init->Mode == GPIO_MODE_OUTPUT)
			{
				SETB(DDRE, GPIO_Init->Pin);
			}
			break;
		case GPIOF:
			if(GPIO_Init->Mode == GPIO_MODE_INPUT)
			{
				CLRB(DDRF, GPIO_Init->Pin);
			}
			else if(GPIO_Init->Mode == GPIO_MODE_OUTPUT)
			{
				SETB(DDRF, GPIO_Init->Pin);
			}
			break;
		case GPIOG:
			if(GPIO_Init->Mode == GPIO_MODE_INPUT)
			{
				CLRB(DDRG, GPIO_Init->Pin);
			}
			else if(GPIO_Init->Mode == GPIO_MODE_OUTPUT)
			{
				SETB(DDRG, GPIO_Init->Pin);
			}
			break;
		default:
			break;
	}

}

GPIO_PinState gpioReadPin(uint8_t port, uint8_t pin)
{
	GPIO_PinState ret = 0x00;
	
	switch(port)
	{
		case GPIOA:
			ret = READB(PINA, pin);
		break;
		case GPIOB:
			ret = READB(PINB, pin);
		break;
		case GPIOC:
			ret = READB(PINC, pin);
		break;
		case GPIOD:
			ret = READB(PIND, pin);
		break;
		case GPIOE:
			ret = READB(PINE, pin);
		break;
		case GPIOF:
			ret = READB(PINF, pin);
		break;
		case GPIOG:
			ret = READB(PING, pin);
		break;
		default:
		break;
	}
	return ret;
}

void gpioWritePin(uint8_t port, uint8_t pin, GPIO_PinState pinState)
{
	switch(port)
	{
		case GPIOA:
			if(pinState == PIN_RESET)
			{
				CLRB(PORTA, pin);
			}
			else if(pinState == PIN_SET)
			{
				SETB(PORTA, pin);	
			}
		break;
		case GPIOB:
			if(pinState == PIN_RESET)
			{
				CLRB(PORTB, pin);
			}
			else if(pinState == PIN_SET)
			{
				SETB(PORTB, pin);
			}
		break;
		case GPIOC:
			if(pinState == PIN_RESET)
			{
				CLRB(PORTC, pin);
			}
			else if(pinState == PIN_SET)
			{
				SETB(PORTC, pin);
			}
		break;
		case GPIOD:
			if(pinState == PIN_RESET)
			{
				CLRB(PORTD, pin);
			}
			else if(pinState == PIN_SET)
			{
				SETB(PORTD, pin);
			}
		break;
		case GPIOE:
			if(pinState == PIN_RESET)
			{
				CLRB(PORTE, pin);
			}
			else if(pinState == PIN_SET)
			{
				SETB(PORTE, pin);
			}
		break;
		case GPIOF:
			if(pinState == PIN_RESET)
			{
				CLRB(PORTF, pin);
			}
			else if(pinState == PIN_SET)
			{
				SETB(PORTF, pin);
			}
		break;
		case GPIOG:
			if(pinState == PIN_RESET)
			{
				CLRB(PORTG, pin);
			}
			else if(pinState == PIN_SET)
			{
				SETB(PORTG, pin);
			}
		break;
		default:
		break;
	}
}

void gpioTogglePin(uint8_t port, uint8_t pin)
{
	switch(port)
	{
		case GPIOA:
			TGLB(PORTA, pin);
		break;
		case GPIOB:
			TGLB(PORTB, pin);
		break;
		case GPIOC:
			TGLB(PORTC, pin);
		break;
		case GPIOD:
			TGLB(PORTD, pin);
		break;
		case GPIOE:
			TGLB(PORTE, pin);
		break;
		case GPIOF:
			TGLB(PORTF, pin);
		break;
		case GPIOG:
			TGLB(PORTG, pin);
		break;
		default:
		break;
	}
}


#endif