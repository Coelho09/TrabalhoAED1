#ifndef INGREDIENTES_H
#define INGREDIENTES_H

#include "dados.h"

/*
   Estrutura de nó que representa um ingrediente.
   Cada nó contém o nome do ingrediente, se é essencial (1 ou 0),
   e ponteiros para o próximo e o anterior na lista.
*/
typedef struct no {
    char ingrediente[100];
    int essencial;
    struct no* prox;
    struct no* ant;
} No;

/*
   Estrutura da lista de ingredientes.
   Armazena ponteiros para o início e fim da lista,
   além da quantidade total de ingredientes.
*/
typedef struct ListaI {
    No* inicio;
    No* fim;
    int quantidade;
} ListaI;

/*
   Cria e retorna um ponteiro para uma nova lista de ingredientes vazia.
*/
ListaI* criarListaI();

/*
   Cria e retorna um novo nó de ingrediente com o nome fornecido.
   Inicializa os ponteiros e marca como não essencial.
*/
No* criarNovoNo(char ingrediente[]);

/*
   Insere um ingrediente na lista de uma receita específica.
*/
void inserirI(ListaR* r, char receitaC[], char ingrediente[]);

/*
   Substitui um ingrediente por outro dentro de uma receita.
   Verifica se o novo ingrediente já existe na lista antes da substituição.
*/
void substituir(ListaR* r, char receitaC[], char ingrediente[], char Ningrediente[]);

/*
   Marca um ingrediente de uma receita como essencial.
   O usuário informa o nome do ingrediente a ser marcado.
*/
void essencial(ListaR* r, char receitaC[]);

/*
   Percorre e imprime os ingredientes de uma receita.
*/
void percorrerI(ListaR* r, char receitaC[]);

#endif
