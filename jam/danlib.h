typedef struct{
	char **c;
	int alt,lar;
}mapa;

//===========CORES=============
#define DFT "\e[m"
#define RED "\e[1;31m"
#define GREEN "\e[1;32m"
#define YELLOW "\e[1;33m"
#define BLUE "\e[1;34m"
#define MAGENTA "\e[1;35m"
#define CYAN "\e[1;36m"

//============================

void maximizar();
void init();
//retorna o numero de modificacoes feitas entre a matriz_antiga e a matriz_nova ou -1 se elas forem iguais
int draw(char** matriz_antiga, char** matriz_nova, int x_matriz, int y_matriz);
void newMapa(mapa * m,int alt, int lar);
void printMapa(mapa m);
int random(int mini, int maxi);
int terminal_x();
int terminal_y();
char getKey();
char* toUpper(char* texto);
int set_cursor(int x,int y);
int get_cursor_x();
int get_cursor_y();
void hide_cursor();
