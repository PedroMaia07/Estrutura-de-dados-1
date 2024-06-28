// link para ver os metodos de manipulação de string https://linguagemc.com.br/a-biblioteca-string-h/ e https://www.cprogressivo.net/2013/03/Lendro-e-Escrevendo-Strings-em-C.html#google_vignette

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char palavra[21];
    struct no *prox;
}Node;

Node *criaNo(char valor[]){
    Node *novo = (Node *) calloc(1, sizeof(Node));
    if (novo == NULL){
        printf("Erro de alocação de memoria!");
        exit(1);
    }
    strncpy(novo->palavra, valor, 21);
    return novo;
}

Node *insereOrd(Node *L, char valor[]){
    Node *novo = criaNo(valor);
    Node *aux = L;
    Node *pred = NULL;
    if (aux == NULL) L = novo;
    else {
        while (aux != NULL && strcmp(valor, aux->palavra) > 0)
        {
            pred = aux;
            aux = aux->prox;
        }
        if (pred == NULL)
        {
            novo->prox = aux;
            L = novo;
        }else{
            novo->prox = aux;
            pred->prox = novo;
        }
    }
    return L;
}

Node *excluiChaveOrd(Node *L, char valor[]){
    Node *aux = L;
    Node *pred = NULL;
    if (L == NULL) return NULL;
    else{
        while (aux != NULL && strcmp(valor, aux->palavra) > 0)
        {
            pred = aux;
            aux = aux->prox;
        }
        if (aux != NULL && strcmp(valor, aux->palavra) == 0)
        {
            if (pred == NULL) {
                L = aux->prox;
            }
            else {
                pred->prox = aux->prox;
            }
            free(aux);
        }
        return L;
    }
}


void imprimeLista(Node *L){
    Node *aux = L;
    printf("\nLista");
    
    if (aux == NULL) printf(" -> Sua lista esta vazia");
    while (aux != NULL)
    {
        printf(" -> %s", aux->palavra);
        aux = aux->prox;
    }
}


void painelDeOpcoes(){

    system("clear");
    printf("\n\nNo caso, como é uma lista ordenada de strings, esta ordenada em ordem alfabetica.\n\n");
    printf("Possiveis operações: \n");
    printf("0 - Finalizar oprerações\n");
    printf("1 - Inserir uma palavra na lista\n");
    printf("2 - Excluir uma palavra na lista\n");
    printf("Por favor, digite qual operação deseja: ");

}

Node *opcoes(Node *L, int escolha, char valor[]){
    switch (escolha) {
        case 0:
            printf("\n**********************************************\nServiço encerrado!\n\nA lista resultante foi:\n");
            imprimeLista(L);
            printf("\n**********************************************\n");
            break;
        case 1:
            printf("Digite o valor a inserir: ");
            fgets(valor, 21, stdin);
            valor[strcspn(valor, "\n")] = '\0'; // Remove a nova linha final, se presente. Após ler a string usando fgets, é necessário remover o caractere de nova linha (\n) do final de valor.
            
            if (strlen(valor) > 20) {
                printf("Por favor, digite palavras com menos de 20 caracteres.\n");
            } else {
                L = insereOrd(L, valor);
            }
            break;
        case 2:
            printf("Digite o valor a excluir: ");
            fgets(valor, 21, stdin);
            valor[strcspn(valor, "\n")] = '\0'; // Remove a nova linha final, se presente. Após ler a string usando fgets, é necessário remover o caractere de nova linha (\n) do final de valor.
            
            if (strlen(valor) > 20) {
                printf("Por favor, digite palavras com menos de 20 caracteres.\n");
            } else {
                L = excluiChaveOrd(L, valor);
            }
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
    char valor[21]; 

    do {

        imprimeLista(L);
        painelDeOpcoes();
        int resultado = scanf("%d", &escolha); //O scanf retorna o número de itens lidos com sucesso
        getchar(); // Consome o caractere de nova linha deixado pelo scanf

        if (resultado == 1 && escolha >= 0 && escolha < 3) {
            L = opcoes(L, escolha, valor);
        }

    } while (escolha != 0);

    return 0;
}