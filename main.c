/*
Primeiro entregável - Sistemas Operacionais
Grupo:Heitor Xavier de Abreu
      João Lucas Lima
      Vitor Emanuel Rozeno
*/

#include <stdio.h>
#include <stdlib.h>
#include "bcp.h"
#include "mem.h"
#include "proc.h"
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

int main()
{
  int menu = 1;
  char userIn[100];

  // Criando thread para a função ProcessCreate
  pthread_t pcThread; // ProcessCreate
  int PCOut;          // Resultado da pcThread

  // Inicialização da memória
  RAM *mem = malloc(sizeof(RAM));
  mem->blocosDisp = qtBlocos;
  mem->blocosOcu = 0;

  ThreadArgs args;
  BCP *lista = NULL;

  while (menu)
  {
    printf("\n\nMenu:\n");

    printf(" - (ProcessCreate): Digite PC nomedoarquivo.extensao\n");
    printf(" - (Ver Dados de Proc e Mem): Digite VIEW\n");
    printf(" - (Sair): Digite Sair\n\n");
    printf("----> ");

    scanf(" %[^\n]", userIn);

    char *token = strtok(userIn, " ");
    if (token != NULL)
    {
      if (strcmp(token, "PC") == 0)
      {
        token = strtok(NULL, " ");

        if (token != NULL)
        {
          args.token = token;  // Nome arq
          args.mem = mem;      // Estrutura da memória RAM
          args.lista = &lista; // BCP
          PCOut =
              pthread_create(&pcThread, NULL, ProcessCreate, (void *)&args);

          if (PCOut != 0)
            printf("Erro na criação da thread\n");

          pthread_join(pcThread, NULL); // Aguarda a finalização da thread
        }
        else
        {
          printf("PC precisa de nomedoarquivo.extensao.\n");
        }
      }
      else if (strcmp(token, "VIEW") == 0)
      {
        printLista(lista, mem); // Visualiza a lista de processos e a memória
      }
      else if (strcmp(token, "Sair") == 0)
      {
        menu = 0; // Encerra o programa
      }
      else
      {
        printf("Entrada Inválida. Tente novamente.\n");
      }
    }
    getchar();
  }
  free(mem);
  return 0;
}
