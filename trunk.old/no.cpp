#include "no.h"

NO::NO(){
	this->no = NULL;
	this->eRaiz = false;
}

NO::NO(tipoNo * no){
	this->no = no;
	this->eRaiz = false;
}

void NO::setTipo(NO_rotulo rotulo){
	this->no->tipo = rotulo;
}

void NO::setRaiz(bool eRaiz){
	this->eRaiz = eRaiz;
}

bool NO::getRaiz(){
	return this->eRaiz;
}

void NO::adicionar(NUMERO * numero, bool * erro){
	
	if( this->getRaiz() ){
		cout << "entrou é raiz\n";
		if( this->estaNulo() ){
			this->no = getNovoNo(FOLHA);
		}
		
		if( this->eFolha() ){
			cout << "entrou e folha\n";
			if( this->cabeMaisUm() ){
				cout << "entrou cabe mais um\n";
				cout << "entrou insereEOrdenaFolha\n";
				this->insereEOrdenaFolha(numero, erro);
				cout << "saiu insereEOrdenaFolha\n";
			} else {
				cout << "entrou nao cabe mais um\n";
				cout << "entrou divide folha raiz\n";
				this->divideFolhaRaiz(numero, erro);
				cout << "saiu divide folha raiz\n";
			}
		} else {
			cout << "entrou e interno\n";
			bool mandouAdicionar = false;
			unsigned int i = 0;
			while( !mandouAdicionar && i < this->no->contador ){
				if( this->no->vetorIndice[i] > numero->getNumero() ){
					NO noFilho(this->no->vetorNo[i]);
					
					if( noFilho->cabeMaisUm() ){
						noFilho.adicionar(numero, erro);
						if(*erro){
							return;
						}
					} else {
						this->divideFolha(i, numero, erro);
					}
					
					mandouAdicionar = true;
				}
				i++;
			}
			
			if(!mandouAdicionar){
				NO no(this->no->vetorNo[i]);
				no.adicionar(numero, erro);
				if(*erro){
					return;
				}
			}
		}
		
	} else {
		cout << "entrou nao e raiz\n";
		if( this->eFolha() ){
			cout << "entrou e folha\n";
			if( this->cabeMaisUm() ){
				this->insereEOrdenaFolha(numero, erro);
			} else {
				// divide folha não raiz
			}
		} else {
			cout << "entrou e interno\n";
			//caminha a baixo na árvore
		}
	}
}

bool NO::estaNulo(){
	if( this->no == NULL ){
		return true;
	}
	return false;
}

bool NO::cabeMaisUm(){
	if( this->no->contador < ARVORE_GRAU -1 ){
		return true;
	}
	return false;
}

void NO::insereEOrdenaFolha(NUMERO * numero, bool * erro){
	
	long long int indice = numero->getNumero();
	cout << "indice a ser adicionado = " << indice << endl;
	
	unsigned int posicao = this->no->contador;
	cout << "posicao que vai entrar = " << posicao << endl;
	bool inseriu = false;
/*	
	if( this->no->contador == 0 ){
		cout << "adiciou em vetor vazio\n";
		this->no->vetorIndice[posicao] = indice;
		this->no->vetorNumero[posicao] = numero;
		this->no->contador++;
		inseriu = true;
	}*/
	
	while( !inseriu ){
		cout << "ainda não inseriu\n";
		if(posicao == 0 || this->no->vetorIndice[posicao - 1] < indice){
			cout << "adicionando novo numero\n";
			this->no->vetorIndice[posicao] = indice;
			this->no->vetorNumero[posicao] = numero;
			this->no->contador++;
			inseriu = true;
		} else if( this->no->vetorIndice[posicao - 1] == numero->getNumero() ){
			*erro = true;
			cout << "ERRO: o número já existe na árvore\n";
			return;
		} else {
			cout << "movendo numero existente: ";
			this->no->vetorIndice[posicao] = this->no->vetorIndice[posicao - 1];
			this->no->vetorNumero[posicao] = this->no->vetorNumero[posicao - 1];
			cout << "numero existente movido\n";
		}
		posicao--;
	}
	
	 cout << "contador = " << this->no->contador << endl;
}

bool NO::eFolha(){
	if( this->no->tipo == FOLHA ){
		return true;
	}
	return false;
}

bool NO::eInterno(){
	if( this->no->tipo == INTERNO ){
		return true;
	}
	return false;
}

void NO::divideFolhaRaiz(NUMERO * numero, bool * erro){
	*erro = false;
	
	NUMERO * vetNumero[ARVORE_GRAU];
	
	unsigned int iNo = 0;
	unsigned int iAux = 0;
	bool adicionado = false;
	
	cout << "criando vetor auxiliar\n";
	cout << "contador = " << this->no->contador << " | ";
	cout << "iAux = " << iAux << endl;
	while( !(*erro) && iAux <= this->no->contador){
		cout << "entrou no while" << endl;
		if( !adicionado && numero->getNumero() < this->no->vetorIndice[iNo] ){
			vetNumero[iAux] = numero;
			iAux++;
			adicionado = true;
			cout << "adicionado novo numero: " << numero->getNumero() << endl;
			
		} else if ( numero->getNumero() == this->no->vetorIndice[iNo] ){
			cout << "Erro: o numero já está na árvore\n";
			*erro = true;
			return;
		} else {
			vetNumero[iAux] = this->no->vetorNumero[iNo];
			cout << "adicinado numero : " << this->no->vetorNumero[iNo]->getNumero() << endl;
			iAux++;
			iNo++;
		}
	}
	
	unsigned int iCorte = floor( (this->no->contador + 1)/2 );
	
	cout << "criando nos auxiliares\n";
	NO noEsquerdo( this->getNovoNo(FOLHA) );
	NO noDireito( this->getNovoNo(FOLHA) );
	NO noPai( this->getNovoNo(INTERNO) );
	
	iAux = 0;
	while( iAux < this->no->contador + 1 ){
		if( iAux < iCorte ){
			cout << "adicinando " << vetNumero[iAux]->getNumero() << " a esquerda\n";
			noEsquerdo.adicionar( vetNumero[iAux], erro );
		} else {
			cout << "adicinando " << vetNumero[iAux]->getNumero() << " a direita\n";
			noDireito.adicionar( vetNumero[iAux], erro );
		}
		
		if( *erro ){
			noEsquerdo.deletarNo();
			noDireito.deletarNo();
			noPai.deletarNo();
			return;
		} else {
			iAux++;
		}
	}
	
	noEsquerdo.setProximoNo( noDireito.getNo() );
	noPai.setFilhosRaiz(noEsquerdo.getNo(), noDireito.getIndiceMinimo(), noDireito.getNo());
	
	this->deletarNo();
	this->no = noPai.getNo();
	
}

tipoNo * NO::getNovoNo(NO_rotulo rotulo){
	tipoNo * no = new tipoNo;
	no->tipo = rotulo;
	no->contador = 0;
	no->vetorIndice = new long long int [ARVORE_GRAU - 1];
	no->vetorNumero = new NUMERO * [ARVORE_GRAU - 1];
	no->vetorNo = new tipoNo * [ARVORE_GRAU];
	no->vetorNo[0] = NULL;
	
	return no;
}

void NO::deletarNo(){
	if( this->no != NULL ){
		delete [] this->no->vetorIndice;
		delete [] this->no->vetorNumero;
		delete [] this->no->vetorNo;
		delete this->no;
	}
	this->no = NULL;
}


tipoNo * NO::getNo(){
	return this->no;
}

void NO::setProximoNo(tipoNo * proximoNo){
	this->no->vetorNo[0] = proximoNo;
}

tipoNo * NO::getProximoNo(){
	return this->no->vetorNo[0];
}

long long int NO::getIndiceMinimo(){
	if( this->no->contador > 0 ){
		return this->no->vetorIndice[0];
	} else {
		return NULL;
	}
}

void NO::setFilhosRaiz(tipoNo * esquerdo, long long int indice, tipoNo * direito){
	this->no->vetorIndice[0] = indice;
	this->no->vetorNo[0] = esquerdo;
	this->no->vetorNo[1] = direito;
	this->no->contador++;
}

void NO::imprimir(unsigned int recuo){

	if( this->eFolha() ){
		for(unsigned int i=0; i < this->no->contador; i++){
			this->imprimirRecuo(recuo+1);
			imprimirRecuo(recuo);
			cout << this->no->vetorIndice[i] << ": ";
			cout << this->no->vetorNumero[i]->getNome() << endl;
		}	
	} else {
	
		this->imprimirRecuo(recuo);
		cout << "imprimindo indices (contador = " << this->no->contador << ")\n";
		for(unsigned int i=0; i < this->no->contador; i++){
			cout << this->no->vetorIndice[i] << " ";
		}
		
		cout << "imprimindo filhos\n";
		
		for(unsigned int i=0; i < this->no->contador+1; i++){
			NO no(this->no->vetorNo[i]);
			no.imprimir(recuo + 1);
		}
	}
	cout << " cabou a impressao\n";
	
}

void NO::imprimirRecuo(unsigned int recuo){
	for(unsigned int i=0; i<recuo; i++){
		cout << "\t";
	}
}

void NO::divideFolha(unsigned int posicao, NUMERO * numero, bool * erro){
	*erro = false;
	tipoNo * no = this->vetorNo[posicao];
	
	NUMERO * vetNumero[ARVORE_GRAU];
	
	unsigned int iNo = 0;
	unsigned int iAux = 0;
	bool adicionado = false;
	
	cout << "criando vetor auxiliar\n";
	cout << "contador = " << no->contador << " | ";
	cout << "iAux = " << iAux << endl;
	while( !(*erro) && iAux <= no->contador){
		cout << "entrou no while" << endl;
		if( !adicionado && numero->getNumero() < no->vetorIndice[iNo] ){
			vetNumero[iAux] = numero;
			iAux++;
			adicionado = true;
			cout << "adicionado novo numero: " << numero->getNumero() << endl;
			
		} else if ( numero->getNumero() == no->vetorIndice[iNo] ){
			cout << "Erro: o numero já está na árvore\n";
			*erro = true;
			return;
		} else {
			vetNumero[iAux] = no->vetorNumero[iNo];
			cout << "adicinado numero : " << no->vetorNumero[iNo]->getNumero() << endl;
			iAux++;
			iNo++;
		}
	}
	
	unsigned int iCorte = floor( (no->contador + 1)/2 );
	
	cout << "criando nos auxiliares\n";
	NO noEsquerdo( this->getNovoNo(FOLHA) );
	NO noDireito( this->getNovoNo(FOLHA) );
	
	iAux = 0;
	while( iAux < no->contador + 1 ){
		if( iAux < iCorte ){
			cout << "adicinando " << vetNumero[iAux]->getNumero() << " a esquerda\n";
			noEsquerdo.adicionar( vetNumero[iAux], erro );
		} else {
			cout << "adicinando " << vetNumero[iAux]->getNumero() << " a direita\n";
			noDireito.adicionar( vetNumero[iAux], erro );
		}
		
		if( *erro ){
			noEsquerdo.deletarNo();
			noDireito.deletarNo();
			noPai.deletarNo();
			return;
		} else {
			iAux++;
		}
	}
	
	noDireito.setProximoNo( noEsquerdo.getProximoNo() );
	noEsquerdo.setProximoNo( noDireito.getNo() );
	noPai.setFilhosRaiz(noEsquerdo.getNo(), noDireito.getIndiceMinimo(), noDireito.getNo());
	
	this->deletarNo();
	this->no = noPai.getNo();
	
}

