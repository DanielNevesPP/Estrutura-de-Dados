#include <stdio.h>
#include <stdlib.h>

//funcao que troca o valor de duas variaveis
#define troca(x, y) {int temp = x; x = y; y = temp;}


//faz a particao do vetor
int particiona(int *vetor, int esq, int dir, int pivo_index){
    //escolhe a posicao pivo_index como pivo
    int pivo = vetor[pivo_index];
    //move o pivo para o final do vetor
    troca(vetor[pivo_index], vetor[dir]);

    //pivo_index recebe o valor de esq
    pivo_index = esq;

    /*cada vez que eh encontrado um elemento menor ou igual ao pivo, pivo_index eh
    incrementado, e esse elemento sera colocado antes do indice do pivo, assim, todos os 
    elementos menores que o pivo ficarao a esquerda de pivo_index e os maiores ficarao a 
    direita*/
    int i;
    for(i = esq; i < dir; i++){
        if(vetor[i] <= pivo){
            troca(vetor[i], vetor[pivo_index]);
            pivo_index++;
        }
    }
    //move o pivo para sua posicao final
    troca(vetor[pivo_index], vetor[dir]);

    //retorna o indice do pivo no vetor
    return pivo_index;
}

int quickselect(int *vetor, int esq, int dir, int k){
    //caso o vetor tenha apenas um elemento, retorna ele
    if(esq == dir){
        return vetor[esq];
    }

    //seleciona aleatoriamente uma posicao pro pivo
    int pivo_index = esq + rand() % (dir - esq + 1);

    pivo_index = particiona(vetor, esq, dir, pivo_index);

    //caso k seja igual a pivo_index, o pivo esta na posicao ordenada
    if(k == pivo_index){
        return vetor[k];
    }

    /*caso k seja menor que o indice do pivo, usa recursao na parte do vetor a esquerda de
    pivo_index*/
    else if(k < pivo_index){
        return quickselect(vetor, esq, pivo_index-1, k);
    }

    /*caso k seja maior que o indice do pivo, usa recursao na parte do vetor a direita de
    pivo_index*/
    else{
        return quickselect(vetor, pivo_index+1, dir, k);
    }
}

//funcao para receber o vetor com numero indeterminado de elementos ate EOF
int* get_vetor(int *n){
    int tam = 0;
    int *vetor = NULL;
    int valor;

    while(scanf("%d", &valor) != EOF){
        if(tam == 0){
            vetor = (int*) malloc(sizeof(int));
        }
        else{
            vetor = (int*) realloc(vetor, (tam+1)*sizeof(int));
        }
        vetor[tam] = valor;
        tam++;
    }

    *n = tam;
    return vetor;
}

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Digite %s -k (valor de k)\n", argv[0]); // exemplo: ./quickselect -k 10
        return 1;
    }
    int k = atoi(argv[2]);

    int n;
    int *vetor = get_vetor(&n);

    printf("%d\n", quickselect(vetor, 0, n-1, k-1));

    free(vetor);
    return 0;
}
