#ifndef INGREDIENTES_H
#define INGREDIENTES_H

typedef struct no{
    char ingrediente[100];
    int essencial;
    struct no* prox;
    struct no* ant;
} No;

typedef struct ListaI{
    No* inicio;
    No* fim;
    int quantidade;
} ListaI;

ListaI* criarListaI();
No* criarNovoNo(char ingrediente[]);
void inserirI(ListaI* l, char ingrediente[]);
void removerI(ListaI* l, char ingrediente[]);
void substituir(ListaI* l, char ingrediente[], char Ningrediente[]);
void essencial(ListaI* l);
void percorrerI(ListaI* l);

#endif
