#include "arvore.h"
//#include <iostream>
#include <fstream>
#include <cstdlib>
#include "selectionsort.h"

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
        ptrRaiz->insereRec( novaChave, novoPtr );
        qtdNo++;
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
						qtdNo++;
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
    qtdNo = 0;
	cout << "<stub esvaziar>" << endl;
}

void Arvore::imprimir(){
    ofstream html("Arvore.html");
    nivelNo *vetorNo = new nivelNo [qtdNo];
    int k=0, i, j, nivelTemp = 0;

    // Construindo cabeçalho do arquivo html
    html << "<html>\n<head>\n<title>Visualiza&ccedil;&atilde;o da &Aacute;rvore B+</title>\n</head>\n<body>\n\n" << endl;

    // Monta o vetor de structs com ponteiros para todos os nós e seus respectiveis níveis
    montaVetorImpressao(vetorNo, ptrRaiz, k, 1);

    /// Ainda não foi feito!!!
    // Usar selection no vetorNo
    // Isso fará com que os níveis próximos às folhas fiquem no final e os níveis próximo à raiz fiquem no começo
    // Com isso posso mostrar a árvore na sequência
    selectionsort(vetorNo, qtdNo);

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
        if(vetorNo[i].nivel == 1)
            html << " Raiz";
        else
            html << " N&oacute;";
        html << "</th></tr>" << endl;
        // Ordem da árvore
        html << "<tr><th style=\"border: 1px #8f8 solid\">N&deg; chaves" << "</th><td style=\"border: 1px #8f8 solid\">" << vetorNo[i].esseNo->getQuantidade() << "</td>" << endl;  // Quantidade de arquivos
        html << "<th style=\"border: 1px #8f8 solid\">Ordem" << "</th><td style=\"border: 1px #8f8 solid\">" << ordem << "</td></tr>" << endl;
        // Elementos da chave
        html << "<tr><th style=\"border: 1px #8f8 solid\">Chaves" << "</th><td colspan=3 style=\"border: 1px #8f8 solid\">\n<table border=1 style=\"border: 1px #00f solid;\" align=\"center\"><tr>";
        for(j=0;j<vetorNo[i].esseNo->getQuantidade();j++)
            html << "<td style=\"border: 1px #00f solid\">" << vetorNo[i].esseNo->getChave(j) << "</td>";
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

    if(!esse)
        return;

    if(esse->getTipo() == 'f') {
        noAtual.esseNo = esse;
        noAtual.nivel = level;
        vetorNo[k++] = noAtual;
        return;
    }

    int n, i=0;
    n = esse->getQuantidade() + 1;

    while(n) {
        montaVetorImpressao(vetorNo, (No*)esse->getPont(i++), k, level+1);
        noAtual.esseNo = esse;
        noAtual.nivel = level;
        vetorNo[k] = noAtual;
        n--;
    }
    return;
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

Arvore::~Arvore(){
    delete ptrRaiz;
}
