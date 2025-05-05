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
    if (r == NULL || r->inicio == NULL) {
        printf("Lista de receitas vazia ou não existe.\n");
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
        printf("Receita não encontrada");
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
    
    if (aux != NULL){
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
  } else printf("\nLista esta vazia\n");
    return NULL; // Boa prática: retorna algo mesmo em função void*, se for o caso.
}

/*
   Utiliza a função procurarR para achar a receita digitada pelo usuario 
   e atualiza o campo favorita da mesma.
*/
void favoritar(ListaR* r, char receitaC[]){
    
    int achou = 0;
    NoR* receita = procurarR(r, receitaC);
    NoR* aux = receita;
    
    if(receita != NULL){
    receita->favorita = 1;
    } 
}

/* 
   Percorre toda a lista de receitas e imprime o nome de cada uma que seja favorita,
   alem disso imprime os ingredientes essenciais da lista de receitas.
*/

void mostraEspeciais(ListaR* r){
    if (r == NULL || r->inicio == NULL) {
        printf("Lista de receitas vazia ou não existe.\n");
        return;
    }
    
    NoR* aux = r->inicio;
    NoR* aux2 = r->inicio;
    No* auxI;
    
    printf("Receitas Favoritas:\n");
    while (aux != NULL){
        if(aux->favorita == 1){
        printf ("%s\n", aux->receita);
        }
        aux = aux->prox;
    }
    
    printf("Ingredientes essenciais:\n");
    while (aux2 != NULL){
        auxI = aux2->ingredientes->inicio;
        while (auxI != NULL){
            if(auxI->essencial == 1){
            printf("%s\n", auxI->ingrediente);
          }
          auxI = auxI->prox;
        }
        aux2 = aux2->prox;
  }
}

