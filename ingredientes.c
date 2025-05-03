#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingredientes.h"

ListaI* criarListaI(){
    ListaI* l = (ListaI*) malloc(sizeof(ListaI));
    l->inicio = NULL;
    l->fim = NULL;
    l->quantidade = 0;

    return l;    
}

No* criarNovoNo(char ingrediente[]){
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->prox = NULL;
    novoNo->ant = NULL;
    strcpy(novoNo->ingrediente, ingrediente);
    novoNo->essencial = 0;
    
    return novoNo;
}

void inserirI(ListaI* l, char ingrediente[]){
    if(l == NULL){
        printf("Lista não existe");
        return;
    }
    No* novoNo = criarNovoNo(ingrediente);
    
    if(l->inicio == NULL){
        l->inicio = novoNo;
        l->fim = novoNo;
    } else {
        novoNo->ant = l->fim;
        l->fim->prox = novoNo;
        l->fim = novoNo;
    }
    l->quantidade++;
}

void removerI(ListaI* l, char ingrediente[]){
    if(l == NULL){
        printf("Lista não existe");
        return;
    }
    int achou = 0;
    
    No* aux = l->inicio; 
    while(aux != NULL){
        if(strcmp(aux->ingrediente, ingrediente) == 0){
        achou = 1; break;    
        }
        aux = aux->prox;
    }
    
    if(achou == 1){
        if(aux->ant == NULL){
            aux->prox->ant = NULL;
            l->inicio = aux->prox;
        } else if(aux == l->fim){
            aux->ant->prox = NULL;
            l->fim = aux->ant;
        } else {
            aux->ant->prox = aux->prox;
            aux->prox->ant = aux->ant;
        }
        l->quantidade--;
        free(aux);
    } else{
        printf("Ingrediente não encontrado");
    }
}

void substituir(ListaI* l, char ingrediente[], char Ningrediente[]){
    int achou = 0;
    int achouI = 0;
    No* aux = l->inicio; 
    while(aux != NULL){
        if(strcmp(aux->ingrediente, ingrediente) == 0){
        achou = 1; break;    
        }
        if(strcmp(aux->ingrediente, Ningrediente) == 0){
        achouI = 1; break;    
        }
        aux = aux->prox;
    }
    if(achouI == 1){
        printf("O novo ingrediente que você deseja adicionar ja se encontra na lista");
        return;
    }
    if(achou == 1){
        strcpy(aux->ingrediente, Ningrediente);
    }
}

void essencial(ListaI* l){
    char ingrediente[100];
    int achou = 0;
    printf("De qual receita é o ingrediente: ");
    printf("Digite o ingrediente buscado: ");
    fgets(ingrediente, sizeof(ingrediente), stdin);
    
    ingrediente[strcspn(ingrediente, "\n")] = '\0'; 
    No* aux = l->inicio;
    while(aux != NULL){
        if(strcmp(aux->ingrediente, ingrediente) == 0){
            achou = 1; break;
        }
        aux = aux->prox;
    }
    
    if(achou == 1){
        aux->essencial = 1;
        printf("ingrediente %s foi marcado como essencial ", ingrediente);
    } else {
        printf("ingrediente não foi encontrado.");
    }
}

void percorrerI(ListaI* l){
    No* aux = l->inicio;
    
    while (aux != NULL){
        printf("%s \n", aux->ingrediente);
        aux = aux->prox;
    }
}
