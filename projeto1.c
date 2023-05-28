#include <stdio.h>
#include <stdlib.h>
//#include <pthread.h>
//#include <semaphore.h>
#include "pcb.c"



int main() {
    PCB_list *processList = malloc(sizeof(PCB_list));
    initList(processList);

    // Exemplo de criação e adição de processos à lista encadeada
    Process* process1 = malloc(sizeof(Process));
    process1 = createProcess(1, 1, 5, 5);
    Process* process2 = malloc(sizeof(Process));
    process2 = createProcess(2, 2, 3, 3);
    Process* process3 = malloc(sizeof(Process));
    process3 = createProcess(3, 3, 2, 2);

    insert(processList, process1);
    insert(processList, process2);
    insert(processList, process3);

    SRTF(processList);

    return 0;
}