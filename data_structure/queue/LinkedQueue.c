//
// Created by htnek on 08/07/2021.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct no {
    int val;
    struct no* prox;
};

struct linkedqueue {
    struct no* frente;
    struct no* tras;
    int qtdade;
};

struct linkedqueue* inicializar() {
    struct linkedqueue* fila;
    fila = (struct linkedqueue*) malloc(sizeof(struct linkedqueue));
    fila->qtdade = 0;
    fila->tras = NULL;
    fila->frente = NULL;
    return fila;
}

struct no* alocarNovoNo(int valor) {
    struct no* cabeca = (struct no*) malloc(sizeof(struct no));
    cabeca->val = valor;
    cabeca->prox = NULL;
    return cabeca;
}

bool vazia(struct linkedqueue* fila) {
    if( fila == NULL || fila->qtdade == 0){
        return true;
    }
    else{
        return false;
    }
}

//se a fila estiver nula, instancie a fila
//por causa da possibilidade de instanciacao usamos struct linkedqueue**
void enfileirar(struct linkedqueue** fila, int val) {
    if( (*fila) == NULL || (*fila)->qtdade == 0){
        (*fila) = inicializar();
        (*fila)->frente = alocarNovoNo(val);
        (*fila)->tras = (*fila)->frente;
    }
    else{
        struct no* cabeca = (*fila)->tras;
        cabeca->prox = alocarNovoNo(val);
        cabeca = cabeca->prox;
        (*fila)->tras = cabeca;
    }
    (*fila)->qtdade++;
}

//retorne a constante INT_MIN se a fila for nula ou vazia
//lembrem de desalocar o nó removido (free)
int desenfileirar(struct linkedqueue* fila) {
    if ( fila == NULL || fila->qtdade == 0){
        return INT_MIN;
    }
    else{
        struct no* aux = fila->frente;
        int tmp = aux->val;
        if(aux->prox != NULL){
            aux = aux->prox;
            free(fila->frente);
            fila->frente = aux;
        }
        else{
            fila->frente = NULL;
            fila->tras = NULL;
            free(fila->frente);
        }
        fila->qtdade--;
        return tmp;
    }
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int frente(struct linkedqueue* fila) {
    if ( fila == NULL || fila->qtdade == 0){
        return INT_MIN;
    }
    else{
        return fila->frente->val;
    }
}

void imprimirLista(struct linkedqueue* fila) {
    //usamos o aux para percorrer a lista
    if (fila->frente != NULL) {
        struct no* aux = fila->frente;
        //navega partindo da cabeça até chegar NULL
        printf("_\n");
        do {
            printf("%d", aux->val);
            aux = aux->prox;
            if (aux != NULL) {
                printf("\n ");
            }
        } while (aux != NULL);
        printf("\n_\n");
    }
    else {
        printf("A lista está vazia!");
    }
}
