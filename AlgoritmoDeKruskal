#include <stdio.h>
#include <stdlib.h>

//estrutura da aresta
typedef struct Aresta{
    int fonte, destino, peso;
}Aresta;

//estrutura do grafo
typedef struct Grafo{
    int numVertice, numAresta;
    Aresta* aresta;
}Grafo;

//estrutura de um subconjunto pro Union-Find
typedef struct Subconjunto{
    int pai, rank;
}Subconjunto;

//funcao para criar um grafo
Grafo* criarGrafo(int v, int a){
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertice = v;
    grafo->numAresta = a;
    grafo->aresta = (Aresta*)malloc(a * sizeof(Aresta));
    return grafo;
}

//funcao para retornar a diferenca de peso entre duas arestas
int compare(const void* a, const void* b){
    Aresta* a1 = (Aresta*)a;
    Aresta* b1 = (Aresta*)b;
    return a1->peso - b1->peso;
}

//funcao para encontrar o conjunto de um elemento v
int find(Subconjunto subconjuntos[], int v){
    if(subconjuntos[v].pai != v){
        subconjuntos[v].pai = find(subconjuntos, subconjuntos[v].pai);
    }
    return subconjuntos[v].pai;
}

//funcao para realizar a uniao de dois conjuntos x e y
void Union(Subconjunto subconjuntos[], int x, int y){
    int raizX = find(subconjuntos, x);
    int raizY = find(subconjuntos, y);

    if(subconjuntos[raizX].rank < subconjuntos[raizY].rank){
        subconjuntos[raizX].pai = raizY;
    }
    else if(subconjuntos[raizX].rank > subconjuntos[raizY].rank){
        subconjuntos[raizY].pai = raizX;
    }
    else{
        subconjuntos[raizY].pai = raizX;
        subconjuntos[raizX].rank++;
    }
}

//funcao para encontrar a arvore geradora minima
void kruskal(Grafo* grafo){
    int v = grafo->numVertice;
    Aresta resultado[v];
    int e = 0;
    int i = 0;
    int pesoTotal = 0;

    qsort(grafo->aresta, grafo->numAresta, sizeof(grafo->aresta[0]), compare);

    Subconjunto* subconjuntos = (Subconjunto*)malloc(v * sizeof(Subconjunto));

    int k;
    for(k = 0; k < v; k++){
        subconjuntos[v].pai = v;
        subconjuntos[v].rank = 0;
    }

    while(e < v-1 && i < grafo->numAresta){
        Aresta proximaAresta = grafo->aresta[i++];

        int x = find(subconjuntos, proximaAresta.fonte);
        int y = find(subconjuntos, proximaAresta.destino);

        if(x != y){
            resultado[e++] = proximaAresta;
            Union(subconjuntos, x, y);
            pesoTotal += proximaAresta.peso;
        }
    }

    printf("Soma dos pesos das arestas da árvore geradora mínima: %d", pesoTotal);
    
}

int main(){
    int v, a, i;
    printf("Digite o numero de vertices e arestas do grafo: ");
    scanf("%d %d", &v, &a);

    Grafo* grafo = criarGrafo(v,a);

    printf("Digite a fonte, o destino e o peso das arestas do grafo:\n");
    for(i = 0; i < a; i++){
        scanf("%d %d %d", &grafo->aresta[i].fonte, &grafo->aresta[i].destino, &grafo->aresta[i].peso);
    }

    kruskal(grafo);

    free(grafo);
    free(grafo->aresta);

    return 0;
}
