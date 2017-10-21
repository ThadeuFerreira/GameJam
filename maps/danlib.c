#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

void init(){
	srand(time(NULL));
    hide_cursor();
}

//void maximizar(){
//	HWND a = GetForegroundWindow();
//	ShowWindow(a,3);
//}

void hide_cursor(){
	system("");
	printf("\e[?25l");
}

int random(int mini, int maxi){
	return mini+rand()%(maxi-mini+1);
}

void newMapa(mapa * m, int alt, int lar){
	m->alt = alt;
	m->lar = lar;
	m->c = malloc(alt*sizeof(char*));
	int i;
	for(i=0;i<alt;i++){
		m->c[i] = malloc(lar*sizeof(char));
	}
	//limpar
	int j;
	for(i = 0;i<alt;i++){
		for(j = 0;j<lar;j++){
			m->c[i][j] = '.';
		}
	}
}

void printMapa(mapa m){
	int i,j;
	for(i = 0;i<m.alt;i++){
		for(j = 0;j<m.lar;j++){
			printf("%c ",m.c[i][j]);
		}
		printf("\n");
	}
}


int draw(char** matriz_antiga, char** matriz_nova, int x_matriz, int y_matriz){
    int i,j;
    //caso as duas sejam iguais nao perde tempo fazendo calculos
    if(matriz_antiga == matriz_nova)
        return -1;
    //aceita matriz antiga como NULL, nesse caso soh printa a matriz_nova
    //NAO MODIFICAR AQUI
    if(matriz_antiga == NULL){
        system("cls");
        for(i = 0;i<y_matriz;i++){
            for(j = 0;j<x_matriz;j++){
                printf("%c",matriz_nova[i][j]);
            }
        printf("\n");
        }
        return x_matriz*y_matriz;
    }

    //salva a coord do cursor na pos atual
    int x,y;
    x = get_cursor_x();
    y = get_cursor_y();
    int cont = 0;
    //procura as diferencas entre as matrizes
    //se achar: vai na posicao substitui pela matriz_nova
    for(i = 0;i<y_matriz;i++){
        for(j = 0;j<x_matriz;j++){
            if(matriz_antiga[i][j] != matriz_nova[i][j]){
                set_cursor(j,i);
                matriz_antiga[i][j] = matriz_nova[i][j];

                printf("%c", matriz_nova[i][j]);
                printf("\e[m");

                cont++;
            }
        }
    }

    //volta para a coord onde o cursor estava
    set_cursor(x,y);
    return cont;
}

//int terminal_x(){
//    CONSOLE_SCREEN_BUFFER_INFO t;
//    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&t);
//    return t.srWindow.Right - t.srWindow.Left + 1;
//}
//int terminal_y(){
//    CONSOLE_SCREEN_BUFFER_INFO t;
//    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&t);
//    return t.srWindow.Bottom - t.srWindow.Top + 1;
//}

char getKey(){
	return tolower(getch());
}
char* toUpper(char* texto){
	char* textoR = malloc(1);
        int aux, size = 0;
        for(aux = 0;texto[aux-1] != '\0'; aux ++){
		if(texto[aux] >= 'a' && texto[aux] <= 'z'){
			textoR[aux] = texto[aux] + ('A' - 'a');
		}
		else{
			textoR[aux] = texto[aux];
		}
		size++;
		textoR = realloc(textoR, size+1);
	}
	return &textoR;
}
int set_cursor(int x,int y){
    if(x < 0 || y < 0){
        return -1;
    }
    printf("\e[%d;%dH",y+1,x+1);

    return 0;
}

void save_cursor_pos(){
	printf("\e[s");
}

void load_cursor_pos(){
	printf("\e[u");
}

//==================WINDOWS================

int get_cursor_x(){
    CONSOLE_SCREEN_BUFFER_INFO t;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&t);
    return t.dwCursorPosition.X;
}
int get_cursor_y(){
    CONSOLE_SCREEN_BUFFER_INFO t;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&t);
    return t.dwCursorPosition.Y;
}
