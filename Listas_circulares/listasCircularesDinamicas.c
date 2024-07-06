#include <stdio.h>
#include <stdlib.h>

// como uma lista circular "não tem" começo e nem final usei a conveção em que o ponteiro da lista guarda o endereço do último elemento.

typedef struct no{
    int chave;
    struct no *prox;
}Node;

Node *criaNo(int valor){
    Node *novo = (Node *) calloc(1, sizeof(Node));
    if (novo == NULL){
        printf("Erro de alocação de memoria!");
        exit(1);
    }
    novo->chave = valor;
    return novo;
}

Node *insereInicio(Node *L, int valor){
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

Node *insereFinal(Node *L, int valor){
    Node *novo = criaNo(valor);
    if(L == NULL) novo->prox = novo;
    else {
        novo->prox = L->prox;
        L->prox = novo;
    }
    L = novo;
    return L;
};

Node *excluiInicio(Node *L){
    if (L == NULL || L->prox == L) return NULL;

    Node *aux = L->prox;
    L->prox = aux->prox;
    free(aux);
    
    return L;
}

Node *excluiFinal(Node *L){
    if (L == NULL || L->prox == L) return NULL;
    Node *aux = L->prox,*pred = L;

    while (aux != L)
    {
        pred = aux;
        aux = aux->prox;
    }

    pred->prox = aux->prox;
    L = pred;
    free(aux);
    return L;
}

void imprimeLista(Node *L) {
    printf("\nLista");
    if (L == NULL) {
        printf(" -> Sua lista esta vazia");
        return;
    }
    Node *aux = L->prox;
    do {
        printf(" -> %d", aux->chave);
        aux = aux->prox;
    } while (aux != L->prox);
}

void painelDeOpcoes(Node *L){

    system("clear");
    imprimeLista(L);
    printf("\n\nPossiveis operações:\n");
    printf("0 - Finalizar oprerações\n");
    printf("1 - Inserir no inicio da lista\n");
    printf("2 - Inserir no final da lista\n");
    printf("3 - Excluir no inicio da lista\n");
    printf("4 - Excluir no final da lista\n");
    printf("Por favor, digite qual operação deseja: ");

}

Node *opcoes(Node *L,int escolha){
    
    if(escolha == 0){
        printf("\n**********************************************\nServiço encerrado!\n\nA lista resultante foi:\n");
        imprimeLista(L);
        printf("\n**********************************************\n");
    }
    else if (escolha == 1){
        int valor;
        printf("Digite o valor que deseja adicionar: ");
        scanf("%d", &valor);
        L = insereInicio(L, valor);
    } 
    else if (escolha == 2){
        int valor;
        printf("Digite o valor que deseja adicionar: ");
        scanf("%d", &valor);
        L = insereFinal(L, valor);
    } 
    else if (escolha == 3) L = excluiInicio(L);
    else if (escolha == 4) L = excluiFinal(L);
    return L;
}

int main(void){
    Node *L = NULL;

    int escolha = 1;
    do
    {

        painelDeOpcoes(L);
        scanf("%d", &escolha);

        if (escolha >= 0 && escolha <6) {
            L = opcoes(L, escolha);  
        }

    } while (escolha != 0);
    

    return 0;
}