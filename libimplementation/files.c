#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<files.h>

int fcreate(char* name){
	FILE* novo = fopen(name,"r");
	if(novo != NULL){
        return -1;
	}
	novo = fopen(name,"a+");
	fclose(novo);
	return 0;
}

int scan_file(char *name,char **aux){
	FILE* p = fopen(name,"r");
	if(p == NULL){
		return -1;
	}
	(*aux) = (char*)malloc(sizeof(char));
	int i=0;
	while(fgetc(p) != EOF){
		fseek(p,-1,1);
		(*aux)[i] = fgetc(p);
		i++;
		(*aux) = (char*)realloc((*aux),(i+1)*sizeof(char));
	}
	if(i>0){
        (*aux)[i] = '\0';
	}
	else{
            (*aux)[0] = '\0';
        return -2;
	}
	return 0;
}

int delete_from_file(char* name,char* string){
	char* s = string;
	int j,t2,t = strlen(s);
	FILE* p = fopen(name,"r");
	if(p==NULL){
		return -1;
	}
	char *pp,*aux;
	scan_file(name,&aux);
	pp = strstr(aux,s);
	if(pp == NULL){
		free(aux);
		return -2;
	}
	t2 = strlen(aux);
	fclose(p);
	p = fopen(name,"w");
	for(j=0;j<t2;j++){
		if(&aux[j] == pp){
			j+=t;
			if(j>=t2){
				break;
			}
		}
		fprintf(p,"%c",aux[j]);
	}
	free(aux);
	fclose(p);
	return 0;
}

int update_file(char* name,char* old_string,char* new_string){
	char* s = old_string, *ss = new_string;
	int k,j,t2,t = strlen(s),nt = strlen(ss),d = t - nt;
	FILE* p = fopen(name,"a+");
	if(p==NULL){
		return -1;
	}
	char *pp,*aux = (char*)malloc(sizeof(char));
	scan_file(name,&aux);
	pp = strstr(aux,s);
	if(pp == NULL){
		free(aux);
		fclose(p);
		return -2;
	}
	t2 = strlen(aux);
	fclose(p);
	p = fopen(name,"w");
	for(j=0;j<t2;j++){
		if(&aux[j] == pp){
			j-=d;
			for(k=0;k<nt;k++){
				fprintf(p,"%c",ss[k]);
			}
			if(j>=t2){
				break;
			}
			continue;
		}
		fprintf(p,"%c",aux[j]);
	}
	free(aux);
	fclose(p);
	return 0;
}

char* search_in_file(char* name,char* string){
	FILE* p = fopen(name,"r");
	if(p==NULL){
		return "-1";
	}
	char* aux;
	scan_file(name,&aux);
	fclose(p);
	char* pos;
	pos = strstr(aux,string);
	while(pos != NULL){
		if(pos == NULL){
			free(aux);
			return "-2";
		}
		int t = strlen(string),t2=strlen(aux),i;
		for(i=0;i<t2;i++){
			if(&aux[i] == pos){
				break;
			}
		}
		if(i == 0){
			if(pos[t] == ' ' || pos[t] =='\n' || pos[t] == '\0'){
				free(aux);
				return pos;
			}
		}
		else if(i==t2-1){
			if(pos[-1] == ' ' || pos[-1] == '\0' || pos[-1] == '\n'){
				free(aux);
				return pos;
			}
		}
		else if(pos[t] == ' ' || pos[t] =='\n' || pos[t] == '\0'){
			if(pos[-1] == ' ' || pos[-1] == '\0' || pos[-1] == '\n'){
				free(aux);
				return pos;
			}
		}
		pos = strstr(pos+1,string);
	}
	free(aux);
	return "-2";
}

int add_to_file(char* name,char* s,int pos){
    FILE* p = fopen(name,"r");
    if(p == NULL){
        return -1;
    }
    char* aux;
    scan_file(name,&aux);
    fclose(p);
    int k = strlen(aux);
    if(pos > k){
        free(aux);
        return -2;
    }
    int i,t = strlen(aux),t2 = strlen(s);
    if(t==0 || t == pos){
        p = fopen(name,"a+");
        fseek(p,0,2);
        fprintf(p,"%s",s);
    }
    else{
        p = fopen(name,"w");
        for(i=0;i<t;i++){
            if(i == pos){
                int j;
                for(j=0;j<t2;j++){
                    fprintf(p,"%c",s[j]);
                }
            }
            fprintf(p,"%c",aux[i]);
        }
    }
    //fprintf(p,"\0");
    fclose(p);
    free(aux);
    return 0;
}

int reset_file(char* name){
    FILE* p = fopen(name,"w");
    if(p == NULL){
        return -1;
    }
    fclose(p);
    return 0;
}

int filelen(char* name){
    char *aux;
    int i;
    i = scan_file(name,&aux);
    if(i == -1){
        return -1;
    }
    i = strlen(aux);
    free(aux);
    return i;
}
