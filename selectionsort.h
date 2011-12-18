void change(nivelNo v1, nivelNo v2) {
    nivelNo temp;

    temp = v1;
    v1 = v2;
    v2 = temp;
}

void selectionsort(nivelNo vetor[], int n) {
    int i, j, min;

    for(i=0;i<n-1;i++) {
        min = i;
        for (j=i+1;j<n;j++) {
            if (vetor[j].nivel > vetor[min].nivel)
                min = j;
        }
        if (i != min)
            change(vetor[i], vetor[min]);
    }
}
