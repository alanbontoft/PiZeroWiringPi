/*
 ============================================================================
 Name        : Wiring.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "wiringPi.h"
#include "wiringSerial.h"

int main(void)
{
	int ret = -1;
	int fd = -1;
	char ch = 'A';


	puts("!!!Wiring Pi Test!!!\n");

	ret = wiringPiSetup();

	if (ret != 0) return EXIT_FAILURE;

	fd = serialOpen("/dev/serial0", 9600);

	pinMode (0, OUTPUT) ;
	for (;;)
	{
		digitalWrite(0, HIGH);
		delayMicroseconds(100000);
		digitalWrite(0, LOW);
		delayMicroseconds(100000);

		serialPutchar(fd, ch++);
	}

	return EXIT_SUCCESS;
}
