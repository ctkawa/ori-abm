#include "arvore.h"


Arvore::Arvore(){
		ptrRaiz = NULL;
    ordem = 5;
}

void Arvore::inserir(int novaChave, void* novoPtr){
    if(ptrRaiz == NULL){
        //novoNo <= novachave, novoPtr
        //novoNo.ptr[0]=null // nao ha outra folha para apontar
        ptrRaiz = new No(ordem, false); // criar no folha
				cout << ptrRaiz->getQuantidade() << endl;
				ptrRaiz->insereRec( novaChave, novoPtr );
				cout << ptrRaiz->getQuantidade() << endl;
    } else {
        bool dividiu = ptrRaiz->insereRec(/*raiz,*/ novaChave, novoPtr);
        No* novaRaiz = new No(ordem, true);
        //ajustar novaRaiz
				
				if( dividiu )
					dividiu = dividiu;
				
        ptrRaiz = novaRaiz;
    }
	cout << "inserido com sucesso" << endl;
	
	ptrRaiz->imprimir();
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
