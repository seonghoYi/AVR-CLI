#include "uart.h"
#include "qbuffer.h"

#ifdef _USE_HW_UART

static bool is_open[UART_MAX_CH];

static qbuffer_t qbuffer[UART_MAX_CH];
static uint8_t rx_buf[512];
//static uint8_t rx_data[UART_MAX_CH];

UART_HandleTypeDef huart1;

bool uartInit(void)
{
	for (int i=0; i<UART_MAX_CH; i++)
	{
		is_open[i] = false;

	}

	return true;
}


bool uartOpen(uint8_t ch, uint32_t baud)
{
	bool ret = false;


	switch(ch)
	{
		case _DEF_UART0:
		huart1.USARTn				= USART0;
		huart1.Init.BaudRate		= baud;
		huart1.Init.StopBits		= UART_STOPBITS_1;
		huart1.Init.Parity			= UART_PARITY_NONE;
		huart1.Init.WordLength		= UART_WORDLENGTH_8B;
		huart1.Init.Mode			= UART_MODE_RX_TX;
		huart1.Init.OverSampling	= UART_OVERSAMPLING_8;

		qbufferCreate(&qbuffer[ch], rx_buf, 512);

		if (UART_Init(&huart1) != OK)
		{
			ret = false;
		}
		else
		{
			ret = true;
			is_open[ch] = true;
		}
		break;
	}
	return ret;
}

uint32_t uartAvailable(uint8_t ch)
{
	uint32_t ret = 0;

	switch(ch)
	{
		case _DEF_UART0:
		ret = qbufferAvailable(&qbuffer[ch]);
		break;
	}
	return ret;
}

uint8_t uartRead(uint8_t ch)
{
	uint8_t ret = 0;

	switch(ch)
	{
		case _DEF_UART0:
		qbufferRead(&qbuffer[ch], &ret, 1);
		break;
	}

	return ret;
}

uint32_t uartWrite(uint8_t ch, uint8_t *p_data, uint32_t length)
{
	uint32_t ret = 0;
	StatusTypeDef status;
	switch(ch)
	{
		case _DEF_UART0:
		status = UART_Transmit(&huart1, p_data, length, 100);
		if (status == OK)
		{
			ret = length;
		}
		break;
	}
	return ret;
}

uint32_t uartPrintf(uint8_t ch, char *fmt, ...)
{
	char buf[256];
	va_list args;
	int len;
	uint32_t ret;

	va_start(args, fmt);
	len = vsnprintf(buf, 256, fmt, args);

	ret = uartWrite(ch, (uint8_t *)buf, len);

	va_end(args);
	return ret;
}

uint32_t uartGetBaud(uint8_t ch)
{
	uint32_t baud = 0;
	switch(ch)
	{
		case _DEF_UART0:
		baud = huart1.Init.BaudRate;
		break;
	}
	return baud;
}

#endif