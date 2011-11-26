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
			qntOcupado = 0;
			ordem = elementos;
			chaves = new int[elementos - 1];
			*pont = new void*[elementos];
		}
		int getChave(int indice){
			if(indice >= 0 && indice <= ordem) 
				return chaves[indice];
		}
		
		int setChave(int valor){					
			if (qntOcupado < ordem ){
				int i;
				for(i = qntOcupado; i > 0 && chaves[i - 1] > valor; i--)
					chaves[i] = chaves[i - 1];
				
				chaves[i]  = valor;
					
				qntOcupado++;

				return i;
			}else
				return -1;	
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
	away.setChave(34);
	cout << away.getChave(0) << endl;	
	away.setChave(2);
	cout << away.getChave(0) << endl;	
	cout << away.getChave(1) << endl;	
	away.setChave(55);
	away.setChave(1);
	cout << away.getQuantidade() << endl;
	cout << away.getChave(0) << endl;
	cout << away.getChave(1) << endl;	
	cout << away.getChave(2) << endl;	
	cout << away.getChave(3) << endl;	
	return 0;
}