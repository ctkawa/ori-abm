#include "jardineiro.h"

Jardineiro::Jardineiro(){

 	for(int i=0; i<20; i++){
// 		cout << "==================" << endl;
// 		cout << "==================" << endl;
// 		cout << "==================" << endl;
// 		cout << "==================" << endl;
// 		cout << "==================" << endl;
// 		cout << "==================" << endl;
// 		cout << "==================" << endl;
// 		cout << "==================" << endl;
 		this->arvore.inserir( i, new int(i) );
 	}

	this->executar();
}

void Jardineiro::executar(){

	// tela de inicialização
	this->MostrarIniciar();
	bool sair = false;

	while(!sair){
		// recebe comando
		this->MostrarComando();

		// interpreta comando
		if(this->comando == "sair"){
			sair = true;
		} else if(this->comando == "menu"){
			this->MostrarMenu();
		} else if(this->comando == "buscar"){
			this->MostrarBuscarElemento();
		} else if(this->comando == "buscarintervalo"){
			this->MostrarBuscarIntervalo();
		} else if(this->comando == "inserir"){
			this->MostrarInserirElemento();
		} else if(this->comando == "imprimir"){
			this->MostrarImprimirArvore();
        } else if(this->comando == "abrir"){
			this->MostrarAbrirArvore();
		} else if(this->comando == "esvaziar"){
			this->MostrarEsvaziarArvore();
		} else if(this->comando == "sobre"){
			this->MostrarSobre();
		} else {
		    cout << endl;
		    MostrarMenu();
		    cout << endl;
		}
	}

	// tela de finalização
	this->MostrarFinalizar();
}

void Jardineiro::MostrarIniciar(){

	cout << endl;
	cout << "   _.%.$$&$%$$8o_	" << endl;
	cout << " _$$$$%$&&&%$&&$$$.	" << endl;
	cout << ".$&%$$$$&$%$/$&&$%$	" << endl;
	cout << "$$$%$$%&$&%/$&%$$&$$	" << endl;
	cout << "_%$$$&$%$$%$%$$$%&$&	" << endl;
	cout << "$$&$$|$$$\\%$%$$%$$$'	" << endl;
	cout << "%&$%|&$$$$V$&/$$&$&$	" << endl;
	cout << "`$$%&|$%$%|$&$&%%%$$	" << endl;
	cout << " '%$$$%$$&$%$$/$$`	" << endl;
	cout << "  $$&$&|&$%%/$$%$$,	" << endl;
	cout << "   ` $$|||//$%	" << endl;
	cout << "       #89 " << endl;
	cout << "       8#R	" << endl;
	cout << "       6FN	" << endl;
	cout << "       XB#" << endl;
	cout << "       S8P	" << endl;
	cout << "       #8H	" << endl;
	cout << "       9##	" << endl;
	cout << "     _.986,_ 	" << endl;
	cout << "        ' `' mh	" << endl;
	cout << endl;

	cout << "Bem vindo a Arvore!" << endl;
}

void Jardineiro::MostrarComando(){
	cout << ">> ";
	cin >> this->comando;
}

void Jardineiro::MostrarMenu(){
	cout << "-- MENU --" << endl;
	cout << "\tmenu" << endl;
	cout << "\tbuscar" << endl;
	cout << "\tbuscarintervalo" << endl;
	cout << "\tinserir" << endl;
	cout << "\timprimir" << endl;
	cout << "\tabrir" << endl;
	cout << "\tsair" << endl;
	//cout << "\tmenu" << endl;
	//cout << "\tesvaziar" << endl;
	cout << endl;
}

void Jardineiro::MostrarBuscarElemento(){
	int chave;

	cout << "Buscar por chave: ";
	cin >> chave;
	cout << endl;

	// busca
	cout << "Buscando chave na arvore..." << endl;

	int* resultado = this->arvore.buscar(chave);

	// imprime resultado
	cout << "Imprimindo resultado: " <<*resultado<< endl;
}

void Jardineiro::MostrarBuscarIntervalo(){
	int min;
	int max;

	cout << "Buscar por chaves entre min e max:" << endl;

	cout << "\tmin = ";
	cin >> min;
	cout << endl;

	cout << "\tmax = ";
	cin >> max;
	cout << endl;

	// busca
	cout << "Buscando o Chaves na arvore..." << endl;

	this->arvore.buscarIntervalo();

	//imprime resultado
	cout << "Imprimindo lista de resultado: <?resulados?>" << endl;

}

void Jardineiro::MostrarInserirElemento(){
	int *elemento = new int;

	cout << "Inserir elemento: ";
	cin >> *elemento;

	cout << "Inserindo elemento na arvore... " << endl;

	this->arvore.inserir( *elemento, elemento );

	cout << "Inserido com sucesso." << endl;
}

void Jardineiro::MostrarImprimirArvore(){
	cout << "Imprimindo arvore: " << endl;

	this->arvore.imprimir();

	cout << endl;

}

void Jardineiro::MostrarAbrirArvore(){
	cout << "Abrindo a arvore impressa em seu navegador padrao: " << endl;

	this->arvore.abrir();

	cout << endl;

}

void Jardineiro::MostrarEsvaziarArvore(){
	cout << "Esvaziando arvore..." << endl;

	this->arvore.esvaziar();

	cout << "Arvore vazia." << endl;
}

void Jardineiro::MostrarSobre(){
	cout << "Nos escrevemos este programa Ele funciona e estamos muito felizes com isso." << endl << endl;
}

void Jardineiro::MostrarFinalizar(){
	cout << "Volte sempre." << endl;
}

Jardineiro::~Jardineiro(){

}
