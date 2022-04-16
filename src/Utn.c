/*
 * Utn.c
 *
 *  Created on: 16 abr. 2022
 *      Author: PC
 */

#include <stdio.h>
#include <stdlib.h>
#include "Utn.h"

int utn_getNum(int* pResultado, char* mensaje, char* errorMensaje, int min, int max, int reintento)
{
	int retorno;
	int bufferInt;

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && errorMensaje != NULL && min <= max && reintento >= 0)
		{
			do
			{
				printf("%s", mensaje);
				scanf("%d", &bufferInt);

				if(bufferInt >= min && bufferInt <= max)
				{
					*pResultado = bufferInt;
					retorno = 0;
					break;

				}
				else
				{
					printf("%s\n", errorMensaje);
					reintento--;
				}
			}while(reintento >= 0);

		}

	return retorno;
}


int utn_getNumFlotante(float* pResultado, char* mensaje, char* errorMensaje, float min, float max, int reintento)
{
	int retorno;
	float bufferFloat;

	retorno = -1;

	if(pResultado != NULL && mensaje != NULL && errorMensaje != NULL && min <= max && reintento >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%f", &bufferFloat);

			if(bufferFloat >= min && bufferFloat <= max)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;

			}
			else
			{
				printf("%s\n", errorMensaje);
				reintento--;
			}
		}while(reintento >= 0);

	}
	return retorno;
}

