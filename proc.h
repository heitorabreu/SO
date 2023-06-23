/*
Primeiro entregável - Sistemas Operacionais
Grupo:Heitor Xavier de Abreu
      João Lucas Lima
      Vitor Emanuel Rozeno
*/

#ifndef __PROC
#define __PROC

#include "bcp.h"
#include "mem.h"
#include <stdio.h>

// Estrutura para representar um processo
typedef struct processo
{
  char *nome;    // Nome
  int tBlocos;   // Tamanho do segmento (BLOCOS)
  int tRest;     // Tempo restante (u.t.)
  char *lista;   // Lista de semáforos
  FILE *arqProg; // Arquivo do programa
  int pos;       // Posição no arquivo
  int idSeg;     // Identificador do segmento
  int prioridade;
  int tSeg; // Tamanho do segmento (KB)

} Processo;

// Estrutura para os argumentos da thread
typedef struct threadargs
{
  char *token; // Token da thread
  RAM *mem;    // Ponteiro para a memória
  BCP **lista; // Ponteiro para a lista de BCPs
} ThreadArgs;

// Função para criar um processo
void *ProcessCreate(void *arg);

#endif
