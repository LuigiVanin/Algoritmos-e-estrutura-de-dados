//
// Created by htnek on 07/07/2021.
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
    else if ( (*fila)->qtdade < (*fila)->tamanho ){
        if((*fila)->qtdade == 0){
            (*fila)->frente++;
        }
        (*fila)->elementos[(*fila)->qtdade] = val;
        (*fila)->qtdade++;
        (*fila)->tras++;
    }
    else{
        printf("a fila está cheia!\n");
    }
}
//retorne a constante INT_MIN se a fila for nula ou vazia
int desenfileirar(struct arrayqueue* fila) {
    if ( fila == NULL || fila->qtdade == 0){
        return INT_MIN;
    }
    else if(fila->qtdade > 0 && fila->qtdade){
        int* tmp = (int*)calloc(fila->qtdade, sizeof(int));
        for(int i = 0; i < fila->qtdade - 1; i++){
            tmp[i] = fila->elementos[i + 1];
        }
        free(fila->elementos);
        fila->elementos = tmp;
        fila->qtdade--;
        if(fila->qtdade > 1){
            fila->frente++;

        }
        else{
            fila->frente = -1;
            fila->tras = -1;
        }

        return fila->elementos[0];
    }
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int frente(struct arrayqueue* fila) {
    if ( fila == NULL || fila->qtdade == 0){
        return INT_MIN;
    }
    else{
        return fila->elementos[fila->qtdade - 1];
    }
}

void exibirLista(struct arrayqueue* lista) {
    printf("[");
    for (int i = 0; i < lista->qtdade; i++) {
        printf("%d", lista->elementos[i]);
        if (i < lista->qtdade - 1) {
            printf(",\n ");
        }
    }
    printf("]\n");
}
