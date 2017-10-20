#ifndef _QUEUE
#define _QUEUE

//tamanho da fila
#define qtotal 3

// o tipo que sera contido na fila, 'queue-type'
typedef int qtype;

typedef struct q{
    int head,tail,max,total;
    qtype item[qtotal];
}QUEUE;

// inicializa a fila
void create_queue(QUEUE* q);

// retorna 1 se a pilha esta cheia, 0 se nao esta
int q_is_full(QUEUE q);

// retorna 1 se a pilha esta vazia, 0 se nao esta
int q_is_empty(QUEUE q);

// coloca o elemento 'n' na proxima posicao da fila
// retorno: -1, a fila esta cheia ; 0, nao houve erro
int in_queue(QUEUE* q,qtype n);

// retorna o primeiro elemento que entrou na fila e o remove, ou INT_MIN caso a fila esteja vazia
qtype out_queue(QUEUE* q);

// retorna o primeiro elemento que entrou na fila sem removelo, ou INT_MIN caso a fila esteja vazia
qtype peek(QUEUE q);

#endif

