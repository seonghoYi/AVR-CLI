#include "atmega128_DRV.h"

#ifdef DRV_UART_MODULE_ENABLED

USART_TypeDef USART0_descripter = {&UDR0, &UCSR0A, &UCSR0B, &UCSR0C, &UBRR0H, &UBRR0L};
USART_TypeDef USART1_descripter = {&UDR1, &UCSR1A, &UCSR1B, &UCSR1C, &UBRR1H, &UBRR1L};




StatusTypeDef UART0_Init(UART_HandleTypeDef *huart)
{
	uint32_t temp;
	if (huart == NULL)
	{
		return ERROR;
	}
	
	switch(huart->Init.OverSampling)
	{
		case UART_OVERSAMPLING_8:
		temp = (F_CPU / (16 * huart->Init.BaudRate)) - 1;
		UBRR0H = (temp >> 8) & 0xFF;
		UBRR0L = temp & 0xFF;
		CLRB(UCSR0A, 1);
		break;
		case UART_OVERSAMPLING_16:
		temp = (F_CPU / (8 * huart->Init.BaudRate)) - 1;
		UBRR0H = (temp >> 8) & 0xFF;
		UBRR0L = temp & 0xFF;
		SETB(UCSR0A, 1);
		break;
		default:
		break;
	}
	
	switch(huart->Init.WordLength)
	{
		case UART_WORDLENGTH_8B:
		CLRB(UCSR0B, 2);
		SETB(UCSR0C, 2);
		SETB(UCSR0C, 1);
		break;
		case UART_WORDLENGTH_5B:
		CLRB(UCSR0B, 2);
		CLRB(UCSR0C, 2);
		CLRB(UCSR0C, 1);
		break;
		case UART_WORDLENGTH_6B:
		CLRB(UCSR0B, 2);
		CLRB(UCSR0C, 2);
		SETB(UCSR0C, 1);
		break;
		case UART_WORDLENGTH_7B:
		CLRB(UCSR0B, 2);
		SETB(UCSR0C, 2);
		CLRB(UCSR0C, 1);
		break;
		case UART_WORDLENGTH_9B:
		SETB(UCSR0B, 2);
		SETB(UCSR0C, 2);
		SETB(UCSR0C, 1);
		break;
		default:
		break;
	}
	
	switch(huart->Init.StopBits)
	{
		case UART_STOPBITS_1:
		CLRB(UCSR0C, 4);
		break;
		case UART_STOPBITS_2:
		SETB(UCSR0C, 4);
		break;
	}
	
	switch(huart->Init.Parity)
	{
		case UART_PARITY_NONE:
		CLRB(UCSR0C, 6);
		CLRB(UCSR0C, 5);
		break;
		case UART_PARITY_EVEN:
		SETB(UCSR0C, 6);
		CLRB(UCSR0C, 5);
		break;
		case  UART_PARITY_ODD:
		SETB(UCSR0C, 6);
		SETB(UCSR0C, 5);
		break;
		default:
		break;
	}
	
	
	return OK;
}

StatusTypeDef UART1_Init(UART_HandleTypeDef *huart)
{
	uint32_t temp;
	if (huart == NULL)
	{
		return ERROR;
	}
	
	switch(huart->Init.OverSampling)
	{
		case UART_OVERSAMPLING_8:
		temp = (F_CPU / (16 * huart->Init.BaudRate)) - 1;
		UBRR1H = (temp >> 8) & 0xFF;
		UBRR1L = temp & 0xFF;
		CLRB(UCSR1A, 1);
		break;
		case UART_OVERSAMPLING_16:
		temp = (F_CPU / (8 * huart->Init.BaudRate)) - 1;
		UBRR1H = (temp >> 8) & 0xFF;
		UBRR1L = temp & 0xFF;
		SETB(UCSR1A, 1);
		break;
		default:
		break;
	}
	
	switch(huart->Init.WordLength)
	{
		case UART_WORDLENGTH_8B:
		CLRB(UCSR1B, 2);
		SETB(UCSR1C, 2);
		SETB(UCSR1C, 1);
		break;
		case UART_WORDLENGTH_5B:
		CLRB(UCSR1B, 2);
		CLRB(UCSR1C, 2);
		CLRB(UCSR1C, 1);
		break;
		case UART_WORDLENGTH_6B:
		CLRB(UCSR1B, 2);
		CLRB(UCSR1C, 2);
		SETB(UCSR1C, 1);
		break;
		case UART_WORDLENGTH_7B:
		CLRB(UCSR1B, 2);
		SETB(UCSR1C, 2);
		CLRB(UCSR1C, 1);
		break;
		case UART_WORDLENGTH_9B:
		SETB(UCSR1B, 2);
		SETB(UCSR1C, 2);
		SETB(UCSR1C, 1);
		break;
		default:
		break;
	}
	
	switch(huart->Init.StopBits)
	{
		case UART_STOPBITS_1:
		CLRB(UCSR1C, 4);
		break;
		case UART_STOPBITS_2:
		SETB(UCSR1C, 4);
		break;
	}
	
	switch(huart->Init.Parity)
	{
		case UART_PARITY_NONE:
		CLRB(UCSR1C, 6);
		CLRB(UCSR1C, 5);
		break;
		case UART_PARITY_EVEN:
		SETB(UCSR1C, 6);
		CLRB(UCSR1C, 5);
		break;
		case  UART_PARITY_ODD:
		SETB(UCSR1C, 6);
		SETB(UCSR1C, 5);
		break;
		default:
		break;
	}
	
	
	return OK;
}



StatusTypeDef UART_Init(UART_HandleTypeDef *huart)
{
	switch(huart->USARTn)
	{
		case USART0:
			UART0_Init(huart);
		break;
		case USART1:
			UART1_Init(huart);
		break;
		default:
		break;
	}
	return OK;
}

StatusTypeDef UART_Transmit(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
	uint8_t		*pdata8bits = NULL;
	uint16_t	*pdata16bits = NULL;

	
	huart->ErrorCode = UART_ERROR_NONE;
	
	huart->TxXferSize = Size;
	huart->TxXferCount = Size;
	
	if (huart->Init.WordLength == UART_WORDLENGTH_9B && huart->Init.Parity == UART_PARITY_NONE)
	{
		pdata8bits = NULL;
		pdata16bits = (uint16_t *) pData;
	}
	else
	{
		pdata8bits = pData;
		pdata16bits = NULL;
	}
	
	switch(huart->USARTn)
	{
		case USART0:
		for(int i = 0; i < huart->TxXferCount; i++)
		{
			while (!(UCSR0A & 0x20));
			if (pdata16bits == NULL)
			{
				UDR0 = *(pdata8bits + i);
			}
			else
			{
				UDR0 = *(pdata16bits + i);
			}
			
		}
		break;
		case USART1:
		for(int i = 0; i < huart->TxXferCount; i++)
		{
			while (!(UCSR1A & 0x20));
			if (pdata16bits == NULL)
			{
				UDR1 = *(pdata8bits + i);
			}
			else
			{
				UDR1 = *(pdata16bits + i);
			}

		}
		break;
		default:
		break;
	}
	
	
	return OK;
}

StatusTypeDef UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
	uint8_t		*pdata8bits = NULL;
	uint16_t	*pdata16bits = NULL;

	
	huart->ErrorCode = UART_ERROR_NONE;
	
	huart->RxXferSize = Size;
	huart->RxXferCount = Size;
	
	if (huart->Init.WordLength == UART_WORDLENGTH_9B && huart->Init.Parity == UART_PARITY_NONE)
	{
		pdata8bits = NULL;
		pdata16bits = (uint16_t *) pData;
	}
	else
	{
		pdata8bits = pData;
		pdata16bits = NULL;
	}
	
	switch(huart->USARTn)
	{
		case USART0:
		for(int i = 0; i < huart->TxXferCount; i++)
		{
			while (!(UCSR0A & 0x80))
			{
				if (pdata16bits == NULL)
				{
					*(pdata8bits + i) = UDR0;
				}
				else
				{
					*(pdata16bits + i) = UDR0;
				}
			}
		}
		break;
		case USART1:
		for(int i = 0; i < huart->TxXferCount; i++)
		{
			while (!(UCSR1A & 0x80))
			{
				if (pdata16bits == NULL)
				{
					*(pdata8bits + i) = UDR1;
				}
				else
				{
					*(pdata16bits + i) = UDR1;
				}
			}
		}
		break;
		default:
		break;
	}

	return OK;
}




















#endif