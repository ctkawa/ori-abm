#ifndef NO_H
#define NO_H

class No {
	private:
		int qntOcupado, ordem;
		int *chaves;
		void ** pont;
		char tipo; // i para no interno | f para no folha

// Para uso interno
		static int chavePromovida;
		static No* ptrNovoNo;

	public:

		No(int elementos, bool isInterno);
		~No();
		int getChave(int indice);

		int setChave(int valor);

		int getQuantidade();

		char getTipo();

        // insereRec retorna se dividiu ou nao
		bool insereRec(/*No* noAtual,*/ int novaChave, void* novoPtr);



};

#endif
