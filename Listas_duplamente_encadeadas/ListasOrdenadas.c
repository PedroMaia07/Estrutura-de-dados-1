#include <stdlib.h>
#include  <stdio.h>

typedef struct no
{
    int chave;
    struct no *ant, *prox;
}Node;

Node *criaNo(int valor){
    Node *novo = (Node*) calloc(1, sizeof(Node));
    if (novo == NULL)
    {
        printf("ERRO: problemas com a alocacao de memoria . \n");
        exit(1);
    }
    novo->chave = valor;
    return novo;
    
}

Node *buscaOrd(Node *L, int valor){
    Node *aux = L;
    while (aux != NULL && valor > aux->chave)
    {
        if(aux->prox == NULL) break;
        aux = aux->prox;
    }
    return aux;
}

Node *insereOrd(Node *L, int valor){
    Node *novo = criaNo(valor);
    Node *aux = buscaOrd(L, valor);
    if (aux == NULL) L = novo;
    else{
         if (aux->chave < valor)
         {
            aux->prox = novo;
            novo->ant = aux;
         }
         else {
            novo->prox = aux;
            if(aux->ant == NULL) L = novo;
            else {
                aux->ant->prox = novo;
                novo->ant = aux->ant;
            }
            aux->ant = novo;
         }
    }
    return L;
}


Node *buscaLista(Node *L, int valor){
    Node *aux = L;
    while (aux != NULL && valor != aux->chave)
    {
        if(aux->prox == NULL) break;
        aux = aux->prox;
    }
    return aux;
}

Node *esxcluiChave(Node *L, int valor){
    Node *aux = buscaLista(L,valor);
    if (aux == NULL || aux->chave != valor) printf("A chave nao esta na lista!");
    else
    {
        if (aux != NULL)
        {
            if (aux->ant == NULL) L=aux->prox;
            else aux->ant->prox = aux->prox;
            if(aux->prox != NULL) aux->prox->ant = aux->ant;
            free(aux);
        }
    }
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
    printf("1 - Inserir elemento na lista\n");
    printf("2 - Excluir elemento da lista\n");
    printf("Por favor, digite qual operação deseja: ");

}



Node *opcoes(Node *L,int escolha){
    int valor;
    switch (escolha) {
        case 0:
            printf("\n**********************************************\nServiço encerrado!\n\nA lista resultante foi:\n");
            imprimeLista(L);
            printf("\n**********************************************\n");
            break;
        case 1:
            printf("Digite o valor a inserir: ");
            scanf("%d", &valor);
            L = insereOrd(L,valor);
            break;
        case 2:
            printf("Digite o valor a inserir: ");
            scanf("%d", &valor);
            L = esxcluiChave(L,valor);
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;
    }
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