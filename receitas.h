#ifndef RECEITAS_H
#define RECEITAS_H

#include "dados.h"
#include "ingredientes.h"

/*
   Estrutura que representa um nó de receita.
   Contém o nome da receita, a lista de ingredientes associados
   e um ponteiro para o próximo nó na lista encadeada.
*/
typedef struct noR {
    char receita[100];
    ListaI* ingredientes;
    struct noR* prox;
} NoR;

/*
   Estrutura da lista de receitas.
   Armazena ponteiros para o início e fim da lista,
   além da quantidade total de receitas cadastradas.
*/
typedef struct ListaR {
    NoR* inicio;
    NoR* fim;
    int quantidade;
} ListaR;

/*
   Cria uma nova lista de receitas vazia e retorna um ponteiro para ela.
*/
ListaR* criarListaR();

/*
   Cria e retorna um novo nó de receita com o nome fornecido.
   Também inicializa a lista de ingredientes da receita.
*/
NoR* criarNovoNoR(char receita[]);

/*
   Insere uma nova receita na lista de receitas.
*/
void inserirR(ListaR* r, char receita[]);

/*
   Remove uma receita da lista pelo nome.
*/
void removerR(ListaR* r, char receita[]);

/*
   Procura e retorna um ponteiro para uma receita específica pelo nome.
   Caso não encontre, retorna NULL.
*/
NoR* procurarR(ListaR* r, char receita[]);

/*
   Percorre e imprime todas as receitas e seus ingredientes.
*/
NoR* percorrerR(ListaR* r);

#endif
