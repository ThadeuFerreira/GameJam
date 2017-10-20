#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<maps.h>
#include<files.h>


void set_rect_map(MAP* m,int y,int x,char wall){
    int i,j;
    m->cinfo = '0';
    m->campo = (char**)malloc(sizeof(char*)*y);
    for(i=0;i<y;i++){
        m->campo[i] = (char*)malloc(sizeof(char)*x);
    }

    for(i=0;i<y;i++){
        m->campo[i][0] = wall;
        m->campo[i][x-1] = wall;
    }

    for(j=0;j<x;j++){
        m->campo[0][j] = wall;
        m->campo[y-1][j] = wall;
    }

    for(i=1;i<y-1;i++){
        for(j=1;j<x-1;j++){
            m->campo[i][j] = ' ';
        }
    }
    m->y = y;
    m->x = x;
}

int load_map_from_file(MAP* m,char* name){
    FILE* p = fopen(name,"r");
    if(p==NULL){
        return -1;
    }
    char* aux;
    scan_file(name,&aux);
    int i=0,l = strlen(aux);
    free(aux);
    m->x = 0;
    m->y = 0;
    int j=0;
    m->cinfo = '1';
    m->iinfo = (int*)malloc(sizeof(int));
    m->campo = (char**)malloc(sizeof(char*));
    m->campo[0] = (char*)malloc(sizeof(char));
    while(i<l){
        if(fgetc(p) == '\n'){
            m->iinfo = (int*)realloc(m->iinfo,sizeof(int)*(m->y+1));
            m->iinfo[m->y] = (j);
            m->y++;
            m->campo = (char**)realloc(m->campo,sizeof(char*)*(m->y+1));
            m->campo[m->y] = (char*)malloc(sizeof(char));
            j=0;
            i++;
        }
        else{
            fseek(p,-1,1);
            m->campo[m->y] = (char*)realloc(m->campo[m->y],sizeof(char)*(j+1));
            m->campo[m->y][j] = fgetc(p);
            j++;
            i++;
        }
    }
    m->iinfo = (int*)realloc(m->iinfo,sizeof(int)*(m->y+1));
    m->iinfo[m->y] = j;
    m->y++;
    fclose(p);
    return 0;
}

int print_rect_map(MAP m){
    if(m.cinfo == '1'){
        return -1;
    }
    int i,j;
    for(i=0;i<m.y;i++){
        for(j=0;j<m.x;j++){
            printf("%c",m.campo[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int print_irregular_map(MAP m){
    int i,j;
    if(m.cinfo == '0'){
        return -1;
    }
    for(i=0;i<m.y;i++){
        for(j=0;j<m.iinfo[i];j++){
            printf("%c",m.campo[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void free_map(MAP* m){
    int i;
    if(m->cinfo == '1'){
        free(m->iinfo);
    }
    for(i=0;i<m->y;i++){
            free(m->campo[i]);
    }
    free(m->campo);
}
