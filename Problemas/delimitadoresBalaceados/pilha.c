#include "pilha.h"

cabeca *criapilha(){
    cabeca *novo = ((cabeca *) calloc(1, sizeof(cabeca)));
    if (novo == NULL)
    {
        printf("ERRO NA ALOCAÇAO");
        exit(1);
    }
    return novo;

} pilha *criano(char carac){
    pilha *novo = ((pilha *) calloc(1, sizeof(pilha)));
    if (novo == NULL)
    {
        printf("ERRO NA ALOCAÇAO");
        exit(1);
    }
    novo->caracter = carac;
    return novo;
}

cabeca *empilha(cabeca *p, char carac){
    pilha *novo = criano(carac);
    pilha *aux= p->prox;
    if(p->prox==NULL){
        p->prox= novo;
        p->ant=novo;
    }else{
        novo->prox= aux;
        aux->ant = novo;
        p->prox = novo;
    }
    p->quant ++;
    return p;
}

void desempilha(cabeca *p){
    pilha *aux = p->prox;
    if (aux==NULL)
    {
        printf("lista esta vazia");
    }else{
        if (aux->prox!=NULL)
        {
            p->prox=aux->prox;
            aux->prox->ant = NULL;
        }else
        {
            p->prox = NULL;
            p->ant = NULL;  
        }
        free(aux);
        p->quant --;
    }
}

void imprime(cabeca *p){
    printf("%d -", p->quant);
    pilha *aux = p->prox;
    while (aux!=NULL)
    {
        printf("%c -",aux->caracter);
        aux=aux->prox;
    }
}