#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "receitas.h"
#include "ingredientes.h"

/* 
   Cria uma nova lista de receitas.
   Inicializa os ponteiros de início e fim como NULL e define a quantidade como 0.
   Retorna o ponteiro para a lista recém-criada.
*/

ListaR* criarListaR(){
    ListaR* r = (ListaR*) malloc(sizeof(ListaR));
    r->inicio = NULL;
    r->fim = NULL;
    r->quantidade = 0;
    return r;    
}

/* 
   Cria um novo nó de receita com o nome informado.
   Inicializa a lista de ingredientes da receita.
   Define o ponteiro para o próximo como NULL e copia o nome da receita.
   Retorna o novo nó de receita.
*/

NoR* criarNovoNoR(char receita[]){
    NoR* novoNoR = (NoR*) malloc(sizeof(NoR));
    novoNoR->prox = NULL;
    novoNoR->ingredientes = criarListaI();
    strcpy(novoNoR->receita, receita);
    return novoNoR;
}

/* 
   Insere uma nova receita na lista de receitas.
   Se a lista estiver vazia, a nova receita vira o primeiro e o último elemento.
   Caso contrário, é adicionada ao final da lista.
*/
void inserirR(ListaR* r, char receita[]){
    NoR* novoNoR = criarNovoNoR(receita);
    
    if (r == NULL){
        printf("Lista não existe.");
        return;
    }
    
    if ((r->inicio) == NULL){
        r->inicio = novoNoR;
        r->fim = novoNoR;
    } else {
        r->fim->prox = novoNoR;
        r->fim = novoNoR;
    }

    r->quantidade++;
}

/* 
   Remove uma receita da lista com base no nome informado.
   Percorre a lista até encontrar a receita e ajusta os ponteiros para removê-la.
   Caso a receita não seja encontrada, exibe uma mensagem.
*/

void removerR(ListaR* r, char receita[]){
    if (r == NULL){
        printf("Lista não existe");
        return;
    }

    int achou = 0;
    NoR* aux = r->inicio;
    NoR* ant = r->inicio;

    while (aux != NULL){
        if (strcmp(aux->receita, receita) == 0){
            achou = 1;
            break;    
        }
        ant = aux;
        aux = aux->prox;
    }

    if (achou == 1){
        /* Se o nó a ser removido for o primeiro */
        if (aux == r->inicio)
            r->inicio = aux->prox;
        else
            ant->prox = aux->prox;

        /* Se o nó a ser removido for o último */
        if (aux == r->fim)
            r->fim = ant;

        r->quantidade--;
        free(aux);
    } else {
        printf("Ingrediente não encontrado");
    }
}

/* 
   Procura uma receita pelo nome.
   Percorre a lista até encontrar o nome correspondente e retorna o nó da receita.
   Caso não encontre, imprime uma mensagem e retorna NULL.
*/

NoR* procurarR(ListaR* r, char receita[]){
    NoR* aux = r->inicio;
    int achou = 0;
    
    while (aux != NULL){
        if (strcmp(aux->receita, receita) == 0){
            achou = 1;
            break;
        }
        aux = aux->prox;
    }

    if (achou == 1){
        return aux;
    } else {
        printf("Receita não encontrada.");
        return NULL;
    }
}

/* 
   Percorre toda a lista de receitas e imprime o nome de cada uma,
   junto com seus respectivos ingredientes.
   Usa um laço aninhado para percorrer a lista de ingredientes de cada receita.
*/
NoR* percorrerR(ListaR* r){
    NoR* aux = r->inicio;
    No* auxI;
    
    while (aux != NULL){
        printf("Receita: %s\n", aux->receita);
        auxI = aux->ingredientes->inicio;

        printf("Ingredientes:\n");
        while (auxI != NULL){
            printf("%s\n", auxI->ingrediente);
            auxI = auxI->prox;
        }

        aux = aux->prox;
    }

    return NULL; // Boa prática: retorna algo mesmo em função void*, se for o caso.
}
