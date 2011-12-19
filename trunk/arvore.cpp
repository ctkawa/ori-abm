#include "arvore.h"
//#include <iostream>
#include <fstream>
#include <cstdlib>
#include "insertionsort.h"

#define DEBUG

Arvore::Arvore(){
    ptrRaiz = NULL;
    ordem = 5;
    qtdNo = 0;
}

void Arvore::inserir(int novaChave, void* novoPtr){
    if(ptrRaiz == NULL){
        //novoNo <= novachave, novoPtr
        //novoNo.ptr[0]=null // nao ha outra folha para apontar
        ptrRaiz = new No(ordem, false); // criar no folha
        ptrRaiz->insereRec( novaChave, novoPtr);
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
}

int* Arvore::buscar (int busc_chave){
    return ptrRaiz->busca (busc_chave , ptrRaiz);
	cout << "<stub busca>" << endl;
}

void Arvore::buscarIntervalo(){
	cout << "<stub busca intervalo>" << endl;
}

void Arvore::esvaziar(){
    qtdNo = 0;
	cout << "<stub esvaziar>" << endl;
}

void Arvore::imprimir(){
    ofstream html("Arvore.html");
    ptrRaiz->contarNo(qtdNo);
    //qtdNo = ;
    cout << qtdNo;
    nivelNo *vetorNo = new nivelNo [qtdNo];
    int k=0, i, j, nivelTemp = 0;

    // Construindo cabeçalho do arquivo html
    html << "<html>\n<head>\n<title>Visualiza&ccedil;&atilde;o da &Aacute;rvore B+</title>\n</head>\n<body>\n\n" << endl;

    // Monta o vetor de structs com ponteiros para todos os nós e seus respectiveis níveis
    montaVetorImpressao(vetorNo, ptrRaiz, k, 1);

    // O InsertionSort serve para organizar o vetor começando pelos níveis menores (próximos à raiz)
    insertionsort(vetorNo, qtdNo);

    html << "<h1 align=\"center\">A &aacute;rvore est&aacute; assim:</h1>\n<div align=\"center\"><center>\n";
    if(qtdNo == 0)
        html << "Vazia\n<br /><br />";
    html << "Quantidade de n&oacute;s: " << qtdNo << "<br>" << endl;
    for(i=0;i<qtdNo;i++) {
        if(nivelTemp != vetorNo[i].nivel) {
            if(nivelTemp != 0)
                html << "</table>" << endl;
            html << "<table border=0 cellspacing=5>" << endl;
        }
        html << endl << endl;
        html << "<td><table border=1 style=\"background-color: #00ca00;border: 1px #0f0 solid;\">" << endl;
        // Número do nível (1 = raiz)
        html << "<tr><th colspan=4 style=\"border: 1px #8f8 solid\">N&iacute;vel " << vetorNo[i].nivel << " - ";
        if(vetorNo[i].nivel == 1){
            html << " Raiz";
#ifdef DEBUG
html << " " << vetorNo[i].esseNo;
#endif
        }else if (vetorNo[i].folha){
            html << " Folha";
#ifdef DEBUG
html << " " << vetorNo[i].esseNo;
#endif
        }else{
            html << " N&oacute;";
#ifdef DEBUG
html << " " << vetorNo[i].esseNo;
#endif
        }
        html << "</th></tr>" << endl;
        // Ordem da árvore
        html << "<tr><th style=\"border: 1px #8f8 solid\">N&deg; chaves" << "</th><td style=\"border: 1px #8f8 solid\">" << vetorNo[i].esseNo->getQuantidade() << "</td>" << endl;  // Quantidade de arquivos
        html << "<th style=\"border: 1px #8f8 solid\">Ordem" << "</th><td style=\"border: 1px #8f8 solid\">" << ordem << "</td></tr>" << endl;
        // Elementos da chave
        html << "<tr><th style=\"border: 1px #8f8 solid\">Chaves" << "</th><td colspan=3 style=\"border: 1px #8f8 solid\">\n<table border=1 style=\"border: 1px #00f solid;\" align=\"center\"><tr>";
        for(j=0;j<vetorNo[i].esseNo->getQuantidade();j++){
            html << "<td style=\"border: 1px #00f solid\">" << vetorNo[i].esseNo->getChave(j);
#ifdef DEBUG
html << "/" << vetorNo[i].esseNo->getPont(j);
if (!vetorNo[i].folha){
html << "/" << vetorNo[i].esseNo->getPont(j+1);
}
#endif
            html << "</td>";
        }
        html << "</tr>\n</table></td>" << endl;

        html << "</table></td>" << endl;
        nivelTemp = vetorNo[i].nivel;
    }
    html << "</center></div>";

    // Construindo o rodapé da página
    html << "\n\n</body>\n</html>";
    html.close();
    if(qtdNo == 0)
        cout << "A arvore esta vazia atualmente.\nInsira alguns valores..." << endl;
    else
        cout << endl << "Arvore construida com sucesso!\nDigite 'Abrir' para ela aparecer em seu navegador!" << endl;
}

void Arvore::montaVetorImpressao(nivelNo vetorNo[], No *esse, int &k, int level) {
    nivelNo noAtual;

    // Caso a árvore não tenha nada
    if(!esse)
        return;

    if(esse->getTipo() == 'f') {
        noAtual.esseNo = esse;
        noAtual.nivel = level;
        noAtual.folha = true;
        vetorNo[k++] = noAtual;
        return;
    }

    int n, i=0;
    n = esse->getQuantidade() + 1;

    while(n) {
        montaVetorImpressao(vetorNo, (No*)esse->getPont(i++), k, level+1);
        n--;
    }
    noAtual.esseNo = esse;
    noAtual.nivel = level;
    noAtual.folha = false;
    vetorNo[k++] = noAtual;
}

void Arvore::abrir() {
    ifstream tem("Arvore.html");
    if(!tem)
        cout << "Ops, o arquivo ainda nao foi criado." << endl << "Digite 'imprimir' na linha de comando primeiro" << endl;
    else {
        tem.close();
        system("Arvore.html");
    }
}

void Arvore::listar(){
    ofstream html("Arvore_-_Listagem.html");
    ptrRaiz->contarNo(qtdNo);
    nivelNo *vetorNo = new nivelNo [qtdNo];
    int k=0, i, j, nivelTemp = 0;

    // Construindo cabeçalho do arquivo html
    html << "<html>\n<head>\n<title>Visualiza&ccedil;&atilde;o da &Aacute;rvore B+</title>\n</head>\n<body>\n\n" << endl;

    // Monta o vetor de structs com ponteiros para todos os nós e seus respectiveis níveis
    montaVetorImpressao(vetorNo, ptrRaiz, k, 1);

    // O InsertionSort serve para organizar o vetor começando pelos níveis menores (próximos à raiz)
    insertionsort(vetorNo, qtdNo);

    html << "<h1 align=\"center\">A &aacute;rvore possui as seguintes chaves:</h1>\n<div align=\"center\"><center>\n";
    if(qtdNo == 0)
        html << "Vazia\n<br /><br />";
    for(i=0;i<qtdNo;i++) {
        if(vetorNo[i].folha) {
            for(j=0;j<vetorNo[i].esseNo->getQuantidade();j++)
                html << vetorNo[i].esseNo->getChave(j) << "<br />" << endl;
        }
    }
    html << "</center></div>";

    // Construindo o rodapé da página
    html << "\n\n</body>\n</html>";
    html.close();
    if(qtdNo == 0)
        cout << "A arvore esta vazia atualmente.\nInsira alguns valores..." << endl;
    else
        cout << endl << "Arvore construida com sucesso!\nDigite 'Abrir' para ela aparecer em seu navegador!" << endl;
}

int Arvore::getNumeroNo(){
    int contagem = 0;
    ptrRaiz->contarNo(contagem);
    return contagem;
}

Arvore::~Arvore(){
    delete ptrRaiz;
}
