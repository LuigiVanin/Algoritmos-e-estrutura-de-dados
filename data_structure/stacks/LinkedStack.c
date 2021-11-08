//
// Created by htnek on 07/07/2021.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct no{
    int val;
    struct no *prox;
};

struct linkedstack{
    struct no* topo;
    int qtdade;
};

struct linkedstack* inicializar(){
    struct linkedstack* pilha;
    pilha = (struct linkedstack*) malloc(sizeof(struct linkedstack));
    pilha->qtdade = 0;
    pilha->topo = NULL;
    return pilha;
}

struct no* alocarNovoNo(int valor){
    struct no* topo;
    topo = (struct no*) malloc(sizeof(struct no));
    if(topo == NULL){
        return NULL;
    }
    topo->val = valor;
    topo->prox = NULL;
    return topo;
}

//retornar true se a pilha for nula ou vazia
bool vazia(struct linkedstack* pilha){
    if( pilha == NULL || pilha->qtdade == 0){
        return true;
    }
    else{
        return false;
    }
}

//se a pilha estiver nula, instancie a pilha
//por causa da possibilidade de instanciacao usamos struct linkedstack**
void empilhar(struct linkedstack** pilha, int valor){
    if( vazia(*pilha) ){
        *pilha = inicializar();
        (*pilha)->topo = alocarNovoNo(valor);
    }
    else {
        struct no *aux = (struct no*)malloc(sizeof(struct no));
        aux = alocarNovoNo(valor);
        aux->prox = (*pilha)->topo;
        (*pilha)->topo = aux;
    }
    (*pilha)->qtdade++;
}

//decrementar qtdade se a pilha não estiver nula ou vazia
void desempilhar(struct linkedstack* pilha) {
    if ( pilha == NULL || pilha->qtdade == 0 ){
        pilha = inicializar();
    }
    else{
        struct no* aux = (struct no*) malloc(sizeof(struct no));
        aux = NULL;
        if (pilha->qtdade != 1 ) {
            aux = pilha->topo->prox;
            pilha->topo = aux;
            pilha->qtdade--;
        } else{
            pilha->qtdade--;
            pilha->topo = aux;
        }
    }
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int topo(struct linkedstack* pilha){
    if( pilha == NULL || pilha->qtdade == 0){
        return INT_MIN;
    }
    else{
        return pilha->topo->val;
    }

}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int desempilharRetornando(struct linkedstack* pilha) {
    if( pilha == NULL || pilha->qtdade == 0){
        return INT_MIN;
    }
    else{
        int tmp = topo(pilha);
        desempilhar(pilha);
        return  tmp;
    }
}

void exibirPilha(struct linkedstack* pilha) {
    //usamos o aux para percorrer a lista
    if (!vazia(pilha)) {
        struct no* aux = pilha->topo;
        //navega partindo do topo até chegar NULL
        printf("_\n");
        do {
            printf("%d\n", aux->val);
            aux = aux->prox;
        } while (aux != NULL);
        printf("_");
    }
    else {
        printf("A pilha está vazia!");
    }
}
