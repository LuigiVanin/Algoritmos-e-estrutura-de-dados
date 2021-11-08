//
// Created by htnek on 03/07/2021.
//
#include <stdio.h>
#include <stdlib.h>

struct no{
    int val;
    struct no* prox;
    struct no* ant;
};

void imprimirLista(struct no** cabeca) {
    //usamos o aux para percorrer a lista
    if ((*cabeca) != NULL) {
        struct no* aux = (*cabeca);
        //navega partindo da cabeça até chegar NULL
        printf("[");
        do {
            printf("%d", aux->val);
            aux = aux->prox;
            if (aux != NULL) {
                printf(", ");
            }
        } while (aux != NULL);
        printf("]");
    }
    else {
        printf("A lista está vazia!");
    }
}

struct no* alocarNovoNo(int valor){
    struct no* cabeca;
    cabeca = (struct no*)malloc(sizeof(struct no));
    if(cabeca == NULL){
        return NULL;
    }
    cabeca->val = valor;
    cabeca->prox = NULL;
    cabeca->ant = NULL;
    return cabeca;
}

void inserirElementoNoFim(struct no **cabeca, int valor, int* tamanho){
    if(*cabeca != NULL) {
        if (*tamanho == 0) {
            *cabeca = alocarNovoNo(valor);
            (*tamanho)++;
        }
        else{
            struct no* aux;
            aux = *cabeca;
            while (aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = alocarNovoNo(valor);
            aux->prox->ant = aux;
            (*tamanho)++;
        }
    }
}
