#ifndef _UTILITES
#define _UTILITES

#define pause_message_0 "PRESS ANY KEY TO CONTINUE"
#define pause_message_1 "PRESSIONE QUALQUER TECLA PARA CONTINUAR"
#define pause_message_2 "OPERACAO INVALIDA, TENTE NOVAMENTE"
#define pause_message_3 "INVALID OPERATION, TRY AGAIN"


// reprinta um caracter varias vezes
void spaces(char caracter,int vezes);

// retorna um inteiro entre min e max, caso min seja maior que max, -1 e retornado
int random(int min,int max);

// pausa o programa e printa uma mesagem
void pause(int i);

// as funcoes a seguir substituem o primeiro encontro do primeiro caracter pelo segundo
// espaco_barran substitui o primeiro espaco encontrado por um '\n'
void espaco_barran(char* string);
void espaco_barra0(char* string);
void barran_espaco(char* string);
void barran_barra0(char* string);
void barra0_barran(char* string);
void barra0_espaco(char* string);

// retorna o tamanho ate o enesimo encontro do char 'c' na string
// a contagem vai ate uma posicao antes do char 'c'
// ex: char c = ' ', n = 2, string = "oi oi oi", nesse caso o retorno da funcao e 5
int tamanho_ate_enesimo_char(char* string,char c,int n);

// retorna a maior variavel do vetor
int maxvec(int* vector,int tamanho);

// retorna a menor variavel de um vetor
int minvec(int* vector,int tamanho);

// implementar --------------------------------------------------------------------------------------------------------------
void print_boxed_string(char*srting,int spaces,char box);

// procura uma sub_string em uma string e retorna o ponteiro da enesima ocorrencia
// retorna NULL caso ela nao ocorra 'n' vezes ou caso 'n' seja nao positivo
char* ocorrencia_n(char* source,char* sub_string,int n);

// retorna o tamanho da linha do terminal/console
int terminal_x();

// retorna o tamanho da coluna do terminal/console
int terminal_y();

// limpa o buffer
void limpar_buffer();

#endif
