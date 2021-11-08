//
// Created by htnek on 27/06/2021.
//
#include <stdlib.h>
#include <stdio.h>

void inicializar(int** lista, int capacidade){
    *lista = (int*) calloc(capacidade, sizeof(int));
}

int obterElementoEmPosicao(int* lista, int posicao, int tamanho){
    if (posicao >= 0 && posicao < tamanho){
        return lista[posicao];
    }
}

void duplicarCapacidade(int** lista, int* capacidade) {
    (*lista) = (int*)realloc((*lista), 2 * (*capacidade) * sizeof(int));
    (*capacidade) = (*capacidade) * 2;
}

void inserirElementoNoFim(int** lista, int valor,int* tamanho, int* capacidade){
    if(*tamanho >= *capacidade){
        duplicarCapacidade(lista, capacidade);
    }
    (*lista)[*tamanho] = valor;
    (*tamanho)++;
}

void inserirElementoEmPosicao(int** lista, int valor, int posicao, int* tamanho, int* capacidade) {
    if(*tamanho >= *capacidade){
        duplicarCapacidade(lista, capacidade);
    }

    if(posicao < *tamanho && posicao >= 0){ // posicao <= *tamanho
        (*tamanho)++;
        for(int i = *tamanho - 1; i > posicao; i--){
            (*lista)[i] = (*lista)[i - 1];
        }
        (*lista)[posicao] = valor;
    }
}

void atualizarElemento(int* lista, int valor, int posicao, int tamanho) {
    if (posicao < tamanho && posicao >= 0){
        lista[posicao] = valor;
    }
}

void removerElementoNoFim(int* tamanho) {
    if(*tamanho > 0) {
        (*tamanho)--;
    }
}

void removerElementoEmPosicao(int* lista, int posicao, int* tamanho) {
    if(posicao < *tamanho && posicao > 0){
        for(int i = posicao; i < *tamanho - 1; i++){
            lista[i] = lista[i + 1];
        }
        (*tamanho)--;
    }
}
