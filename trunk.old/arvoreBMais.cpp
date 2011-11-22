#include "arvoreBMais.h"

ARVOREBMAIS::ARVOREBMAIS(){
	this->raiz.setRaiz(true);
}

bool ARVOREBMAIS::adicionar(NUMERO * numero){
	bool erro;
	cout << "adicionar entra ok\n";
	this->raiz.adicionar(numero, &erro);
	cout << "adicionar sai ok\n";
	return erro;
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

void ARVOREBMAIS::imprimir(){
	cout << "entrou raiz.imprimir\n";
	this->raiz.imprimir(0);
	cout <<  "saiu raiz imprimir\n";
}

ARVOREBMAIS::~ARVOREBMAIS(){
	// implementar: delete todos os vetores recursivamente
}