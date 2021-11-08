//
// Created by htnek on 08/07/2021.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct arrayqueue {
    int frente;
    int tras;
    int* elementos;
    int tamanho;    //tam do array
    int qtdade;     //qtdade de elementos no array
};

struct arrayqueue* inicializar(int tamanho){
    struct arrayqueue* fila = (struct arrayqueue*) malloc(sizeof(struct arrayqueue));
    fila->qtdade = 0;
    fila->tamanho = tamanho;
    fila->frente = -1;
    fila->tras = -1;
    fila->elementos = (int*) calloc((*fila).tamanho, sizeof(int));
    return fila;
}

//se a fila estiver nula, instancie a fila com tamanho 10
//por causa da possibilidade de instanciacao usamos struct arrayqueue**
//se a fila encher, simplesmente não enfileire
void enfileirar(struct arrayqueue** fila, int val) {
    if ( (*fila) == NULL ){
        (*fila) = inicializar(10);
        printf("none?\n");
        enfileirar(fila, val);
    }
    else if (( (*fila)->qtdade < (*fila)->tamanho )) {
        if((*fila)->qtdade == 0){
            (*fila)->frente++;
        }
        (*fila)->tras = ((*fila)->tras + 1) % (*fila)->tamanho;
        (*fila)->qtdade++;
        (*fila)->elementos[(*fila)->tras] = val;
    }
    else{
        printf("a fila está cheia!\n");
    }
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int desenfileirar(struct arrayqueue* fila) {
    if ( fila == NULL || fila->qtdade <= 0){
        return INT_MIN;
    }
    else{
        int tmp = fila->elementos[fila->frente];
        fila->frente = (fila->frente + 1) % fila->tamanho;
        fila->qtdade--;
        return tmp;
    }
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int frente(struct arrayqueue* fila) {
    if ( fila == NULL || fila->qtdade == 0){
        return INT_MIN;
    }
    else{
        return fila->elementos[fila->frente];
    }
}

void exibirLista(struct arrayqueue* lista) {
    printf("_\n");
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d\n", lista->elementos[i]);
    }
    printf("_\n");
}
