#ifndef NO_H
#define NO_H

#include "math.h"
#include "constantes.h"
#include "numero.h"


enum NO_rotulo { ROOT, INTERNO, FOLHA };

typedef struct tipoNo {
	NO_rotulo tipo;
	unsigned int contador;
	long long int * vetorIndice;
	tipoNo ** vetorNo;
	NUMERO ** vetorNumero;
} tipoNo;

class NO{
	private:
		tipoNo * no;
		bool eRaiz;
		
	public:
		NO();
		NO(tipoNo *);
		void setTipo(NO_rotulo);
		void setRaiz(bool);
		bool getRaiz();
		void adicionar(NUMERO *, bool *);
		bool estaNulo();
		bool cabeMaisUm();
		void insereEOrdenaFolha(NUMERO *, bool *);
		bool eFolha();
		bool eInterno();
		void divideFolhaRaiz(NUMERO *, bool *);
		tipoNo * getNovoNo(NO_rotulo);
		void deletarNo();
		tipoNo * getNo();
		void setProximoNo(tipoNo *);
		long long int getIndiceMinimo();
		void setFilhosRaiz(tipoNo *, long long int, tipoNo *);
		void imprimir(unsigned int);
		void imprimirRecuo(unsigned int);
};

#endif

