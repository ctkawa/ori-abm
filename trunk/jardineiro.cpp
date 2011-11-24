#include "jardineiro.h"

Jardineiro::Jardineiro(){
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
		} else if(this->comando == "esvaziar"){
			this->MostrarEsvaziarArvore();
		} else if(this->comando == "sobre"){
			this->MostrarSobre();
		}
	}
	
	// tela de finalização
	this->MostrarFinalizar();
}

void Jardineiro::MostrarIniciar(){
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
	cout << "\tsair" << endl;
	cout << endl;
}

void Jardineiro::MostrarBuscarElemento(){
	int chave;
	
	cout << "Buscar por chave: ";
	cin >> chave;
	cout << endl;
	
	// busca
	cout << "Buscando chave na arvore..." << endl;
	
	// imprime resultado
	cout << "Imprimindo resultado: <?resultado?>" << endl;
	
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
	
	//imprime resultado
	cout << "Imprimindo lista de resultado: <?resulados?>" << endl;
	
}

void Jardineiro::MostrarInserirElemento(){
	int elemento;
	
	cout << "Inserir elemento: ";
	cin >> elemento;
	
	cout << "Inserindo elemento na árvore... " << endl;
	cout << "Inserido com sucesso." << endl;
}

void Jardineiro::MostrarImprimirArvore(){
	cout << "Imprimindo arvore: " << endl;
	
	cout << endl << "\t\tarvore" << endl;
	
	cout << endl;
	
}

void Jardineiro::MostrarEsvaziarArvore(){
	cout << "Esvaziando arvore..." << endl;
	
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