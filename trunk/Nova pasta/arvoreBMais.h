#ifndef ARVORE_B_MAIS_H
#define ARVORE_B_MAIS_H

#include <iostream>
#include "no.h"
#include "numero.h"


class ARVOREBMAIS {
	private:
		unsigned int grau;
		NO * root;
	
	public:
		ARVOREBMAIS(unsigned int grau);
		bool adicionar(NUMERO *);
		bool buscar(long long int, NUMERO *);
		bool remover(long long int, NUMERO *);
};

#endif