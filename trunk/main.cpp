////////////////////////////////////
///
/// Universidade Federal de São Carlos
/// Departamento de Computação
///
///
///	Organização e Recuperação da Informação
/// Trabalho 2: Implementação de Árvore B+
///
///	grupo:
///	 Guilherme de Mello Barsoti, RA 386090
///	 João Celso Santos de Oliveira, RA 379247
///	 Willian Fenando Mendes, RA
///
///	Novembro de 2011
///
////////////////////////////////////


#include "numero.h"
#include "arvoreBMais.h"

#include <iostream>

using namespace std;

int main(){

	ARVOREBMAIS arvore;
	
	NUMERO * n;
	
	for(int i=0; i<5; i++){
		n = new NUMERO(i);
		arvore.adicionar(n);
		arvore.imprimir();
		cout << "\n\n\n\n";
	}
	
	
	
	
	return 0;
}
