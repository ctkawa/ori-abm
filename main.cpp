// cabeçalho

// includes
#include  "jardineiro.h"

#include "no.h"

int main (){

/*
       3
     2   4
    1 5 6 7
*/
/*
	No* no1 = new No(5,false);//folha
	cout << "sizeof folha: " << sizeof(*no1) << " bytes" << endl;
	No* no2 = new No(5,true);//interno
	cout << "sizeof interno: " << sizeof(*no2) << " bytes" << endl;
	No* no3 = new No(5,true);//interno
	No* no4 = new No(5,true);//interno
	No* no5 = new No(5,false);
	No* no6 = new No(5,false);
	No* no7 = new No(5,false);


	no3->setPont(0,no2);    no3->setChave(1);   //qtdOcupado eh so incrementado em setChave
	no3->setPont(1,no4);    no3->setChave(2);   //chaves em setChave se acomoda
	no2->setPont(0,no1);    no2->setChave(1);
	no2->setPont(1,no5);    no2->setChave(2);
	no4->setPont(0,no6);    no4->setChave(1);
    no4->setPont(1,no7);    no4->setChave(2);

	int cont = 0;
	no3->contarNo(cont);
	cout << "numero de nos: " << cont << endl;

	delete no1;
	delete no2;
    delete no3;
    delete no4;
    delete no5;
    delete no6;
    delete no7;
*/
	Jardineiro j;

	return 0;
}
