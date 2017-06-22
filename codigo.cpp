#include <iostream>
#include <cstring>
using namespace std;

int longitud(char cadena[30]){
	int i = 0;
	int contador = 0;
	while(cadena[i] != '\0'){
		contador++;
		i++;
	}
	return contador;
}



int main() {
	
	char cadenaA[30], cadenaB[30], cadenaC[30];
	int sizeA, sizeB, sizeC;
	int i , j, contador;
	int indicesPalabrasEncontradas[10][10], indiceX, indiceY, nroIndices;
	int indiceInicio;
	bool bandInicio;
	int arregloIndicesParaNuevaPalabra[10];
	bool bandCaracterValido;
	string cadenaFinal = "";
	string cadenaAux = "";
	int indicesNuevaCadena[10];
	int sizeCadenaFinal;
	bool bandReemplazo;
	
	cout<<"Ingrese Cadena A : ";
	cin>>cadenaA;
	cout<<"Ingrese Cadena B : ";
	cin>>cadenaB;
	cout<<"Ingrese Cadena C : ";
	cin>>cadenaC;
	

	sizeA = longitud(cadenaA);
	sizeB = longitud(cadenaB);
	sizeC = longitud(cadenaC);
	
	
	if(sizeB > sizeA){
		cout<<"El tamaño de la cadena A debe ser mas grande que la cadena B";
		return 0;
	}
	
	
	j = 0;
	contador = 0;
	indiceInicio = -1;
	bandInicio = false;
	indiceX = 0;
	indiceY = 0;
	nroIndices = 0;
	
	for(i = 0; i < sizeA ; i++){
		if(cadenaA[i] == cadenaB[j]){
			if(!bandInicio){
				indiceInicio = i;
				bandInicio = true;
				contador++;
				j++;
				
				if(sizeB == 1){
					j = 0;
					bandInicio = false;
					indicesPalabrasEncontradas[indiceX][indiceY] = indiceInicio; 
					indicesPalabrasEncontradas[indiceX][++indiceY] = i;
					indiceX++;
					indiceY = 0;
					contador = 0;
					nroIndices++;
				}
				
			}
			else{
				contador++;
				if(contador == sizeB){
					j = 0;
					bandInicio = false;
					indicesPalabrasEncontradas[indiceX][indiceY] = indiceInicio; 
					indicesPalabrasEncontradas[indiceX][++indiceY] = i;
					indiceX++;
					indiceY = 0;
					contador = 0;
					nroIndices++;
				}else{
					j++;
				}
			}
			
		}else{
			j = 0;
			contador = 0;
			bandInicio = false;
		}
	}
	
	
	//muestra todos los indices de las palabras encontradas
	/*
	for(i = 0; i < nroIndices ; i++){
		cout<<"X : "<<indicesPalabrasEncontradas[i][0]<<endl;
		cout<<"Y : "<<indicesPalabrasEncontradas[i][1]<<endl;
	}
	*/
	
	if(nroIndices == 0){
		cout<<endl<<"No se encontro ninguna igualdad "<<endl;
		return 0;
	}
	
	
	//elimino todas las palabras que se repiten en la cadenaA
	for(i = 0; i < sizeA; i++){
		bandCaracterValido = true;
		for(j = 0; j < nroIndices ; j++){
			if(indicesPalabrasEncontradas[j][0] <= i && indicesPalabrasEncontradas[j][1] >= i){
				bandCaracterValido = false;
				break;
			}
		}
		
		if(bandCaracterValido){
			cadenaFinal = cadenaFinal + cadenaA[i]; 
		}
		
	}
	
	cout<<endl<<"Cadena A sin las palabras de la cadena B :  "<<cadenaFinal<<endl;
	
	//hallamos los nuevos indices de la nueva cadena sin repeticiones
	
	for(j = 0; j < nroIndices ; j++){
		indicesNuevaCadena[j] = indicesPalabrasEncontradas[j][1] - (sizeB * (j+1));
	}
	
	sizeCadenaFinal = sizeA - (nroIndices * sizeB);
	
	//insertamos las palabars nuevas
	
	cadenaAux = cadenaFinal;
	cadenaFinal = "";
	contador = 0;
	bandReemplazo = false;
	
	while(contador != sizeCadenaFinal+1){
		for(j = 0; j < nroIndices ; j++){
			if(contador - 1 == indicesNuevaCadena[j]){
				cadenaFinal += cadenaC;
				break;
			}
		}
		
		cadenaFinal += cadenaAux[contador];
		contador++;
	}
	
	
	cout<<endl<<"La cadena Final es : "<<cadenaFinal;
	
	return 0;
}

