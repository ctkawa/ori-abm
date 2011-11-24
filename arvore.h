#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>

using namespace std;

class Arvore{
	public:
		Arvore();
		void inserir();
		void buscar();
		void buscarIntervalo();
		void esvaziar();
		void imprimir();
		~Arvore();
};

#endif