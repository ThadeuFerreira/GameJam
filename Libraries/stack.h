#ifndef _STACK
#define _STACK

// tamanho da pilha
#define stotal 10

// o tipo que sera contido na pilha, 'stack-type'
typedef int stype;

typedef struct s{
    int size,top,max;
    stype item[stotal];
}STACK;

// inicializa a pilha
void create_stack(STACK* s);

//retorna 1 se a pilha esta cheia, 0 se nao esta
int s_is_full(STACK s);

// retorna 1 se a pilha esta vazia, 0 se nao esta
int s_is_empty(STACK s);

// empilha uma variavel na pilha
// retorno: -1, a pilha esta cheia ; 0, nao houve erro
int push(STACK* s,stype t);

// retira a variavel do topo da pilha
// retorno: INT_MIN, a pilha esta vazia ; else, a variavel q foi desempilhada
stype pop(STACK* s);

// retorna a variavel do topo da pilha, sem removela, ou INT_MIN caso esteja vazio
stype pull(STACK s);

// troca a ordem dos elementos da pilha
void s_shuffle(STACK* s);

#endif
