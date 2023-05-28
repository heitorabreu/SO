#include "pcb.h"
#include <stdlib.h>

void initList(PCB_list* list) {
    list->first = NULL;
    list->last = NULL;
}

Process* createProcess(int pid, int state, int priority, int remainingTime, int totalTime){
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->pid = pid;
    newProcess->state = state;
    newProcess->priority = priority;
    newProcess->remainingTime = remainingTime;
    newProcess->totalTime = totalTime;
    newProcess->next = NULL;

    return newProcess;
}

// Insere um novo PCB na posição correta da lista (ordenado pelo remainingTime)
void insert(PCB_list* list, Process *p) {

    Process* current = list->first;
    Process* prev = NULL;

    // Encontra a posição correta para inserir o novo Process (ordenado pelo remainingTime)
    while (current != NULL && current->remainingTime < newProcess->remainingTime) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        // Insere o novo Process no início da lista
        newProcess->next = list->first;
        list->first = newProcess;
    } else {
        // Insere o novo Process no meio ou no final da lista
        prev->next = newProcess;
        newProcess->next = current;
        if (current == NULL) {
            // Atualiza o último elemento da lista
            list->last = newProcess;
        }
    }
}

// Percorre e exibe os PCBs da lista
void displayList(PCB_list* list) {
    Process* current = list->first;
    while (current != NULL) {
        printf("PID: %d, State: %d, Priority: %d, Remaining Time: %d, Total Time: %d\n",
               current->pid, current->state, current->priority, current->remainingTime, current->totalTime);
        current = current->next;
    }
}

Process* remove(PCB_list* list){
    Process* aux = list->first;
    list->first = list->first->next;
    return aux;
}