/*
Primeiro entregável - Sistemas Operacionais
Grupo:Heitor Xavier de Abreu
      João Lucas Lima
      Vitor Emanuel Rozeno
*/

#include "mem.h"
#include <stdio.h>
#include <stdlib.h>

const int qtBlocos = 131072;

// Função para alocar uma quantidade qBlocos de memória
int memAloc(RAM *mem, int qBlocos)
{
  if (mem->blocosDisp >= qBlocos)
  {
    mem->blocosDisp -= qBlocos;
    mem->blocosOcu += qBlocos;
    return 1; // Alocação bem-sucedida
  }
  else
  {
    return 0; // Alocação falhou
  }
}

// Função para liberar uma quantidade de qBlocos de memória
void memDesaloc(RAM *mem, int qBlocos)
{
  mem->blocosDisp += qBlocos;
  mem->blocosOcu -= qBlocos;
}

// Função para exibir a ocupação da memória
void memStatus(RAM *mem)
{
  printf("\nMemória Livre: %d kB", mem->blocosDisp * 8);
  printf("\nMemória Ocupada: %d kB", mem->blocosOcu * 8);
}
