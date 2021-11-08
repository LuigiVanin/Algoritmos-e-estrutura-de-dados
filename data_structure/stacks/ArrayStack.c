//
// Created by htnek on 07/07/2021.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct arraystack {
    int* elementos;
    int tamanho;    //tam do array
    int qtdade;     //qtdade de elementos no array
};

struct arraystack* inicializar(int tamArray){
    struct arraystack* pilha = (struct arraystack*) malloc(sizeof(struct arraystack));
    if (tamArray < 0)
        return NULL;
    pilha->qtdade = 0;
    pilha->tamanho = tamArray;
    pilha->elementos = (int*)calloc(tamArray, sizeof(int));
    return pilha;
}

void duplicarCapacidade(struct arraystack* pilha){
    pilha->tamanho = 2*(pilha->tamanho);
    pilha->elementos = (int*) realloc(pilha->elementos, pilha->tamanho * sizeof(int));
}

void empilhar(struct arraystack** pilha, int valor){
    if(*pilha == NULL){
        *pilha = inicializar(10);
    }
    else if((*pilha)->qtdade == (*pilha)->tamanho){
        duplicarCapacidade(*pilha);
    }
    (*pilha)->elementos[(*pilha)->qtdade] = valor;
    ((*pilha)->qtdade)++;
}

bool vazia(struct arraystack* pilha) {
    if( pilha == NULL || pilha->qtdade == 0 ){
        return true;
    }
    else{
        return false;
    }
}

int topo(struct arraystack* pilha){
    if( pilha == NULL || pilha->qtdade == 0 ){
        return INT_MIN;
    }
    else{
        return pilha->elementos[pilha->qtdade - 1];
    }
}

void desempilhar(struct arraystack* pilha){
    if(pilha->qtdade > 0){
        (pilha->qtdade)--;
    }
}

int desempilharRetornando(struct arraystack* pilha){
    if( pilha == NULL || pilha->qtdade == 0 ){
        return INT_MIN;
    }
    int tmp = pilha->elementos[pilha->qtdade - 1];;
    (pilha->qtdade)--;
    return tmp;
}

void imprimir(struct arraystack* pilha){
    printf("_\n");
    for(int i = pilha->qtdade - 1; i >= 0; i--){
        printf("%d\n",pilha->elementos[i]);
    }
    printf("_\n\n");
}
