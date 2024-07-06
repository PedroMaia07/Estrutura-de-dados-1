#ifndef __PILHA_H__
#define __PILHA_H__

/* Inclusão de bibliotecas necessárias para o pacote */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/* Definição de estruturas e declaração de variáveis locais */
typedef struct pilha {
    char caracter;
    struct pilha *ant, *prox;
}pilha;

typedef struct cabeca{
    int quant;
    struct pilha *ant, *prox;
}cabeca;

/* Cabeçalhos das funções com suas respectivas descrições */

/*
Função: criano
Descrição: Aloca dinamicamente uma estrutura pilha e inicializa os campos com os dados passados como parâmetro.
Entrada:
    char caracter = recebe o caracter para a comparação
Saída:
    ponteiro para a estrutura pilha alocada dinâmicamente
*/
pilha *criano (char carac);

/*
Função: criapilha
Descrição: Aloca dinamicamente uma estrutura pilha e inicializa os campos com os dados passados como parâmetro.
Entrada:

Saída:
    ponteiro para a estrutura pilha alocada dinâmicamente
*/
cabeca *criapilha();

/*
Função: imprime
Descrição: printa a pilha
Entrada:
    pilha *p: ponteiro para uma estrutura pilha
Saída: void
*/
void imprime (cabeca *p);

/*
funçao: empilha
descrição: Empilha os nos na pilha
entrada:
    pilha *p: ponteiro para uma estrutura do tipo pilha
    char caracter: o caracter que vai ser empilhado
saida:
    ponteiro para a entrutura pilha
*/
cabeca *empilha(cabeca *p, char carac);

/*
funçao: desempilha
descrição: desmpilha o primeiro no da pilha
entrada:
    pilha *p: ponteiro para uma estrutura do tipo pilha
saida:
    ponteiro para a entrutura pilha
*/
void desempilha(cabeca *p);


#endif
