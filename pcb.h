
typedef struct process{
    int pid; // Identificador do processo
    int state; // Estado do processo (em execução = 1, bloqueado = 0, aguardando = -1)
    int priority; // Prioridade do processo
    int remainingTime; // Tempo de execução restante do processo
    int totalTime; // Tempo de execução total do processo
    struct process *next;
} Process;

typedef struct{
    Process* first;
    Process* last;
} PCB_list;

void initList(PCB_list* list);
Process* createProcess(int pid, int priority, int remainingTime, int totalTime);
void insert(PCB_list* list, Process *p);
void displayList(PCB_list* list);
Process* remover(PCB_list* list);

Process *selectNextProcess(PCB_list* list);
void SRTF(PCB_list *list);