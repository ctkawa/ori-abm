#ifndef NUMERO_H
#define NUMERO_H

#include <iostream>


using namespace std;

class NUMERO {
	private:
		long long int numero;
		string nome;
		bool ePar;
		bool ePrimo;
		string observacao;
	
	public:
		NUMERO();
		NUMERO(long long int);
		long long int setNumero(long long int);
		long long int getNumero();
		string getNome();
		bool getEPar();
		bool getEPrimo();
		string setObservacao(string);
		string getObservacao();
};

#endif