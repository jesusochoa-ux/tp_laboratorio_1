/*
 * Contable.h
 *
 *  Created on: 16 abr. 2022
 *      Author: PC
 */

#ifndef CONTABLE_H_
#define CONTABLE_H_

int calcularDebito(float aerolineas, float latam, float* pDebitoAerolineas, float* pDebitoLatam);
int calcularCredito(float aerolineas, float latam, float* pCreditoAerolineas, float* pCreditoLatam);
int calcularBitcoin(float aerolineas, float latam, float* pBitcoinAerolineas, float* pBitcoinLatam);
int calcularPrecioUnitario(float kilometros, float aerolineas, float latam, float* pUnitarioAerolineas, float* pUnitarioLatam);
int calcularDiferencia(float aerolineas, float latam, float* pDiferencia);

#endif /* CONTABLE_H_ */
