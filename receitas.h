#ifndef RECEITAS_H
#define RECEITAS_H
#include "ingredientes.h"

typedef struct noR{
    char receita[100];
    ListaI* ingredientes;
    struct noR* prox;
} NoR;


typedef struct ListaR{
    NoR* inicio;
    NoR* fim;
    int quantidade;
} ListaR;

ListaR* criarListaR();
NoR* criarNovoNoR(char receita[]);
void inserirR(ListaR* r, char receita[]);
void removerR(ListaR* r, char receita[]);


#endif