/*
Primeiro entregável - Sistemas Operacionais
Grupo:Heitor Xavier de Abreu
      João Lucas Lima
      Vitor Emanuel Rozeno
*/

#include "proc.h"
#include "bcp.h"
#include "mem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>

// Função para calcular o tempo restante do programa com base no arquivo de programa
int calcTRest(FILE *arq, int posicao)
{
  int tTotal = 0;
  char line[256];
  char *token;
  char sep[] = " ";

  fseek(arq, 0, posicao);

  while (!feof(arq))
  {
    fgets(line, sizeof(line), arq);

    if (strlen(line) != 5)
    {
      token = strtok(line, sep);
      token = strtok(NULL, sep);
      int tempo = atoi(token);
      printf("Soma do Tempo: %d\n", tempo);
      tTotal += tempo;
    }
  }

  return tTotal;
}

// Função executada pela thread para criar um novo processo
void *ProcessCreate(void *arg)
{
  // Obtém os argumentos da função
  ThreadArgs *args = (ThreadArgs *)arg;

  // Extrai os argumentos individuais
  char *arqPrograma = args->token;
  RAM *memo = args->mem;
  BCP **lista = args->lista;

  // Carrega informações do programa a partir do arquivo
  Processo *nProc = (Processo *)malloc(sizeof(Processo));
  nProc->nome = (char *)malloc(100 * sizeof(char));
  nProc->lista = (char *)malloc(20 * sizeof(char));
  FILE *arq;
  if ((arq = fopen(arqPrograma, "r")) == NULL)
  {
    printf("Falha ao abrir o arquivo\n");
    return NULL;
  }
  fscanf(arq, "%s\n", nProc->nome);
  fscanf(arq, "%d\n", &nProc->idSeg);
  fscanf(arq, "%d\n", &nProc->prioridade);
  fscanf(arq, "%d\n", &nProc->tSeg);

  int i = 0;
  char aux;
  do
  {
    aux = (char)fgetc(arq);
    if (aux != '\n')
      nProc->lista[i] = aux;
    i++;
  } while (aux != '\n');
  fscanf(arq, "\n");

  // Retorna a posição do primeiro comando no arquivo
  nProc->pos = ftell(arq);

  // Calcula o tempo restante do programa
  nProc->tRest = calcTRest(arq, nProc->pos);

  // Calcula o tamanho em blocos do programa
  nProc->tBlocos = ceil(nProc->tSeg / 8);

  // Verifica se há memória suficiente para alocar o programa
  if (memAloc(memo, nProc->tBlocos) == 1)
  {
    printf("Memória suficiente.\n");
  }
  else
  {
    printf("Memória insuficiente.\n");
  }
  fclose(arq);
  // Insere o novo processo ordenadamente na BCP
  insereOrdenado(nProc, lista);
  // Finaliza a thread
  pthread_exit(NULL);
}
