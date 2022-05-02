#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int inicio, int meio, int fim){

    int *temp, p1, p2, tam, i, j, k, fim1 = 0, fim2 = 0;

    tam = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *) malloc(tam * sizeof(int));
    if (temp != NULL){
        for(i = 0; i < tam; i++){
            if(!fim1 && !fim2){
                if(vetor[p1] < vetor[p2]){
                    temp[i] = vetor[p1++]
                }
                else{
                    temp[i] = vetor[p2++];
                }
                if(p1 > meio){
                    fim1 = 1;
                }
                if(p2 > fim){
                    fim2 = 1;
                }
            }
            else{
                if(!fim1){
                    temp[i] = vetor[p1++];
                }
                else{
                    temp[i] = vetor[p2++];
                }
            }
        }
        for(j = 0, k = inicio; j < tam; j++, k++){
            vetor[k] = temp[j];
        }
    }
    free(temp);

}

void mergeSort(int *vetor, int inicio, int fim){

    int meio;
    if(inicio < fim){
        meio = floor((inicio + fim) / 2);
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }

}

int main(int argc, char* argv[]){



}
