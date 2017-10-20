#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<utilites.h>

void spaces(char caracter,int vezes){
    int i;
    for(i=0;i<vezes;i++){
        printf("%c",caracter);
    }
}

int random(int min,int max){
    if(min > max){
        return -1;
    }
	return rand()%(max-min+1) + min;
}

void pause(int i){
    if(i==0){
        printf(pause_message_0);
    }
    else if(i==1){
        printf(pause_message_1);
    }
    else if(i==2){
        printf(pause_message_2);
    }
    else if(i==3){
        printf(pause_message_3);
    }
	printf("\n");
	getch();
}

void espaco_barran(char* s){
    int i=0;
    while(s[i] != ' '){
        i++;
    }
    s[i] = '\n';
}

void espaco_barra0(char* s){
    int i=0;
    while(s[i] != ' '){
        i++;
    }
    s[i] = '\0';
}

void barran_espaco(char* s){
    int i=0;
    while(s[i] != '\n'){
        i++;
    }
    s[i] = ' ';
}

void barran_barra0(char* s){
    int i=0;
    while(s[i] != '\n'){
        i++;
    }
    s[i] = '\0';
}

void barra0_barran(char* s){
    int i=0;
    while(s[i] != '\0'){
        i++;
    }
    s[i] = '\n';
}

void barra0_espaco(char* s){
    int i=0;
    while(s[i] != '\0'){
        i++;
    }
    s[i] = ' ';
}

int tamanho_ate_enesimo_char(char* string,char c,int n){
    if(n <= 0){
        return -1;
    }
    int i,j=0;
    for(i=0;i<n;i++){
        while(string[j] != c){
            j++;
        }
        j++;
    }
    return --j;
}

int maxvec(int* v,int n){
    int i,max = v[0];
    for(i=1;i<n;i++){
        if(v[i]>max){
            max = v[i];
        }
    }
    return max;
}

int minvec(int* v,int n){
    int i,min = v[0];
    for(i=1;i<n;i++){
        if(v[i]<min){
            min = v[i];
        }
    }
    return min;
}

void print_boxed_string(char* s,int e,char b){

}

char* ocorrencia_n(char* source,char* sub_string,int n){
    if(n<=0){
        return NULL;
    }
    int i;
    char* ptr = source;
    for(i=0;i<n;i++){
        ptr = strstr(ptr,sub_string);
        if(ptr == NULL){
            return NULL;
        }
        ptr++;
    }
    return --ptr;
}

int terminal_x(){
    CONSOLE_SCREEN_BUFFER_INFO t;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&t);
    return t.srWindow.Right - t.srWindow.Left + 1;
}

int terminal_y(){
    CONSOLE_SCREEN_BUFFER_INFO t;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&t);
    return t.srWindow.Bottom - t.srWindow.Top + 1;
}

void limpar_buffer(){
    _iob[0]._cnt = 0; //melhor fucao, flws
}

