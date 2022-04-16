/*
 * Menu.h
 *
 *  Created on: 16 abr. 2022
 *      Author: PC
 */

#ifndef MENU_H_
#define MENU_H_


int menu(float kilometros, float aerolineas, float latam);
void ingresarKM(float* pKilometros, int* pFlag);
void ingresarPrecio(float* pPrecioAerolineas, float* pPrecioLatam, int* pFlag);
int calcularCosto(float kilometros, float aerolineas, float latam, float* pDebitoAerolineas, float* pDebitoLatam, float* pCreditoAerolineas, float* pCreditoLatam, float* pBitcoinAerolineas, float* pBitcoinLatam, float* pUnitarioAerolineas, float* pUnitarioLatam, float* pDiferencia);
void informarResultado(float aerolineas, float latam, float debitoAerolineas, float debitoLatam, float creditoAerolineas, float creditoLatam, float aerolineasBTC, float latamBTC, float unitarioAerolineas, float unitarioLatam, float diferencia);
void cargaForzadaDeDatos();
void confirmarSalida(char* pSalir);


#endif /* MENU_H_ */
