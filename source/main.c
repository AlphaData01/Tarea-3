//Enceder y Apagar un led
//#include <stdio.h>
#include <stdint.h>
#include <MK64F12.h>


int main(void){
	//Registros internos
	SIM->SCGC5 = 0x00000400; //clock puerto B
	PORTB->PCR[22] = 0x00000100; //Define como GPIO
	GPIOB->PDOR = 0x00400000; //Pone un 1 en el pin 22 (valor seguro)
	GPIOB->PDDR = 0x00400000; //Pone el pin 22 como salida

	//Lazo infinito
	while(1){
		GPIOB->PDOR = 0;
		//printf("RED LED ON\n");

		GPIOB->PDOR = 0x00400000;
		GPIOB->PDOR = 0x00000000;
		GPIOB->PDOR = 0x00400000;

		//printf("RED LED OFF\n");
	}
	return 0;
}
