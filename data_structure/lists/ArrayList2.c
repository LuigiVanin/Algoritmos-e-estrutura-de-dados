//
// Created by htnek on 03/07/2021.
//
#include <stdlib.h>
#include <stdio.h>

struct arraylist {
    int* vetor;
    int qtdade;
    int capacidade;
};

void exibirLista(struct arraylist* lista) {
    printf("[");
    for (int i = 0; i < lista->qtdade; i++) {
        printf("%d", lista->vetor[i]);
        if (i < lista->qtdade - 1) {
            printf(", ");
        }
    }
    printf("]");
}

struct arraylist* inicializar(int capacidade) {
    struct arraylist* lista = (struct arraylist*)malloc(sizeof(struct arraylist));
    lista->vetor = (int*)calloc(capacidade, sizeof(int));
    lista->qtdade = 0;
    lista->capacidade = capacidade;
    return lista;
}

void duplicarCapacidade(struct arraylist* lista) {
    lista->capacidade = 2*(lista->capacidade);
    lista->vetor = (int*) realloc(lista->vetor, lista->capacidade * sizeof(int));
}

void inserirElementoNoFim(struct arraylist* lista, int valor) {
    if(lista->qtdade >= lista->capacidade){
        duplicarCapacidade(lista);
    }
    lista->vetor[lista->qtdade] = valor;
    (lista->qtdade)++;
}

void inserirElementoEmPosicao(struct arraylist* lista, int valor, int posicao) {
    if(lista->qtdade >= lista->capacidade){
        duplicarCapacidade(lista);
    }

    if(posicao <= lista->qtdade && posicao >= 0 && lista->qtdade > 0){ // posicao <= *tamanho
        (lista->qtdade)++;
        for(int i = lista->qtdade - 1; i > posicao; i--){
            (lista->vetor)[i] = (lista->vetor)[i - 1];
        }
        (lista->vetor)[posicao] = valor;
    }
    else if(posicao == 0 && lista->qtdade == 0){
        inserirElementoNoFim(lista, valor);
    }
}

void atualizarElemento(struct arraylist* lista, int valor, int posicao) {
    if (posicao < lista->qtdade && posicao >= 0){
        (lista->vetor)[posicao] = valor;
    }
}

void removerElementoNoFim(struct arraylist* lista) {
    if(lista->qtdade > 0) {
        (lista->qtdade)--;
    }
}

void removerElementoEmPosicao(struct arraylist* lista, int posicao) {
    if(posicao < lista->qtdade && posicao >= 0){
        for(int i = posicao; i < (lista->qtdade) - 1; i++){
            (lista->vetor)[i] = (lista->vetor)[i + 1];
        }
        (lista->qtdade)--;
    }
}

int obterElementoEmPosicao(struct arraylist* lista, int posicao) {
    if (posicao >= 0 && posicao < lista->qtdade){
        return (lista->vetor)[posicao];
    }
}

void inverter(struct arraylist* lista){
    int* tmp = (int *) calloc(lista->capacidade, sizeof(int));
    for (int i = lista->qtdade - 1; i >= 0; i--){
        tmp[i] = lista->vetor[(lista->qtdade - 1) - i];
    }
    free(lista->vetor);
    lista->vetor = tmp;
}
