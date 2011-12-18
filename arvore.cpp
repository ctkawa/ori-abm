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
				ptrRaiz->insereRec( novaChave, novoPtr );
				
    } else {
        bool dividiu = ptrRaiz->insereRec(/*raiz,*/ novaChave, novoPtr);

        //Se houve divisao no raiz, criar novo raiz
        if( dividiu ){
            No* novaRaiz = new No(ordem, true);
						
            ////ajustar novaRaiz
						
						novaRaiz->chaves[0] = ptrRaiz->chavePromovida;
						novaRaiz->pont[0] = ptrRaiz;
						novaRaiz->pont[1] = ptrRaiz->ptrNovoNo;
						novaRaiz->qntOcupado = 1;
						
						ptrRaiz = novaRaiz;
						novaRaiz->imprimir();
        }
    }
	cout << "<stub inserir>" << endl;
}

int* Arvore::buscar (int busc_chave){
    return ptrRaiz->busca (busc_chave , ptrRaiz);
	cout << "<stub busca>" << endl;
}

void Arvore::buscarIntervalo(){
	cout << "<stub busca intervalo>" << endl;
}

void Arvore::esvaziar(){
	cout << "<stub esvaziar>" << endl;
}

void Arvore::imprimir(){
    cout << "<stub impressao arvore>" << endl;
	cout << endl << "\t\t" << "A R V O R E" << endl;
}

Arvore::~Arvore(){
    delete ptrRaiz;
}
