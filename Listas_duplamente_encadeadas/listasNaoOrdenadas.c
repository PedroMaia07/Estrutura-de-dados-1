#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int chave;
    struct no *prox, *ant;
}Node;

Node * criaNo(int valor){
    Node *novo = (Node*) calloc(1,sizeof(Node));
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
    if(L != NULL) L->ant = novo;
    return novo;
}

Node *insereFinal(Node *L, int ch){
    Node *novo = criaNo(ch);
    Node *aux = L;
    if (L == NULL) L = novo;
    else
    {
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
    }
    return L;
}

Node *excluiInicio(Node *L){
    Node *aux = L;
    if(L == NULL) return NULL;
    L = aux->prox;
    if(L != NULL) L->ant = NULL;
    free(aux);
    return L;
}

Node *excluiFinal(Node *L){
    Node *aux = L;
    if(L == NULL) return NULL;
    while (aux->prox != NULL) aux = aux->prox;
    if (aux->ant == NULL) L = NULL;
    else aux->ant->prox = NULL;
    free(aux);
    return L;
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