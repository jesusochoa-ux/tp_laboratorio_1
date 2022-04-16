/*
 ============================================================================
 Name        : TP1.c
 Author      : Jesus ochoa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Utn.h"
#include "Menu.h"
#include "Contable.h"

int main()
{
	setbuf(stdout, NULL);

	int flagKilometros;
	int flagPrecio;
	int flagCalcular;
	float kilometros;
	float AerolineaPrecio;
	float LatamPrecio;
	float DebitoAerolineaPrecio;
	float DebitoLatamPrecio;
	float CreditoAerolineaPrecio;
	float CreditoLatamPrecio;
	float AerolineaBTCPrecio;
	float latamBTCPrecio;
	float AerolineaPrecioUnitario;
	float LatamPrecioUnitario;
	float diferencia;
	char salir;

	flagKilometros = 0;
	flagPrecio = 0;
	flagCalcular = 0;
	AerolineaPrecio = 0;
	LatamPrecio = 0;


	do
	{
		switch(menu(kilometros, AerolineaPrecio, LatamPrecio))
		{
			case 1:
				ingresarKM(&kilometros, &flagKilometros);
				system("pause");
				break;
			case 2:

				ingresarPrecio(&AerolineaPrecio, &LatamPrecio, &flagPrecio);
				system("pause");
				break;
			case 3:

				if(flagKilometros == 1 && flagPrecio == 1)
				{
					printf("\nCalculando costos... \n");
					if(calcularCosto(kilometros, AerolineaPrecio, LatamPrecio, &DebitoAerolineaPrecio, &DebitoLatamPrecio, &CreditoAerolineaPrecio, &CreditoLatamPrecio, &AerolineaBTCPrecio, &latamBTCPrecio, &AerolineaPrecioUnitario, &LatamPrecioUnitario, &diferencia) == 0)
					{
						printf("Se calculo exitosamente!\n");
					}else
					{
						printf("ERROR. No se pudo calcular los costos!\n");
					}
					system("pause");
					flagCalcular = 1;
				}else
				{
					printf("\nNo se pueden realizar los calculos sin haber ingresado todos los datos!\n");
					system("pause");
				}
				break;
			case 4:
				if(flagCalcular == 1)
				{
					printf("\nMostrando los costos...\n");
					informarResultado(AerolineaPrecio, LatamPrecio, DebitoAerolineaPrecio, DebitoLatamPrecio, CreditoAerolineaPrecio, CreditoLatamPrecio, AerolineaBTCPrecio, latamBTCPrecio, AerolineaPrecioUnitario, LatamPrecioUnitario, diferencia);
					system("pause");
				}else
				{
					printf("\nPara informar resultados primero se debe calcular los vuelos ingresados!\n");
					system("pause");
				}
				break;
			case 5:
				printf("\nForzando entrada de datos...\n");
				cargaForzadaDeDatos();
				system("pause");
				break;
			case 6:
				confirmarSalida(&salir);
				if(salir == 's')
				{
					printf("\nSaliendo...\n");
				}else if(salir == 'n')
				{
					printf("\nRegresando...\n");
				}
				break;
		}
	}while(salir != 's');


	return EXIT_SUCCESS;
}

