#include "arvoreBMais.h"

ARVOREBMAIS::ARVOREBMAIS(unsigned int grau){
	
	if(grau < 2){
		this->grau = 2;
		cout << "Ajustando árvore para grau mínimo 2.";
	} else {
		this->grau = grau;
	}
	
	root = NULL;
}

bool ARVOREBMAIS::adicionar(NUMERO * numero){
	long long int indice = numero->getNumero();
	bool erro = false;
	
	// codigo para adicionar
	
	if (erro){
		cout << "ERRO";
		return false;
	}
	
	return true;
}

bool ARVOREBMAIS::buscar(long long int indice, NUMERO * numero){
	bool erro = false;
	
	// codigo para buscar
	
	if(erro){
		numero = NULL;
		cout << "ERRO";
		return false;
	}
	
	return true;
}

bool ARVOREBMAIS::remover(long long int indice, NUMERO * numero){
	bool erro = false;
	
	// codigo para remover
	
	if(erro){
		numero = NULL;
		cout << "ERRO";
		return false;
	}
	
	return true;
}
