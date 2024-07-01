#include <stdio.h>
#include <stdlib.h>

typedef struct cabeca  //criei outro struct para o nó cabeça.Porem, é possivel usar apenas um struct para todos os nós
{
    int quantidade;
    struct no *prox;
    struct no *ultimo; //Esse struct mostra duas utilidades do no cabeça: guardar a quantidade de nós na lista e apontar para o ultimo elemento da lista
}Cabeca;

Cabeca *criaLista(){   //Essa função só vai ser usada uma vez, quando for inicialiar o lista na função main
    Cabeca *novo;
    novo = (Cabeca*) calloc(1,sizeof(Cabeca));
    if (novo == NULL)
    {
        printf("ERRO: problemas com a alocacao de memoria . \n");
        exit(1);
    }
    return novo;
}

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

void insereInicio(Cabeca *L, int valor){
    Node *novo = criaNo(valor);
    novo->prox = L->prox;
    L->prox = novo;
    if (L->quantidade == 0) L->ultimo = novo;
    L->quantidade ++;
}

void insereFinal(Cabeca *L, int valor){
    Node *novo = criaNo(valor);
    if (L->quantidade == 0) L->prox = novo;
    else L->ultimo->prox = novo;
    L->ultimo = novo;
    L->quantidade ++;
}

void excluiInicio(Cabeca *L){
    Node *aux = L->prox;
    if (L->quantidade != 0)
    {
        L->prox = aux->prox;
        free(aux);
        L->quantidade --;
        if (L->quantidade == 0) L->ultimo = NULL;
    }
}

void excluiFinal(Cabeca *L){
    Node *aux = L->prox;
    Node *pred = NULL;
    if (L->quantidade != 0)
    {      
        while(aux->prox != NULL)
        {
            pred = aux;
            aux = aux->prox;
        }
        if (pred == NULL) L->prox = NULL;
        else pred->prox = NULL;
        free(aux);
        L->ultimo = pred;
        L->quantidade --;
    }
}


void imprimeLista(Cabeca *L){
    Node *aux = L->prox;
    printf("Lista -> |%d|", L->quantidade);
    while (aux != NULL)
    {
        printf(" -> %d", aux->chave);
        aux = aux->prox;
    }
}

void painelDeOpcoes(Cabeca *L){
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

void opcoes(Cabeca *L,int escolha){
    
    if(escolha == 0){
        printf("\n**********************************************\nServiço encerrado!\n\nA lista resultante foi:\n");
        imprimeLista(L);
        printf("\n**********************************************\n");
    }
    else if (escolha == 1){
        int valor;
        printf("Digite o valor que deseja adicionar: ");
        scanf("%d", &valor);
        insereInicio(L, valor);
    } 
    else if (escolha == 2){
        int valor;
        printf("Digite o valor que deseja adicionar: ");
        scanf("%d", &valor);
        insereFinal(L, valor);
    } 
    else if (escolha == 3) excluiInicio(L);
    else if (escolha == 4) excluiFinal(L);
}

int main(void){
    Cabeca *L = criaLista();

    int escolha = 1;
    do
    {   
        painelDeOpcoes(L);
        scanf("%d", &escolha);

        if (escolha >= 0 && escolha <6) {
            opcoes(L, escolha);  
        }

    } while (escolha != 0);
    

    return 0;
}