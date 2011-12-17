#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

/**
 * FOLHA => pont[0] aponta para proxima folha,
 * correspondente de chaves[n] e pont[n+1]
 *
**/

#include "no.h"

int No::chavePromovida;
No* No::ptrNovoNo;


No::No(int elementos, bool isInterno){
    qntOcupado = 0;
    ordem = elementos;
    chaves = new int[elementos - 1];
    *pont = new void*[elementos];
    tipo = isInterno?'i':'f';
}

No::~No(){
    delete chaves;
    delete pont;
}

int No::getChave(int indice){
    if(indice >= 0 && indice <= ordem)
        return chaves[indice];
		else
			return -1;
}

int No::setChave(int valor){
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

int No::getQuantidade(){				// Informa a quantidade de elementos ocupados no vetor
    return qntOcupado;
}

char No::getTipo(){					// Informa o tipo do no: i para no interno | f para no folha
    return tipo;
}

// insereRec retorna se dividiu ou nao
bool No::insereRec(/*No* noAtual,*/ int novaChave, void* novoPtr){
    if(tipo == 'i'){
        No* filho = (No*) pont[qntOcupado];
        for(int i = qntOcupado; i>0; i--){
            if(chaves[i-1] >= novaChave)
                filho = (No*) pont[i-1];
        }
        bool dividiu = filho->insereRec(novaChave, novoPtr);
        if(dividiu){
            if(qntOcupado < ordem-1){
                /*HA ESPACO NESTE NIVEL, INSERIR CODIGO E PTR*/
                int contador = qntOcupado;  //contador = primeira posicao vazia
                while(contador>0 && (chaves[contador-1] >= novaChave)){
                    chaves[contador] = chaves[contador-1];
                    pont[contador+1] = pont[contador];
                    contador--;
                }
                chaves[contador] = chavePromovida;
                pont[contador+1] = ptrNovoNo;
                qntOcupado++;
                return false;
            } else {
                /*DIVIDIR NESTE NIVEL*/
                // retorne parametros em "chavePromovida" e "ptrNovoNo"


                return true;
            }
        }
    }else if(tipo == 'f'){
        if(qntOcupado < ordem-1){
            /*INSERIR NESTA FOLHA*/
            int contador = qntOcupado;  //contador = primeira posicao vazia
            while(contador>0 && (chaves[contador-1] >= novaChave)){
                chaves[contador] = chaves[contador-1];
                pont[contador+1] = pont[contador];
                contador--;
            }
            chaves[contador] = novaChave;
            pont[contador+1] = novoPtr;
            qntOcupado++;
            return false;
        }else{
            /*DIVIDIR ESTA FOLHA*/
            // retorne parametros em "chavePromovida" e "ptrNovoNo"


            return true;
        }
    }else{
        cout << "NO: TIPO INVALIDO" << endl;
        return false;
    }
    return false;
}




/*
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
*/
