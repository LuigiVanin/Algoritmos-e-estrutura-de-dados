//
// Created by htnek on 04/07/2021.
//
#include <stdlib.h>
#include <stdio.h>

struct no{
    int val;
    struct no* prox;
    struct no* ant;
};

struct doublylinkedlist {
    struct no* cabeca;
    struct no* cauda;
    int qtdade;
};

struct doublylinkedlist* inicializar() {
    struct doublylinkedlist* lista;
    lista = (struct doublylinkedlist*) malloc(sizeof(struct doublylinkedlist));
    lista->qtdade = 0;
    return lista;
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

void inserirElementoNoFim(struct doublylinkedlist* lista, int valor){
    if(lista->cabeca != NULL) {
        if (lista->qtdade == 0) {
            lista->cabeca = alocarNovoNo(valor);
            (lista->qtdade)++;
        }
        else{
            struct no* aux;
            aux = lista->cabeca;
            while (aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = alocarNovoNo(valor);
            aux->prox->ant = aux;
            (lista->qtdade)++;
        }
    }
}

void inserirElementoNoInicio(struct doublylinkedlist* lista, int valor) {
    struct no* temp1 = alocarNovoNo(valor);

    if (lista->cabeca != NULL) {
        struct no* temp2 = lista->cabeca;

        temp2->ant = temp1;
        temp1->prox = temp2;
        lista->cabeca = temp1;
        lista->qtdade++;
    }
    else {
        lista->cabeca = temp1;
        lista->cauda = temp1;
        lista->qtdade++;
    }
}

void inserirElementoEmPosicao(struct doublylinkedlist* lista, int valor, int posicao) {
    struct no* temp1 = alocarNovoNo(valor);

    if (posicao == 0) {
        inserirElementoNoInicio(lista, valor);
    }
    else if (posicao > lista->qtdade - 1) {
        inserirElementoNoFim(lista, valor);
    }
    else {
        struct no* temp2 = lista->cabeca;

        for (int i = 0; i < posicao - 1; i++) {
            temp2 = temp2->prox;
        }

        temp1->ant = temp2;
        temp1->prox = temp2->prox;
        struct no* temp3 = temp2->prox;
        temp3->ant = temp1;
        temp2->prox = temp1;

        lista->qtdade++;
    }
}

int obterElementoEmPosicao(struct doublylinkedlist* lista, int posicao) {
    if (posicao >= 0 && lista->cabeca != NULL) {
        struct no* temp1 = lista->cabeca;

        for (int i = 0; i < posicao; i++) {
            if (temp1->prox == NULL) {
                return temp1->val;
            }

            temp1 = temp1->prox;
        }

        return temp1->val;
    }
}

void removerElementoEmPosicao(struct doublylinkedlist* lista, int posicao) {
    struct no* temp1 = lista->cabeca;
    struct no* temp3 = lista->cauda;
    struct no* temp2 = temp1;

    if (posicao == 0) {
        lista->cabeca = lista->cabeca->prox;
        temp2->ant = lista->cabeca;

        free(temp1);
        lista->qtdade--;
    }
    else if (posicao >= lista->qtdade - 1) {
        lista->cauda = temp3->ant;
        temp2 = temp3->ant;
        temp2->prox = NULL;

        free(temp3);
        lista->qtdade--;
    }
    else {
        for (int i = 0; i < posicao - 1; i++) {
            temp1 = temp1->prox;
        }

        temp2 = temp1->prox;
        temp3 = temp2->prox;
        temp1->prox = temp3;
        temp3->ant = temp1;
        free(temp2);
        lista->qtdade--;
    }
}

void imprimirLista(struct no** cabeca) {
    //usamos o aux para percorrer a lista
    if ((*cabeca) != NULL) {
        struct no* aux = (*cabeca);
        //navega partindo da cabe??a at?? chegar NULL
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
        printf("A lista est?? vazia!");
    }
}