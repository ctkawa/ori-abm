#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>

#include "no.h"

using namespace std;

struct nivelNo {
    No *esseNo;
    short int nivel;
};

class Arvore{
    private:
		No* ptrRaiz;
		int ordem;  //Numero de ponteiros no no
		int qtdNo;
	public:
		Arvore();
		void inserir(int, void*);
		int* buscar (int busc_chave);
		void buscarIntervalo();
		void esvaziar();
		void imprimir();
		void abrir();
		void montaVetorImpressao(nivelNo[], No *esse, int &k, int level);
		~Arvore();
};

#endif
