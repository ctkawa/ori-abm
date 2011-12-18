#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>

#include "no.h"

using namespace std;

class Arvore{
	public:
		Arvore();
		void inserir(int, void*);
		int* buscar (int busc_chave);
		void buscarIntervalo();
		void esvaziar();
		void imprimir();
		~Arvore();
	private:
		No* ptrRaiz;
		int ordem;  //Numero de ponteiros no no
};

#endif
