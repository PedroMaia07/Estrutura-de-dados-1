#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
*Como o problema foi passando dentro da materia de lista circular dinamica, essa foi minha escolha de estrutura de dados 
  e como uma lista circular "não tem" começo e nem final usei a conveção da aula, em que o ponteiro da lista guarda o endereço do último elemento.

*Se quiser outra lista de nome como dado inicial, é so chamar a função insereInicio quantas vezes quiser e com qualquer nome
  OBS: se atente em colocar um nome com menos de 20 caracteres
*/

///////////////////// criando as entradas do programa /////////////////////
typedef struct no{
    char nome[21];
    struct no *prox;
}Node;

Node *criaNo(char valor[]){
    Node *novo = (Node *) calloc(1, sizeof(Node));
    if (novo == NULL){
        printf("Erro de alocação de memoria!");
        exit(1);
    }
    strcpy(novo->nome, valor);
    return novo;
}

Node *insereInicio(Node *L, char valor[]){
    Node *novo = criaNo(valor);
    if(L == NULL) {
        novo->prox = novo;
        L= novo;
    }
    else {
        novo->prox = L->prox;
        L->prox = novo;
    }
    return L;
};

void imprimeLista(Node *L) {
    if (L == NULL) return;
    Node *aux = L->prox;
    printf("\nLista");
    do {
        printf(" -> %s", aux->nome);
        aux = aux->prox;
    } while (aux != L->prox);
}

int numeroAleatorio(Node *L){
    Node *aux = L->prox;
    int min = 1, max=0, num;
    do{
        max ++;
        aux = aux->prox;
    }while (strcmp(aux->nome, L->prox->nome) != 0);

    srand(time(NULL));
    num = (rand() % (max - min + 1)) + min;
    return num;
}


////////////// Resolvendo o problema  //////////////////////
Node *excluiSoldado(Node *L, int n) {
    if (L == NULL || L->prox == L) return NULL; 
    
    Node *aux = L->prox;
    Node *pred = L;
    
    for (int i = 2; i < n; i++) {        // Comeca em 2 por causa que o aux comeca no segundo nome. 
        pred = aux;
        aux = aux->prox;
    }

    printf("\n\nSoldado eliminado = %s", aux->nome);
    pred->prox = aux->prox;
    if (aux == L) L = L->prox;
    free(aux);
    return L;
}

int main(void) {
    Node *L = NULL;
    int n;

    ////////////// entradas /////////////////
    L = insereInicio(L, "pedro");  //Vai ser o começo da lista incial
    L = insereInicio(L, "joao");
    L = insereInicio(L, "caio");
    L = insereInicio(L, "breno");
    L = insereInicio(L, "isabela");
    L = insereInicio(L, "carlos");
    L = insereInicio(L, "renan");
    printf("Lista inicial :\n");
    imprimeLista(L);
    n = numeroAleatorio(L);                   //se quiser que o numero n mude em toda "rodada" é so colocar dentro do while
    printf("\n\nNúmero N= %d\n", n);

    //////////// resolucao do problema /////////////////
    while (L->prox != L) {
        L = excluiSoldado(L, n);
        imprimeLista(L);
    }
    printf("\n\nÚltimo soldado: %s\n", L->nome);
    free(L);
    
    
    return 0;
}