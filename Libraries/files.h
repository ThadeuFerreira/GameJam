#ifndef _FILE
#define _FILE

// fazer as funcoes para enesimo encontro


// cria um arquivo com o nome 'name'
// retorno: -1, arquivo ja existe ; 0, nao houve erro
int fcreate(char* name);

// le todo um arquivo e armazena em 'aux', um endereco sera atribuido na funco, *nao aloque a variavel*
// fica  para o programador dar free em 'aux' posterior ao seu uso
// retorno: -1, arquivo nao encontrado ; -2, o arquivo esta vazio ; 0, nao houve erro ;
int scan_file(char* name,char **aux);

// procura no arquivo por uma substring 'string' e a retira de seu conteudo
// retorno: -1, arquivo nao encontrado ; -2, 'string' nao foi encontrada dentro do arquivo  ; 0 nao houve erro ;
int delete_from_file(char* name,char* string);

// procura por 'old_string' dentro de um arquivo e a substitui por 'new_string'
// retorno: -1, arquivo nao encontrado ; -2, 'old_string' nao foi encontrada dentro do arquivo  ; 0 nao houve erro ;
int update_file(char* name,char* old_string,char* new_string);

// encontra uma string isolada(espaço ou \n antes e depois)em uma file e retorna seu endereco
// retorno: "-1": arquivo nao encontrado ; "-2", 'string' nao foi encontrada no arquivo ; else: o endereco da posicao onde se encontra 'string' no arquivo
char* search_in_file(char* name,char* string);

// adiciona no arquivo 'string' na posicao 'pos'(que vai de 0 a strlen(string)), *sem sobreescrever*
// retorno: -1, arquivo nao encontrado ; -2, pos e maior que o tamanho do conteudo do arquivo  ; 0 nao houve erro ;
int add_to_file(char* name,char* string,int pos);

// limpa o arquivo
// retorno: -1, o arquivo nao foi encontrado ; 0, nao houve erro
int reset_file(char* name);

// retorna o numero de caracteres armazenados no arquivo, ou -1 caso o arquivo nao tenha sido encontrado
int filelen(char* name);

#endif
