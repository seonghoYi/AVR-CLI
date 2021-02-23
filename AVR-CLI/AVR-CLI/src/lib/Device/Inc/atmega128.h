#ifndef ATMEGA128_H_
#define ATMEGA128_H_

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>

#define SETB(PORT, BIT)		(PORT |= (1 << BIT))
#define CLRB(PORT, BIT)		(PORT &= ~(1 << BIT))
#define READB(PORT, BIT)	(PORT & (1 << BIT))
#define TGLB(PORT, BIT)		(PORT ^= (1 << BIT)) // toggle


#define GPIOA 0
#define GPIOB 1
#define GPIOC 2
#define GPIOD 3
#define GPIOE 4
#define GPIOF 5
#define GPIOG 6



#endif /* ATMEGA128_H_ */