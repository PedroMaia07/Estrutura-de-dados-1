#include "pilha.h"

/*
Le um arquivo txt com os delimitadoes (), [] e {} e verifica se todos os delimitades tem seus pares.
Para compilar o codigo escreva 'make all' e depois './teste'
*/

int main(){
    cabeca *p = criapilha();
    FILE *fp= NULL;
    char ch;

    fp = fopen("arquivo.txt","r");
    if(fp==NULL){
        printf("\nNão foi possível abrir o arquivo");
        exit(1);
    }
    ch = fgetc(fp);

    while (ch != EOF){
        if (ch == '{' || ch == '[' || ch == '(')
        {
            p = empilha(p, ch);
        }else{
            if (p->prox == NULL)
            {
                p->quant = 99999;
                break;
            }
            if (ch == '}')
            {
                if (p->prox->caracter == '{') desempilha(p);
                else break;
            }
            if (ch == ')')
            {
                if (p->prox->caracter == '(') desempilha(p);
                else break;
            }
            if (ch == ']')
            {
                if (p->prox->caracter == '[') desempilha(p);
                else break;     
            }   
        }
        
        printf("\n");
        imprime(p);
        ch = fgetc(fp);
    }

    if(p->quant == 0) printf("\nMarcadores balanceados!");   
    else printf("\nMarcadores desbalanceados!");

    fclose(fp);

    return 0;
} 
