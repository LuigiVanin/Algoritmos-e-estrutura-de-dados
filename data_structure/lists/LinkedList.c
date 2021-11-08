//
// Created by htnek on 27/06/2021.
//
#include <stdlib.h>
#include <stdio.h>

struct no{
    int val;
    struct no* prox;
};

void imprimirLista(struct no **cabeca){
    if((*cabeca) != NULL){
        struct no *aux = (*cabeca);
        do{
            printf("%d\n", aux->val);
            aux = aux->prox;
        } while (aux != NULL);
    } else{
        printf("A lista está vazia!\n");
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
    return cabeca;
}

void inserirElementoNoFim(struct no** cabeca, int valor, int* tamanho){
    if((*tamanho) != 0) {
        struct no *aux = (*cabeca);
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = alocarNovoNo(valor);
        (*tamanho)++;
    } else if(tamanho < 0){
        printf("erro tamanho negativo");
    }
    else {
        (*tamanho)++;
        (*cabeca) = alocarNovoNo(valor);
    }
}

void inserirElementoNoInicio(struct no **cabeca, int valor, int* tamanho){
    if(*tamanho != 0){
        struct no* aux;
        aux = (struct no*)malloc(sizeof(struct no));
        aux->val = valor;
        aux->prox = (*cabeca);
        (*cabeca) = aux;
        (*tamanho)++;
    }
    else {
        (*cabeca) = alocarNovoNo(valor);
        (*tamanho)++;
    }
}

void inserirElementoEmPosicao(struct no **cabeca,int valor, int posicao, int* tamanho){
    if(posicao >= 0 && posicao < (*tamanho) && (*tamanho) > 0){
        struct no *aux = *cabeca;
        struct no *tmp = (struct no *) malloc(sizeof(struct no));
        tmp->val = valor;
        tmp->prox = NULL;
        for (int i = 0; i < posicao - 1; i++) {
            if (aux->prox != NULL) {
                aux = aux->prox;
            }
        }
        tmp->prox = aux->prox;
        aux->prox = tmp;

        (*tamanho)++;
    }
}

int obterElementoEmPosicao(struct no **cabeca, int posicao) {
    if(posicao >= 0 && *cabeca != NULL){
        struct no* aux = (*cabeca);
        for (int i = 0; i < posicao; i++) {
            if (aux->prox != NULL) {
                aux = aux->prox;
            }
        }
        return aux->val;
    }
}

void removerElementoEmPosicao(struct no **cabeca, int posicao, int* tamanho) {
    if(posicao >= 0 && posicao < (*tamanho) && (*tamanho) > 0) {
        if(posicao == 0){
            struct no *aux = *cabeca;
            (*cabeca) = (*cabeca)->prox;
            free(aux);
            (*tamanho)--;
        }
        else {
            struct no *aux = *cabeca;
            struct no *tmp;
            for (int i = 0; i < posicao; i++) {
                tmp = aux;
                aux = aux->prox;
                if (aux == NULL) {
                    return;
                }
            }
            tmp->prox = aux->prox;
            free(aux);
            (*tamanho)--;
        }
    }
}
