#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "receitas.h"
#include "ingredientes.h"

ListaR* criarListaR(){
    ListaR* r = (ListaR*) malloc(sizeof(ListaR));
    r->inicio = NULL;
    r->fim = NULL;
    r->quantidade = 0;

    return r;    
}

NoR* criarNovoNoR(char receita[]){
    NoR* novoNoR = (NoR*) malloc(sizeof(NoR));
    novoNoR->prox = NULL;
    novoNoR->ingredientes = criarListaI();
    strcpy(novoNoR->receita, receita);
    
    return novoNoR;
}

void inserirR(ListaR* r, char receita[]){
    NoR* novoNoR = criarNovoNoR(receita);
    
    if (r == NULL){
        printf("Lista não existe.");
        return;
    }
    
    if((r->inicio) == NULL){
        r->inicio = novoNoR;
        r->fim = novoNoR;
    } else{
        r->fim->prox = novoNoR;
        r->fim = novoNoR;
    }
    r->quantidade++;
    
}

void removerR(ListaR* r, char receita[]){
     if(r == NULL){
        printf("Lista não existe");
        return;
    }
    int achou = 0;
    
    NoR* aux = r->inicio;
    NoR* ant = r->inicio;
    while(aux != NULL){
        if(strcmp(aux->receita, receita) == 0){
        achou = 1; break;    
        }
        ant = aux;
        aux = aux->prox;
    }
    
    if(achou == 1){
        ant->prox = aux->prox;
        r->quantidade--;
        free(aux);
    } else{
        printf("Ingrediente não encontrado");
    }
}

NoR* procurarR(ListaR* r, char receita[]){
    NoR* aux = r->inicio;
    int achou = 0;
    
    while(aux != NULL){
        if(strcmp(aux->receita,receita) == 0){
            achou = 1; break;
        }
        aux = aux->prox;
    }
    if(achou == 1){
        return aux;
    } else {
        printf("Receita não encontrada.");
        return NULL;
    }
}

NoR* percorrerR(ListaR* r){
    NoR* aux = r->inicio;
    No*  auxI;
    
    while (aux != NULL){
        printf("Receita: %s\n", aux->receita);
        auxI = aux->ingredientes->inicio;
        printf("Ingredientes: \n");
        while(auxI != NULL){
            printf("%s\n", auxI->ingrediente);
            auxI = auxI->prox;
        }
        aux = aux->prox;
    }
}

