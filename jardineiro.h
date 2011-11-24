#ifndef JARDINEIRO_H
#define JARDINEIRO_H

#include <iostream>

using namespace std;

class Jardineiro {
	private:
		string comando;
	
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