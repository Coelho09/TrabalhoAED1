#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingredientes.h"
#include "receitas.h"

/*
  MAIN
  Função principal do programa, onde toda a interação com o usuário acontece.
  É aqui que a lista de receitas é criada e o menu é apresentado em loop até o usuário sair.
*/

int main() {

     /*
      Criação da lista principal de receitas.
      A função criarListaR() inicializa a estrutura que armazenará as receitas.
      Exemplo: ListaR* R = criarListaR();
    */

    ListaR* R = criarListaR();
    int opcao;
    char receita[100];
    char ingrediente[100];

     /*
      Loop principal do menu. O programa só sai quando a opção 0 for escolhida.
      O usuário escolhe uma ação e o switch direciona a execução.
    */

    do {
        printf("\n----- MENU -----\n");
        printf("1 - Inserir Receita\n");
        printf("2 - Inserir Ingrediente em Receita\n");
        printf("3 - Remover Receita\n");
        printf("4 - Remover Ingrediente de Receita\n");
        printf("5 - Ver todas as receitas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

         /*
          Estrutura switch-case para executar a ação correspondente à escolha do usuário.
          Cada caso executa uma função da lógica de receitas ou ingredientes.
        */

        switch(opcao) {
            case 1:

             /*
                  Inserção de uma nova receita.
                  A função inserirR() adiciona o nome na lista principal de receitas.
                  Exemplo de uso:
                  mas de maneira interativa com o usuário
                  inserirR(R, "Bolo de Cenoura");
                */

                printf("Nome da receita: ");
                fgets(receita, sizeof(receita), stdin);
                receita[strcspn(receita, "\n")] = '\0';
                inserirR(R, receita);
                break;

                /*
                  Inserção de um ou mais ingredientes em uma receita existente.
                  O loop permite adicionar quantos ingredientes o usuário quiser.
                  inserirI() insere o ingrediente na receita específica.
                */

                case 2:
                printf("Nome da receita: ");
                fgets(receita, sizeof(receita), stdin);
                receita[strcspn(receita, "\n")] = '\0';
            
                do {
                    printf("Nome do ingrediente: ");
                    fgets(ingrediente, sizeof(ingrediente), stdin);
                    ingrediente[strcspn(ingrediente, "\n")] = '\0';
            
                    inserirI(R, receita, ingrediente);
            
                    char resposta;
                    printf("Deseja inserir mais um ingrediente? (s/n): ");
                    scanf(" %c", &resposta);
                    getchar();  // Limpa o buffer
            
                    if (resposta != 's' && resposta != 'S') {
                        break;
                    }
            
                } while (1);
                break;

                 /*
                  Remoção de uma receita da lista.
                  A função removerR() busca pelo nome e exclui a receita, liberando seus ingredientes.
                */

            case 3:
                printf("Nome da receita a remover: ");
                fgets(receita, sizeof(receita), stdin);
                receita[strcspn(receita, "\n")] = '\0';
                removerR(R, receita);
                break;

                 /*
                  Remoção de um ingrediente específico de uma receita.
                  A função removerI() procura a receita e exclui o ingrediente informado.
                */

            case 4:
                printf("Nome da receita: ");
                fgets(receita, sizeof(receita), stdin);
                receita[strcspn(receita, "\n")] = '\0';

                printf("Nome do ingrediente a remover: ");
                fgets(ingrediente, sizeof(ingrediente), stdin);
                ingrediente[strcspn(ingrediente, "\n")] = '\0';

                removerI(R, receita, ingrediente);
                break;

                 /*
                  Impressão de todas as receitas com seus ingredientes.
                  A função percorrerR() percorre toda a lista de receitas e chama percorrerI() para os ingredientes.
                */

            case 5:
                percorrerR(R);
                break;

                /*
                  Opção para encerrar o programa.
                  Sai do loop do menu e encerra o main().
                */

            case 0:
                printf("Encerrando o programa.\n");
                break;

                 /*
                  Caso o usuário digite uma opção inválida.
                  Apenas imprime uma mensagem de erro.
                */
               
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}
