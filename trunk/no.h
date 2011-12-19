#ifndef NO_H
#define NO_H

class No {
	friend class Arvore;

	private:
		int qntOcupado, ordem;
		int *chaves;
		void ** pont;
		char tipo; // i para no interno | f para no folha
		int *pQtdNo;

// Para uso interno
		static int chavePromovida;
		static No* ptrNovoNo;

	public:

		No(int elementos, bool isInterno);
		~No();
		int getChave(int indice);

		int setChave(int valor);

		void* getPont(int indice);

		void setPont(int indice, void* novoPtr);

		int getQuantidade();

		char getTipo();

        // insereRec retorna se dividiu ou nao
		bool insereRec(/*No* noAtual,*/ int novaChave, void* novoPtr);

		// para fins de debug
		void imprimir();

		int* busca (int busc_chave, No *raiz);
		void contarNo(int &contagem);
};

#endif
