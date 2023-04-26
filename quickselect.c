#include <stdio.h>
#include <stdlib.h>

//funcao que troca o valor de duas variaveis
void troca(int x,int y){
    int temp = x;
    x = y;
    y = temp;
}

//faz a particao do vetor
int particiona(int *vetor, int esq, int dir, int pivo_index){
    //escolhe a posicao pivo_index como pivo
    int pivo = vetor[pivo_index];
    //move o pivo para o final do vetor
    troca(vetor[pivo_index], vetor[dir]);

    pivo_index = esq;
    int i;
    for(i = esq; i < dir; i++){
        if(vetor[i] <= pivo){
            troca(vetor[i], vetor[pivo_index]);
            pivo_index++;
        }
    }
    troca(vetor[pivo_index], vetor[dir]);
    return pivo_index;
}

int quickselect(int *vetor, int esq, int dir, int k){
    if(esq == dir){
        return vetor[esq];
    }

    int pivo_index = esq + rand() % (dir - esq + 1);
    pivo_index = particiona(vetor, esq, dir, pivo_index);

    if(k == pivo_index){
        return vetor[k];
    }

    else if(k < pivo_index){
        return quickselect(vetor, esq, pivo_index-1, k);
    }

    else{
        return quickselect(vetor, pivo_index+1, dir, k);
    }
}

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Digite %s -k (valor de k)\n", argv[0]); // exemplo: ./quickselect -k 10
        return 1;
    }
    int k = atoi(argv[2]);

    int tam = 1;
    int *vetor = (int*) malloc(tam*sizeof(int));

    while(scanf("%d", &vetor[tam-1]) != EOF){
        tam++;
        vetor = (int*) realloc(vetor, tam*sizeof(int));
    }
    vetor = (int*) realloc(vetor, (tam-1)*sizeof(int));

    printf("%d\n", quickselect(vetor, 0, tam-1, k-1));

    free(vetor);
    return 0;
}