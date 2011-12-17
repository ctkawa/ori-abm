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
	cout << "<stub inserir>" << endl;
	
	ptrRaiz->imprimir();
}

void Arvore::buscar(){
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
    delete no;
}
