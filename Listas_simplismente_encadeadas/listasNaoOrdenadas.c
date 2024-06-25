#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
}Node;

Node *criaNo(int valor){
    Node *novo;
    novo = (Node*) calloc(1, sizeof(Node));
    if (novo == NULL)
    {
        printf("ERRO: problemas com a alocacao de memoria . \n");
        exit(1);
    }
    novo->chave = valor;
    return novo;
}

Node *insereInicio(Node *L, int valor){
    Node *novo = criaNo(valor);
    novo->prox = L;
    L = novo;
    return L;
}

Node *insereFinal(Node *L, int valor){
    Node *novo = criaNo(valor);
    Node *aux = L;
    if (aux == NULL) L = novo;
    else{
        while (aux->prox != NULL)
        {   
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    return L;
}

Node *excluiInicio(Node *L){
    Node *aux = L;
    if(aux == NULL) return NULL;
    else{
        L = L->prox;
        free(aux);
        return L;
    }
}

Node *excluiFinal(Node *L){
    Node *aux = L;
    Node *pred = NULL;
    if (aux == NULL) return NULL;
    else{
        while (aux->prox != NULL)
        {
            pred = aux;
            aux = aux->prox;
        }
        if (pred == NULL) L = NULL;
        else pred->prox = NULL;
        free(aux);
        return L;
    }
}




void imprimeLista(Node *L){
    Node *aux = L;
    printf("\nLista");
    
    if (aux == NULL) printf(" -> Sua lista esta vazia");
    while (aux != NULL)
    {
        printf(" -> %d", aux->chave);
        aux = aux->prox;
    }
}




void painelDeOpcoes(){

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

int main(){
    Node *L = NULL;

    int escolha = 1;
    do
    {
        system("clear");
        imprimeLista(L);
        painelDeOpcoes();
        scanf("%d", &escolha);

        if (escolha >= 0 && escolha <5) {
            L = opcoes(L, esc        }

    } while (escolha != 0);
    

    return 0;
}