void insertionsort(nivelNo vetor[], int n) {
    int i, j;
    nivelNo a;

    for(j=1;j<n;j++) {
        a = vetor[j];
        i = j-1;
        while(i >= 0 && vetor[i].nivel > a.nivel) {
            vetor[i+1] = vetor[i];
            i--;
        }
        vetor[i+1] = a;
    }

}
