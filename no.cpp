#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;


class No {
	private:
		int quantidade;
		int *chaves;
		void ** pont;
		bool tipo; // false para no interno | true para no folha
		
	public:
		No(int elementos){
			chaves = new int[elementos - 1];
			*pont = new void*[elementos];
		}
		int getChave(int indice){
			if(indice >= 0 && indice <= elementos) 
				return chaves[indice];
		}
		
		void setChave(int indice, int valor){
			if(indice >= 0 && indice <= elementos) 
				chaves[indice] = valor;
		}
		
		int getQuantidade(){
			return quantidade;
		}
		
		int getTipo(){		// Informa o tipo do no: false para no interno | true para no folha
			return tipo;
		}
		








};