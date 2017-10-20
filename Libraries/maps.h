#ifndef _MAPS
#define _MAPS

typedef struct m{
    int x,y;
    char** campo;
    char cinfo;
    int* iinfo;
}MAP;

// cria um mapa retangular com tamanho e borda customizavel(y,x,wall)
// *e necessario liberar o mapa da memoria com a funcao free_map()*
void set_rect_map(MAP* m,int y,int x,char wall);

// carrega o conteudo de um arquivo e o passa para o mapa
// *e necessario liberar o mapa da memoria com a funcao free_map()*
// paring do arquivo: nao e necessario entrar o tamanho do mapa
// retorno: -1, o arquivo nao foi encontrado ; 0, nao houve erro
int load_map_from_file(MAP* m,char* name);

// printa na tela um ampa retangular
// retorno: -1, quando um mapa irregular foi passado como argumento ; 0, nao houve erro
int print_rect_map(MAP m);

// printa na tela um mapa irregular
// retorno: -1, quando um mapa retangular foi passado como argumento ; 0, nao houve erro
int print_irregular_map(MAP m);

// usado para liberar um mapa da heap
void free_map(MAP* m);

#endif
