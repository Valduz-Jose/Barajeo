#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <ctype.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int contador=0,vueltas=0,numero=0,mitad=0,pares=0,inpares=0,cuentamitad=0,posicion1=0,posicion2=0;
	float vuelta=0;//lo uso para cachar el error con los inpares y redondear mas tarde
	string * A ,* B, * C;//creo los vectores de palabras donde A sera la primera mitad de cartas, B la segunda mitad de cartas y C todas las cartas barajeadas

	string nombreArchivo = "barajeo.in";
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    // Obtener línea de archivo, y almacenar contenido en "linea"
 
    while (getline(archivo, linea)) {
    	
    	//contador = 0 numero de vueltas , contador = 1 vacio, contador>2 numeros a guardar
        if(contador==0){
        	vuelta= stoi(linea);//obtengo la cantidad de cartas a barajear
        	vueltas=vuelta;
			mitad= ceil(vuelta/2);
        	
        	A = new string [mitad];//les doy tamaño a los vectores
        	B = new string [mitad];
        	//cout<<"Cartas a Barajear "<<vueltas<<" la mitad es: "<<mitad<<endl;
		}
        if(contador>=2){
        	//numero= stoi(linea);//stoi convierte la cadena en número
        	if(cuentamitad<mitad){//esta condicion me ayuda a guardarlo en pares e inpares segun la posicion
        		B[inpares]=linea;
        		inpares++;//me ayuda a recorrer uno a uno el vector	
			}else{
				A[pares]=linea;//cargo el vector
				pares++;
			}
			cuentamitad++;
		}
		
		contador++;//aqui lleva el numero de linea contado
	}
	
	C =new string [vueltas];
/*	for(int i=0;i<vueltas;i++){
		C[i]=0;//para evitar errores
	}*/
	for(int i=0;i<vueltas;i++){
		
		if(i%2){//si van del cero a la mita
			C[i]=A[posicion1];
			posicion1++;		
		}else{//si van de la mitad en adelante
			C[i]=B[posicion2];
			posicion2++;	
		}
		cout<<C[i]<<endl;
	}
	return 0;
}
/*
Universidad Nacional Experimental del Táchira
José Alejandro Valduz Contreras
Programación 2
Profesor Marcel Molina
Practica 1

Problema 1: Barajeo perfecto
Cuando se barajea un mazo de cartas, se toma el mazo completo y se divide en dos,
posteriormente se juntan los dos montones en un nuevo mazo poniendo una carta del primer
montón, y una carta del segundo, y así posteriormente hasta que no quede ninguna carta en
ninguno de los montones. Cuando se "barajean" datos se hace de la misma forma, se toma
la lista de datos y se divide en dos, posteriormente se juntan de nuevo pero poniendo el
primer dato de la primera mitad y luego el primer dato de la segunda, y así hasta terminar
los datos en las dos mitades.
Entrada (barajeo.in): cantidad de números, números
Salida (pantalla): números barajeados.

Desarrolle dos versiones del codigo, pero en la primera convertia todas las lineas a numero con stoi
pero al colocar una letra me enviaria todo a error asi que preferi trabajar on la cadena completa y asi no importara cual carta use letra o numero la barajeara
para probar la funcionalidad puede alternar entre los documentos "barajeo.in" y "barajeo2.in"*/
