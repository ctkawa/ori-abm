#ifndef JARDINEIRO_H
#define JARDINEIRO_H

#include <iostream>
#include "arvore.h"

using namespace std;

class Jardineiro {
	private:
		string comando;
		Arvore arvore;

	public:
		Jardineiro();
		void executar();

		// interfaces
 		void MostrarIniciar();
 		void MostrarComando();
 		void MostrarMenu();
 		void MostrarBuscarElemento();
 		void MostrarBuscarIntervalo();
 		void MostrarInserirElemento();
 		void MostrarImprimirArvore();
 		void MostrarEsvaziarArvore();
 		void MostrarSobre();
 		void MostrarFinalizar();

		~Jardineiro();
};


#endif
