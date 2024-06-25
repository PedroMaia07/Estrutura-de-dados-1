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

void imprimeLista(Node *L){
    Node *aux = L;
    printf("\nLista");
    
    if (aux == NULL) printf(" -> Sua lista ainda esta vazia");
    while (aux != NULL)
    {
        printf(" -> %d", aux->chave);
        aux = aux->prox;
    }
}

void painelDeOpcoes(){
    printf("\n\nPossiveis operações:\n");
    printf("0 - Finalizar oprerações\n");
    printf("1 - Inseir no inicio da lista\n");
    printf("2 - Inseir no final da lista\n");
    printf("Por favor, digite qual operação deseja: ");

}

Node *opcoes(Node *L,int escolha){
    int valor;
    printf("Digite o valor que deseja adicionar: ");
    scanf("%d", &valor);

    if (escolha == 1) L = insereInicio(L, valor);
    else if (escolha == 2) L = insereFinal(L, valor);
    
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

        if (escolha > 0 && escolha <3) {
            L = opcoes(L, escolha);  
        }
        else{
            system("clear");
            printf("Serviço encerrado!\n\nA lista resultante foi:\n");
            imprimeLista(L);
            printf("\n");
        }
        
        
    } while (escolha != 0);
    

    return 0;
}