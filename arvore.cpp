#include "arvore.h"


Arvore::Arvore(){
    ordem = 5;
}

void Arvore::inserir(int novaChave, void* novoPtr){
    if(ptrRaiz == NULL){
        No* novoNo = new No(ordem, false); // criar no folha
        //novoNo <= novachave, novoPtr
        //novoNo.ptr[0]=null // nao ha outra folha para apontar
        ptrRaiz = novoNo;
    } else {
        bool dividiu = ptrRaiz->insereRec(/*raiz,*/ novaChave, novoPtr);
        No* novaRaiz = new No(ordem, true);
        //ajustar novaRaiz
				
				if( dividiu )
					dividiu = dividiu;
				
				
        ptrRaiz = novaRaiz;
    }
	cout << "inserido com sucesso" << endl;
}

void Arvore::buscar(){
	cout << "elemento encontrado!" << endl;
}

void Arvore::buscarIntervalo(){
	cout << "intervalo encontrado" << endl;
}

void Arvore::esvaziar(){
	cout << "arvore vazia" << endl;
}

void Arvore::imprimir(){
	cout << endl << "\t\t" << "A R V O R E" << endl;
}

Arvore::~Arvore(){

}
