#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//funcao do bubblesort
void bubbleSort(int *vetor, int dim){

    int i, j, aux;

    for(i = 0; i < dim; i++){
        for(j = 0; j < dim - 1; j++){
            //troca a proxima posicao do vetor com a atual caso ela (a proxima) seja menor
            if(vetor[j] > vetor[j + 1]){
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }

}

//funcao do quicksort
void quickSort(int *vetor, int inicio, int fim){

    int pivo;

    if(fim > inicio){
        pivo = particiona(vetor, inicio, fim); //separa o vetor em 2 partes (antes e depois do pivo)
        quickSort(vetor, inicio, pivo - 1); //chama a funcao recursivamente para a primeira parte do vetor (antes do pivo)
        quickSort(vetor, pivo + 1, fim); //chama a funcao recursivamente para a segunda parte do vetor (depois do pivo)
    }

}

//funcao para separar o vetor em 2 partes (antes e depois do pivo)
int particiona(int *vetor, int inicio, int fim){

    int esquerda, direita, pivo, aux;

    esquerda = inicio; //esquerda comeca no inicio
    direita = fim; //direita comeca no fim
    pivo = vetor[inicio]; //pivo comeca no inicio do vetor

    while(esquerda < direita){
        //esquerda avanca ate a primeiro casa do vetor com valor maior que o pivo
        while(vetor[esquerda] <= pivo){
            esquerda++;
        }
        //direita recua ate a primeira casa do vetor (da direita pra esquerda) com valor menor ou igual ao pivo
        while(vetor[direita] > pivo){
            direita--;
        }
        //se esquerda for menor que direita, troca os valores das casas do vetor de lugar
        if(esquerda < direita){
            aux = vetor[esquerda];
            vetor[esquerda] = vetor[direita];
            vetor[direita] = aux;
        }
    }
    vetor[inicio] = vetor[direita]; //coloca o valor da casa direita do vetor no inicio
    vetor[direita] = pivo; //coloca o valor do pivo na casa direita

    //retorna o valor de direita para ser o pivo no quicksort
    return direita;

}

//funcao do mergesort
void mergeSort(int *vetor, int inicio, int fim){

    int meio;
    if(inicio < fim){
        meio = floor((inicio + fim) / 2); //calcula o meio do vetor
        mergeSort(vetor, inicio, meio); //chama a funcao recursivamente para a primeira metade do vetor
        mergeSort(vetor, meio + 1, fim); //chama a funcao recursivamente para a segunda metade do vetor
        merge(vetor, inicio, meio, fim); //combina as duas metades do vetor de forma ordenada
    }

}

//funcao para combinar as duas metades do vetor de forma ordenada
void merge(int *vetor, int inicio, int meio, int fim){

    int *temp, p1, p2, tam, i, j, k, fim1 = 0, fim2 = 0;

    tam = fim - inicio + 1;
    p1 = inicio; //p1 comeca no inicio do vetor
    p2 = meio + 1; //p2 comeca no meio do vetor
    temp = (int *) malloc(tam * sizeof(int)); //vetor temporario para auxiliar no programa

    if (temp != NULL){
        for(i = 0; i < tam; i++){
            //caso p1 nao tenha chegado ao meio ou p2 nao tenha chegado ao final do vetor
            if(!fim1 && !fim2){
                //caso o valor na posicao p1 do vetor seja menor que o da posicao p2, copia ele para a posicao i do vetor temporario e adiciona 1 a p1 (anda p1 para a proxima casa do vetor)
                if(vetor[p1] < vetor[p2]){
                    temp[i] = vetor[p1];
                    p1++;
                }
                //caso contrario, copia o valor da posicao p2 do vetor para a posicao i do vetor temporario e adiciona 1 a p2 (anda p2 para a proxima casa do vetor)
                else{
                    temp[i] = vetor[p2];
                    p2++;
                }
                if(p1 > meio){
                    fim1 = 1; //indica que p1 chegou ao meio do vetor
                }
                if(p2 > fim){
                    fim2 = 1; //indica que p2 chegou ao fim do vetor
                }
            }
            //caso p1 ja tenha chegado no meio ou p2 ja tenha chegado no fim do vetor
            else{
                //caso p2 ja tenha chegado no fim do vetor
                if(!fim1){
                    temp[i] = vetor[p1]; //copia o restante da primeira metade do vetor no vetor temporario
                    p1++;
                }
                else{
                    temp[i] = vetor[p2]; //copia o restante da segunda metade do vetor no vetor temporario
                    p2++;
                }
            }
        }
        //copia o vetor temporario no vetor principal
        for(j = 0, k = inicio; j < tam; j++, k++){
            vetor[k] = temp[j];
        }
    }
    free(temp); //libera o vetor temporario

}

//funcao principal
int main(int argc, char* argv[]){

    int *vetor, dim, i;

    if(argc != 4){
        printf("Digite: %s -n (tamanho do vetor) (-q para quicksort, -m para mergesort ou -n para bubblesort)\n", argv[0]); //exemplo: ./ordena -n 1000 -q (quicksort de vetor de tamanho 1000)
        return 1;
    }
    dim = atoi(argv[2]);

    vetor = malloc(dim * sizeof(int));

    //da valores aleatorios ao vetor
    srand(time(NULL));
    for(i = 0; i < dim; i++){
        vetor[i] = rand() % dim;
    }

    //mergesort
    if(argv[3] == "-m"){
        mergeSort(vetor, 0, dim - 1);
    }

    //quicksort
    if(argv[3] == "-q"){
        quickSort(vetor, 0, dim - 1);
    }

    //bubblesort
    if(argv[3] == "-n"){
        bubbleSort(vetor, dim);
    }

    //printa o vetor
    for(i = 0; i < dim; i++){
        printf("%d\n", vetor[i]);
    }

    return 0;

}
