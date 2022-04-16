/*
 * Menu.c
 *
 *  Created on: 16 abr. 2022
 *      Author: PC
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Menu.h"
#include "Utn.h"
#include "Contable.h"


/**@brief Muestro un menu de opciones por pantalla y le doy al usuario la posibilidad de ingresar una opcion.
 *
 * @param kilometros Cantidad de kilometros ingresado por el usuario que se mostrara en pantalla
 * @param aerolineas Precio de Aerolineas ingresado por el usuario que se mostrara en pantalla
 * @param latam Precio de Latam ingresado por el usuario que se mostrara en pantalla
 * @return opcion Retorna un numero del 1 al 6 que sera la opcion ingresada
 */
int menu(float kilometros, float aerolineas, float latam)
{
	int opcion;

	system("cls");
	//Cuerpo del menu
	printf("------ AGENCIA DE VIAJES UTN ------ \n");
	printf("\n-- Menu de Opciones --\n\n");
	printf("1- Ingresar kilometros(Km = %.2f)\n", kilometros);
	printf("2- Ingresar precio de vuelos(Aerolineas = %.2f, Latam = %.2f)\n", aerolineas, latam);
	printf("3- Calcular todos los costos\n");
	printf("4- Informar resultado\n");
	printf("5- Carga forzada\n");
	printf("6- Salir\n");
	utn_getNum(&opcion, "\n-Ingrese opcion: ", "\nERROR. Opcion invalida. Debe ingresar una opcion valida (del 1 al 6)", 1, 6, 2);
	system("cls");

	return opcion;
}


/**@brief Funcion para ingresar los kilometros. Recibe la direccion de memoria de kilometros y pide al usuario
 * un valor que será pasado por referencia. Cuando finaliza, establece el flag de kilometros en 1.
 *
 * @param pKilometros Puntero a la variable donde se guardaran los kilometros
 * @param pFlag Puntero a la variable donde se guardara el flag
 */
void ingresarKM(float* pKilometros, int* pFlag)
{
	float kilometros;

	if(pKilometros != NULL && pFlag != NULL)
	{
		if(utn_getNumFlotante(&kilometros, "\n1- Ingresar kilometros: ", "\nERROR. Cantidad de kilometros invalida\n", 1, 99999, 2) == 0)
		{
			*pKilometros = kilometros;
			*pFlag = 1;
		}else
		{
			printf("\nERROR. No pudo ingresar kilometros valido. Regresando...\n");
		}

	}
}


/**@brief Funcion para ingresar los precios de las aerolineas. Recibe la direccion de memoria del precio de Aerolineas
 * y el de Latam, le pide un valor al usuario que pasara por referencia y establece el flag de precios en 1.
 *
 * @param pPrecioAerolineas
 * @param pPrecioLatam
 * @param pFlag
 */
void ingresarPrecio(float* pPrecioAerolineas, float* pPrecioLatam, int* pFlag)
{
	float aerolineas;
	float latam;

	if(pPrecioAerolineas != NULL && pPrecioLatam != NULL && pFlag != NULL)
	{
		printf("\n2- Ingresar precio de vuelos");
		if(utn_getNumFlotante(&aerolineas, "\n- Precio vuelo Aerolineas: ", "Error. Precio invalido\n", 1, 999999999999999, 2) == 0
		&& utn_getNumFlotante(&latam, "- Precio vuelo Latam: ", "\nERROR. Precio invalido\n", 1, 999999999999999, 2) == 0)
		{
			*pPrecioAerolineas = aerolineas;
			*pPrecioLatam = latam;
			*pFlag = 1;
		}else
		{
			printf("ERROR. No pudo ingresar precio valido. Regresando...\n");
		}
	}
}

 /**@brief Funcion para calcular todos los costos de las aerolineas. Recibe todos los parametros a calcular y los
  * guarda en auxiliares, los valida, luego llama a las funciones que realizaran los calculos pasandoles los
  * auxiliares, cuando tiene esos resultados los pasa por referencia a las variables del main y una vez finalizo
  * correctamente establece el flag a 1
  *
  * @param kilometros Pasa el valor que el usuario ingreso para los kilometros
  * @param aerolineas Pasa el valor que el usuario ingreso para el precio de vuelo en Aerolineas
  * @param latam Pasa el valor que el usuario ingreso para el precio de vuelo en Latam
  * @param pDebitoAerolineas Puntero a la variable que guardara el valor del precio con tarjeta de debito de Aerolineas
  * @param pDebitoLatam Puntero a la variable que guardara el valor del precio con tarjeta de debito de Latam
  * @param pCreditoAerolineas Puntero a la variable que guardara el valor del precio con tarjeta de credito de Aerolineas
  * @param pCreditoLatam Puntero a la variable que guardara el valor del precio con tarjeta de credito de Latam
  * @param pBitcoinAerolineas Puntero a la variable que guardara el valor del precio en bitcoin de Aerolineas
  * @param pBitcoinLatam Puntero a la variable que guardara el valor del precio en bitcoin de Latam
  * @param pUnitarioAerolineas Puntero a la variable que guardara el valor del precio unitario de Aerolineas
  * @param pUnitarioLatam Puntero a la variable que guardara el valor del precio unitario de Latam
  * @param pDiferencia Puntero a la variable que guardara el valor de la diferencia calculada
  * @return retorno Devuelve -1 si la validacion fallo o 0 si se pudo realizar los calculos
  */int calcularCosto(float kilometros, float aerolineas, float latam, float* pDebitoAerolineas, float* pDebitoLatam, float* pCreditoAerolineas, float* pCreditoLatam, float* pBitcoinAerolineas, float* pBitcoinLatam, float* pUnitarioAerolineas, float* pUnitarioLatam, float* pDiferencia)
 {
	int retorno;
 	float auxKilometros;
 	float auxAerolineas;
 	float auxLatam;
 	float auxDebitoAerolineas;
 	float auxDebitoLatam;
 	float auxCreditoAerolineas;
 	float auxCreditoLatam;
 	float auxAerolineasBTC;
 	float auxLatamBTC;
 	float auxUnitarioAerolineas;
 	float auxUnitarioLatam;
 	float auxDiferencia;


 	auxKilometros = kilometros;
 	auxAerolineas = aerolineas;
 	auxLatam = latam;
 	auxDebitoAerolineas = *pDebitoAerolineas;
 	auxDebitoLatam = *pDebitoLatam;
 	auxCreditoAerolineas = *pCreditoAerolineas;
 	auxCreditoLatam = *pCreditoLatam;
 	auxAerolineasBTC = *pBitcoinAerolineas;
 	auxLatamBTC = *pBitcoinLatam;
 	auxUnitarioAerolineas = *pUnitarioAerolineas;
 	auxUnitarioLatam = *pUnitarioLatam;
 	auxDiferencia = *pDiferencia;
 	retorno = -1;

 	if(kilometros > 0 && aerolineas > 0 && latam > 0 && pDebitoAerolineas != NULL && pDebitoLatam != NULL
 	&& pCreditoAerolineas != NULL && pCreditoLatam != NULL && pBitcoinAerolineas != NULL && pBitcoinLatam != NULL
 	&& pUnitarioAerolineas != NULL && pUnitarioLatam != NULL && pDiferencia != NULL)
 	{
 		if(calcularDebito(auxAerolineas, auxLatam, &auxDebitoAerolineas, &auxDebitoLatam) == 0
 		&& calcularCredito(auxAerolineas, auxLatam, &auxCreditoAerolineas, &auxCreditoLatam) == 0
 		&& calcularBitcoin(auxAerolineas, auxLatam, &auxAerolineasBTC, &auxLatamBTC) == 0
 		&& calcularPrecioUnitario(auxKilometros, auxAerolineas, auxLatam, &auxUnitarioAerolineas, &auxUnitarioLatam) == 0
 		&& calcularDiferencia(auxAerolineas, auxLatam, &auxDiferencia) == 0)
 		{
 			*pDebitoAerolineas = auxDebitoAerolineas;
 			*pDebitoLatam = auxDebitoLatam;
 			*pCreditoAerolineas = auxCreditoAerolineas;
 			*pCreditoLatam = auxCreditoLatam;
 			*pBitcoinAerolineas = auxAerolineasBTC;
 			*pBitcoinLatam = auxLatamBTC;
 			*pUnitarioAerolineas = auxUnitarioAerolineas;
 			*pUnitarioLatam = auxUnitarioLatam;
 			*pDiferencia = auxDiferencia;
 			retorno = 0;
 		}
 	}

 	return retorno;
 }

  /**@brief Muestra los resultados obtenidos de calcularCostos por pantalla
   *
   * @param aerolineas Recibe y muestra el valor que el usuario ingreso para el precio de vuelo en Aerolineas
   * @param latam Recibe y muestra el valor que el usuario ingreso para el precio de vuelo en Latam
   * @param debitoAerolineas Recibe y muestra el valor del precio con tarjeta de debito de Aerolineas
   * @param debitoLatam Recibe y muestra el valor del precio con tarjeta de debito de Latam
   * @param creditoAerolineas Recibe y muestra valor del precio con tarjeta de credito de Aerolineas
   * @param creditoLatam Recibe y muestra el valor del precio con tarjeta de credito de Latam
   * @param aerolineasBTC Recibe y muestra el valor del precio en Bitcoin de Aerolineas
   * @param latamBTC Recibe y muestra el valor del precio en Bitcoin de Latam
   * @param unitarioAerolineas Recibe y muestra el valor del precio unitario de Aerolineas
   * @param unitarioLatam Recibe y muestra el valor del precio unitario de Latam
   * @param diferencia Recibe y muestra la diferencia del valor en los precios de Aerolineas y Latam
   */void informarResultado(float aerolineas, float latam, float debitoAerolineas, float debitoLatam, float creditoAerolineas, float creditoLatam, float aerolineasBTC, float latamBTC, float unitarioAerolineas, float unitarioLatam, float diferencia)
  {

  	if(aerolineas > 0 && latam > 0 && debitoAerolineas > 0 && debitoLatam > 0
  	&& creditoAerolineas > 0 && creditoLatam > 0 && aerolineasBTC > 0 && latamBTC > 0 && unitarioAerolineas > 0
	&& unitarioLatam > 0 && diferencia >= 0)
  	{
  		printf("\nPrecio Aerolineas: $%.2f\n", aerolineas);
  		printf("a) Precio con tarjeta de debito: $%.2f\n", debitoAerolineas);
  		printf("b) Precio con tarjeta de credito: $%.2f\n", creditoAerolineas);
  		printf("c) Precio pagando con Bitcoin: %.2f BTC\n", aerolineasBTC);
  		printf("d) Precio unitario: $%.2f\n", unitarioAerolineas);
  		printf("\nPrecio Latam: $%.2f\n", latam);
  		printf("a) Precio con tarjeta de debito: $%.2f\n", debitoLatam);
  		printf("b) Precio con tarjeta de credito: %.2f\n", creditoLatam);
  		printf("c) Precio pagando con Bitcoin: %.2f BTC\n", latamBTC);
  		printf("d) Precio unitario: $%.2f\n", unitarioLatam);
  		printf("\nLa diferencia de precio es: $%.2f\n\n", diferencia);
  	}
  }

  /**@brief Crea sus propios valores para las variables de kilometros y precios, llama a la funcion para
   * calcular los costos y muestra el resultado por pantalla
   *
   * */void cargaForzadaDeDatos()
  {
  	float kilometrosForzado;
  	float precioAerolineasForzado;
  	float precioLatamForzado;
  	float precioDebitoAerolineasForzado;
  	float precioDebitoLatamForzado;
  	float precioCreditoAerolineasForzado;
  	float precioCreditoLatamForzado;
  	float precioAerolineasForzadoBTC;
  	float precioLatamForzadoBTC;
  	float precioUnitarioAerolineasForzado;
  	float precioUnitarioLatamForzado;
  	float diferenciaForzado;

  	kilometrosForzado = 7090;
  	precioAerolineasForzado = 162965;
  	precioLatamForzado = 159339;

  	if(calcularCosto(kilometrosForzado, precioAerolineasForzado, precioLatamForzado, &precioDebitoAerolineasForzado, &precioDebitoLatamForzado, &precioCreditoAerolineasForzado, &precioCreditoLatamForzado, &precioAerolineasForzadoBTC, &precioLatamForzadoBTC, &precioUnitarioAerolineasForzado, &precioUnitarioLatamForzado, &diferenciaForzado) == 0)
  	{}
  	informarResultado(precioAerolineasForzado, precioLatamForzado, precioDebitoAerolineasForzado, precioDebitoLatamForzado, precioCreditoAerolineasForzado, precioCreditoLatamForzado, precioAerolineasForzadoBTC, precioLatamForzadoBTC, precioUnitarioAerolineasForzado, precioUnitarioLatamForzado, diferenciaForzado);
  }

 /**@brief Pregunta al usuario si quiere cerrar el programa
  *
  * &param pSalir Recibe la direccion de memoria de la  variable que almacena la respuesta del usuario para salir
  */void confirmarSalida(char* pSalir)
 {
 	char confirma;

 	if(pSalir != NULL)
 	{

 		printf("6- Confirma salida? (s/n): ");
 		fflush(stdin);
 		scanf("%c", &confirma);
 		confirma = tolower(confirma);

 		while(confirma < 's' && confirma > 'n')
 		{
 			printf("Error, Opcion invalida\n6- Confirma salida? (s/n): ");
 			scanf("%c", &confirma);
 			confirma = tolower(confirma);
 		}
 		*pSalir = confirma;
 	}
 }

