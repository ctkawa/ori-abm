#ifndef ARVORE_B_MAIS_H
#define ARVORE_B_MAIS_H


#include <iostream>
#include "no.h"
#include "numero.h"
#include "math.h"


class ARVOREBMAIS {
	private:
		NO raiz;
		
	public:
		ARVOREBMAIS();
		bool adicionar(NUMERO *);
		bool buscar(long long int, NUMERO *);
		bool remover(long long int, NUMERO *);
		void imprimir();
		~ARVOREBMAIS();
};

#endif