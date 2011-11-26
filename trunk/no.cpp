#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;


class No {
	private:
		int qntOcupado, ordem;
		int *chaves;
		void ** pont;
		char tipo; // i para no interno | f para no folha
		
	public:
		No(int elementos){
			ordem = elementos;
			chaves = new int[elementos - 1];
			*pont = new void*[elementos];
		}
		int getChave(int indice){
			if(indice >= 0 && indice <= ordem) 
				return chaves[indice];
		}
		
		void setChave(int indice, int valor){
			if(indice >= 0 && indice <= ordem) 
				chaves[indice] = valor;
		}
		
		int getQuantidade(){				// Informa a quantidade de elementos ocupados no vetor
			return qntOcupado;
		}
		
		char getTipo(){					// Informa o tipo do no: i para no interno | f para no folha
			return tipo;
		}


		
};



int main(){

	No away(5);
	away.setChave(0,34);
	cout << away.getChave(0) << endl;	
	return 0;
}