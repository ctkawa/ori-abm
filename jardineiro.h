#ifndef JARDINEIRO_H
#define JARDINEIRO_H

#include <iostream>
#include "arvore.h"
//#include "no.h"

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
 		void MostrarAbrirArvore();
 		void MostrarListarArvore();
 		void MostrarEsvaziarArvore();
 		void MostrarSobre();
 		void MostrarFinalizar();

		~Jardineiro();
};

#endif
