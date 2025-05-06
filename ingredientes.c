#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "receitas.h"
#include "ingredientes.h"

/*
   Cria uma nova lista de ingredientes.
   Inicializa os ponteiros de início e fim como NULL e define a quantidade como 0.
   Retorna o ponteiro da lista criada.
*/
ListaI* criarListaI() {
	ListaI* l = (ListaI*) malloc(sizeof(ListaI));
	l->inicio = NULL;
	l->fim = NULL;
	l->quantidade = 0;
	return l;
}

/*
   Cria um novo nó de ingrediente com o nome informado.
   Inicializa os ponteiros para o próximo e anterior como NULL.
   Marca o ingrediente como não essencial por padrão.
   Retorna o ponteiro para o novo nó.
*/
No* criarNovoNo(char ingrediente[]) {
	No* novoNo = (No*) malloc(sizeof(No));
	if (novoNo == NULL) return NULL;
	novoNo->prox = NULL;
	novoNo->ant = NULL;
	strcpy(novoNo->ingrediente, ingrediente);
	novoNo->essencial = 0;
	return novoNo;
}

/*
   Insere um novo ingrediente em uma receita específica.
   Se a lista de ingredientes da receita estiver vazia, o novo ingrediente é o primeiro e o último.
   Caso contrário, ele é adicionado ao final da lista.
*/
int inserirI(ListaR* r, char receitaC[], char ingrediente[]) {
	if (r == NULL ) {
		printf("Lista de receitas não existe.\n");
		return 0;
	}

	No* novoNo = criarNovoNo(ingrediente);
	NoR* receita = procurarR(r, receitaC);


	if(receita != NULL) {
		if (receita->ingredientes->inicio == NULL) {
			receita->ingredientes->inicio = novoNo;
			receita->ingredientes->fim = novoNo;
		} else {
			novoNo->ant = receita->ingredientes->fim;
			receita->ingredientes->fim->prox = novoNo;
			receita->ingredientes->fim = novoNo;
		}
		receita->ingredientes->quantidade++;
		return 1;
	} else {
	    printf("Receita não encontrada!\n");
	    return 0;
	}
}

/*
   Remove um ingrediente específico de uma receita.
   Ajusta os ponteiros dos nós vizinhos para manter a integridade da lista.
   Se o ingrediente não for encontrado, exibe uma mensagem de erro.
*/
void removerI(ListaR* r, char receitaC[], char ingrediente[]) {
	if (r == NULL || r->inicio == NULL) {
		printf("Lista de receitas vazia ou não existe.\n");
		return;
	}

	NoR* receita = procurarR(r, receitaC);
	if(receita == NULL) {
		printf("Receita nao encontrada\n");
		return;
	}

	if (receita->ingredientes == NULL || receita->ingredientes->inicio == NULL) {
		printf("Lista de ingredientes vazia para a receita '%s'.\n", receitaC);
		return;
	}


	int achou = 0;
	No* aux = receita->ingredientes->inicio;

	while (aux != NULL || aux->prox != NULL) {
		if (strcmp(aux->ingrediente, ingrediente) == 0) {
			achou = 1;
			break;
		}
		aux = aux->prox;
	}

	if (achou == 1) {
		if (aux->ant == NULL) {
			receita->ingredientes->inicio = aux->prox;
			if (aux->prox != NULL) {
				aux->prox->ant = NULL;
			} else {
				receita->ingredientes->inicio = NULL;
				receita->ingredientes->fim = NULL;
			}
		} else if (aux == receita->ingredientes->fim) {
			aux->ant->prox = NULL;
			receita->ingredientes->fim = aux->ant;
		} else {
			aux->ant->prox = aux->prox;
			aux->prox->ant = aux->ant;
		}
		receita->ingredientes->quantidade--;
		free(aux);
	} else {
		printf("Ingrediente não encontrado\n");
	}
}

/*
   Substitui um ingrediente de uma receita por outro.
   Verifica se o novo ingrediente já existe para evitar duplicação.
   Se o ingrediente original for encontrado, seu nome é atualizado.
*/
void substituir(ListaR* r, char receitaC[], char ingrediente[], char Ningrediente[]) {
	if (r == NULL || r->inicio == NULL) {
		printf("Lista de receitas vazia ou não existe.\n");
		return;
	}

	NoR* receita = procurarR(r, receitaC);

	if(receita == NULL) {
		printf("Receita nao encontrada\n");
		return;
	}

	int achou = 0;
	int achouI = 0;
	No* aux = receita->ingredientes->inicio;

	while (aux != NULL) {
		if (strcmp(aux->ingrediente, ingrediente) == 0) {
			achou = 1;
		}
		if (strcmp(aux->ingrediente, Ningrediente) == 0) {
			achouI = 1;
		}
		aux = aux->prox;
	}

	if (achouI == 1) {
		printf("O novo ingrediente que você deseja adicionar já se encontra na lista\n");
		return;
	}

	aux = receita->ingredientes->inicio;
	while (aux != NULL) {
		if (strcmp(aux->ingrediente, ingrediente) == 0) {
			strcpy(aux->ingrediente, Ningrediente);
			return;
		}
		aux = aux->prox;
	}
}

/*
   Marca um ingrediente como essencial dentro de uma receita.
   Solicita ao usuário o nome do ingrediente e atualiza seu status se for encontrado.
*/
void essencial(ListaR* r, char receitaC[]) {
	if (r == NULL || r->inicio == NULL) {
		printf("Lista de receitas vazia ou não existe.\n");
		return;
	}
	char ingrediente[100];
	int achou = 0;

	printf("Digite o ingrediente buscado: ");
	fgets(ingrediente, sizeof(ingrediente), stdin);
	ingrediente[strcspn(ingrediente, "\n")] = '\0'; // remove o \n da leitura

	NoR* receita = procurarR(r, receitaC);
	if(receita == NULL) {
		printf("Receita nao encontrada\n");
		return;
	}
	No* aux = receita->ingredientes->inicio;

	while (aux != NULL) {
		if (strcmp(aux->ingrediente, ingrediente) == 0) {
			aux->essencial = 1;
			achou = 1;
			printf("Ingrediente %s foi marcado como essencial\n", ingrediente);
			break;
		}
		aux = aux->prox;
	}

	if (!achou) {
		printf("Ingrediente não foi encontrado.\n");
	}
}

/*
   Percorre a lista de ingredientes de uma receita e imprime o nome de cada um.
*/
void percorrerI(ListaR* r, char receitaC[]) {
	NoR* receita = procurarR(r, receitaC);
	No* aux = receita->ingredientes->inicio;

	while (aux != NULL) {
		printf("%s \n", aux->ingrediente);
		aux = aux->prox;
	}
}

/*
   Percorre a lista de receitas e imprime o nome de cada receita que possuir
   o ingrediente digitado pelo usuario.
*/

void buscarIngrediente(ListaR* r, char ingrediente[]) {
	if (r == NULL || r->inicio == NULL) {
		printf("Lista de receitas vazia ou não existe.\n");
		return;
	}

    NoR* aux = r->inicio;
    No* auxI;
    int achou = 0;
    
    printf("Esse ingrediente se encontra nas receitas:\n");
	while (aux != NULL) {
		auxI = aux->ingredientes->inicio;
		while (auxI != NULL) {
			if(strcmp(auxI->ingrediente, ingrediente) == 0) {
			    achou = 1; break;
			}
			auxI = auxI->prox;
		}
		if(achou == 1){
		printf("%s\n", aux->receita);
		achou = 2;
		}
		aux = aux->prox;
	}
	if(achou == 0)
	printf("Ingrediente não foi encontrado");
}

