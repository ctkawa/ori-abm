#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

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
    pont = new void* [elementos];
    for(int i=0; i<elementos; i++)
        pont[i] = NULL;

	if(!isInterno){
		pont[0] = NULL;
	}

    tipo = isInterno? 'i' : 'f';
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

void* No::getPont(int indice){
    if(indice >= 0 && indice < ordem)
        return pont[indice];
    else
        return NULL;
}

void No::setPont(int indice, void* novoPtr){
    if(indice >= 0 && indice < ordem){
        pont[indice] = novoPtr;
    }
}

int No::getQuantidade(){				// Informa a quantidade de elementos ocupados no vetor
    return qntOcupado;
}

char No::getTipo(){					// Informa o tipo do no: i para no interno | f para no folha
    return tipo;
}

// insereRec retorna se dividiu ou nao
bool No::insereRec(/*No* noAtual,*/ int novaChave, void* novoPtr){
		cout << endl << "== Inserindo " << novaChave << " no nó atual: =========" << endl;
		imprimir();

    if(tipo == 'i'){
				cout << "------- no interno: inserindo " << novaChave << endl;
        No* filho = (No*) pont[qntOcupado];
        for(int i = qntOcupado; i>0; i--){
            if(chaves[i-1] >= novaChave)
                filho = (No*) pont[i-1];
        }
				cout << filho << endl;
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

								cout << endl << "dividindo nó interno por causa do " << novaChave << endl;

								No* noesq = new No(ordem, true);
								No* nodir = new No(ordem, true);


								int posicao = 0;
								bool novaChaveInserida = false;
								bool chaveFoiPromovida = false;

								noesq->pont[0] = pont[0];

								int addchave = 0;
								No* addpont = NULL;

								while(posicao < ordem-1){
									if(!novaChaveInserida && chavePromovida <= chaves[posicao]){
										addchave = filho->chavePromovida;
										addpont = filho->ptrNovoNo;
										novaChaveInserida = true;
									} else {
										addchave = chaves[posicao];
										addpont = static_cast<No*>(pont[posicao+1]);
										posicao++;
									}

									if( noesq->getQuantidade() < ceil(ordem/2) ){
										noesq->chaves[noesq->getQuantidade()] = addchave;
										noesq->pont[noesq->getQuantidade()+1] = addpont;
										noesq->qntOcupado++;
									} else {
										if( !chaveFoiPromovida ){
											chavePromovida = addchave;
											nodir->pont[0] = addpont;
											chaveFoiPromovida = true;
										} else {
											nodir->chaves[noesq->getQuantidade()] = addchave;
											nodir->pont[noesq->getQuantidade()+1] = addpont;
											nodir->qntOcupado++;
										}
									}
								}



								// sobrescreve o no atual por noesq

								qntOcupado = noesq->qntOcupado;

								for(int i=0; i<qntOcupado; i++)
									chaves[i] = noesq->chaves[i];

								for(int i=0; i<=qntOcupado; i++)
									pont[i] = noesq->pont[i];

								// retorna os dados necessários para o no pai
								novoPtr = nodir;
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
            cout << endl << "dividindo nó folha por causa do " << novaChave << endl;

						No* noesq = new No(ordem, false);
						No* nodir = new No(ordem, false);

						int posicao = 0;
						bool novaChaveInserida = false;

						while( posicao < ordem-1 ){

							if( !novaChaveInserida && chaves[posicao] >= novaChave ){
								if( noesq->getQuantidade() <= ceil(ordem/2) ){
									noesq->insereRec( novaChave, novoPtr );
								} else {
									nodir->insereRec( novaChave, novoPtr );
								}
								novaChaveInserida = true;
							}

							if( noesq->getQuantidade() <= ceil(ordem/2) ){
								noesq->insereRec( chaves[posicao], pont[posicao+1] );
							} else {
								nodir->insereRec( chaves[posicao], pont[posicao+1] );
							}

							posicao++;
						}

						if(!novaChaveInserida){
							nodir->insereRec( novaChave, novoPtr );
						}

						// resolve ponteiros da lista
						noesq->pont[0] = nodir;
						nodir->pont[0] = pont[0];


						// sobrescreve o no atual por noesq

						qntOcupado = noesq->qntOcupado;

						for(int i=0; i<qntOcupado; i++)
							chaves[i] = noesq->chaves[i];

						for(int i=0; i<=qntOcupado; i++)
							pont[i] = noesq->pont[i];

						// retorna os dados necessários para o no pai
						ptrNovoNo = nodir;
						chavePromovida = nodir->chaves[0];

            return true;
        }
    }else{
        cout << "NO: TIPO INVALIDO" << endl;
        return false;
    }
    return false;
}

void No::imprimir(){
	cout << "No (" << qntOcupado << "):" << endl;

	cout << "chaves: [ ";
	for(int i=0; i<ordem-1; i++){
		if(i < qntOcupado)
			cout << chaves[i] << " ";
		else
			cout << "x ";
	}
	cout << "]" << endl;

	if( tipo == 'f' ){
		cout << "dados: [ ";
		for(int i=0; i<ordem; i++){
			if( i == 0){
				cout << static_cast<No*>(pont[i]) << " ";
			} else if(i < qntOcupado+1){
				cout << *(static_cast<int*>(pont[i])) << " ";
			} else
				cout << "x ";
		}
		cout << "]" << endl;
	} else {
		cout << "pont: [ ";
		for(int i=0; i<ordem; i++){
			if(i < qntOcupado+1)
				cout << static_cast<No*>(pont[i]) << " ";
			else
				cout << "x ";
		}
		cout << "]" << endl;
	}

}

int* No::busca (int busc_chave, No *raiz)
{
	if(raiz == NULL)//caso a �rvore esteja vazia
	{
		cout<<"arvore vazia"<<endl;
		return NULL;
	}


	No *aux;
	aux = raiz;
	int i;

	while(aux->tipo == 'i') // while para ir at� um n� folha que possivelmente
	{			  //se encontra a chave procurada
		i = 0;    //o while abaixo serve para andar nas chaves do n� interno at� encontrar uma chave maior ou igual,
		while(aux->getQuantidade() >= i+1 && aux->chaves[i] < busc_chave) //ou ver que todas as chaves desse n� s�o menores que a chave procurada
			i++;
		if(aux->chaves[i] == busc_chave || aux->getQuantidade() < i+1)
			aux = (static_cast<No*>(aux->pont[i+1])); // caso ache uma chave igual ou nenhuma maior *(static_cast<double*>(pont[2]))
						  //o ponteiro aux recebe o ponteiro a direita, ou da �ltima chave ou da chave igual

		else if (aux->chaves[i] > busc_chave) //foi encontrada uma chave maior
			aux = (static_cast<No*>(aux->pont[i])); // aux recebe o ponteiro para os n�s com chaves menores que a maior que foi encontrada no n� que se estava pesquisando
	}

	// o aux sai do while acima apontando para uma folha

	if (aux->tipo == 'f') // estamos em uma folha
	{
		i=0;
		while(aux->getQuantidade() >= i+1 && aux->chaves[i] < busc_chave)
			i++;
		if(aux->chaves[i] == busc_chave) //caso tenhamos na folha a chave que estavamos procurando
			return (static_cast<int*>(aux->pont[i+1]));
		else
		{
			cout<<"chave nao encontrada"<<endl;
	 		return NULL;
		}
	}
	return NULL;
}

// contar nos descendentes, inclusive este
void No::contarNo(int &contagem){
    if(tipo=='i'){
        for(int i = 0; i<qntOcupado; i++){
            ((No*)pont[i])->contarNo(contagem);
        }
    }
    contagem += 1;  //desse no
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
