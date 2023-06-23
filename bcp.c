/*
Primeiro entregável - Sistemas Operacionais
Grupo:Heitor Xavier de Abreu
      João Lucas Lima
      Vitor Emanuel Rozeno
*/

#include "bcp.h"
#include "proc.h"
#include <stdio.h>
#include <stdlib.h>

// Insere um novo BCP ordenadamente na lista com base no tRest do
// processo
void insereOrdenado(Processo *processo, BCP **lista)
{
  // Cria um novo BCP
  BCP *nBCP = (BCP *)malloc(sizeof(BCP));
  nBCP->dados = processo;
  nBCP->proximo = NULL;

  // Verifica a posição correta de inserção na lista com base no tRest
  BCP *atual = *lista;
  BCP *anterior = NULL;
  while (atual != NULL &&
         atual->dados->tRest < processo->tRest)
  {
    anterior = atual;
    atual = atual->proximo;
  }

  if (anterior == NULL)
  {
    nBCP->proximo = *lista;
    *lista = nBCP;
  }
  else
  {
    anterior->proximo = nBCP;
    nBCP->proximo = atual;
  }
}

// Passa pela lista e imprime as informações de cada processo
void printLista(BCP *lista, RAM *mem)
{
  BCP *atual = lista;

  while (atual != NULL)
  {
    // Imprime o nome do processo, tempo restante e memória usada
    printf("Nome: %s\nT. Restante: %d\n",
           atual->dados->nome, atual->dados->tRest);
    atual = atual->proximo;
  }

  // Imprime a quantidade de memória ocupada e livre
  printf("Memória Usada: %d kB\n", mem->blocosOcu * 8);
  printf("Memória Livre: %d kB\n", mem->blocosDisp * 8);
}

// Retorna o primeiro processo da lista (menor tempo)
Processo *primProc(BCP *lista)
{
  return (lista != NULL) ? lista->dados : NULL;
}
