//Para rodar o programa use gcc -o teste listasNaoOrdenadas.c


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

Node *excluiChave(Node *L, int valor){
    Node *aux = L;
    Node *pred = NULL;
    if (aux == NULL) return NULL;
    else{
        while (aux != NULL && valor != aux->chave)
        {
            pred = aux;
            aux = aux->prox;
        }
        if (aux == NULL) {
            printf("Chave Não esta na lista\n");
            return L;
        }else{
            if (pred == NULL) L = L->prox;
            else pred->prox = aux->prox;
            free(aux);
            return L;
        }
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

    system("clear");
    printf("\n\nPossiveis operações:\n");
    printf("0 - Finalizar oprerações\n");
    printf("1 - Inserir no inicio da lista\n");
    printf("2 - Inserir no final da lista\n");
    printf("3 - Excluir no inicio da lista\n");
    printf("4 - Excluir no final da lista\n");
    printf("5 - Excluir uma chave especifica da lista\n");
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
    else if (escolha == 5) {
        int valor;
        printf("Digite o valor que deseja adicionar: ");
        scanf("%d", &valor);
        L = excluiChave(L, valor);
    }
    return L;
}

int main(void){
    Node *L = NULL;

    int escolha = 1;
    do
    {
        imprimeLista(L);
        painelDeOpcoes();
        scanf("%d", &escolha);

        if (escolha >= 0 && escolha <6) {
            L = opcoes(L, escolha);  
        }

    } while (escolha != 0);
    

    return 0;
}