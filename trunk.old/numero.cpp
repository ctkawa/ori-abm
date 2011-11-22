#include "numero.h"

NUMERO::NUMERO(){
	this->setNumero(0);
}

NUMERO::NUMERO(long long int numero){
	this->setNumero(numero);
}

long long int NUMERO::setNumero(long long int numero){
	if( numero > 0 ){
		this->numero = numero;
	} else {
		this->numero = 0;
	}
	
	// implementar atribuição de nome de verdade
	this->nome = "Nome do numero";
	
	// implementar atribuição de é par de verdade
	this->ePar = false;
	
	// implementar atribuição de é primo de verdade
	this->ePrimo = false;
	
	this->observacao = "";
	
	return this->numero;
}

long long int NUMERO::getNumero(){
	return this->numero;
}

string NUMERO::getNome(){
	return this->nome;
}

bool NUMERO::getEPar(){
	return this->ePar;
}

bool NUMERO::getEPrimo(){
	return this->ePrimo;
}

string NUMERO::setObservacao(string observacao){
	this->observacao = observacao;
	return this->observacao;
}

string NUMERO::getObservacao(){
	return this->observacao;
}

