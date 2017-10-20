#include<stdio.h>
#include<stdlib.h>
#include<stack.h>
#include<limits.h>

void create_stack(STACK* s){
    s->top = -1;
    s->max = stotal;
    s->size = 0;
}

int s_is_full(STACK s){
    if(s.top == s.max -1){
        return 1;
    }
    return 0;
}

int s_is_empty(STACK s){
    if(s.top == -1){
        return 1;
    }
    return 0;
}

int push(STACK* s,stype t){
    if(!s_is_full(*s)){
        s->top++;
        s->item[s->top] = t;
        return 0;
    }
    return -1;
}

stype pop(STACK* s){
    if(!s_is_empty(*s)){
        s->top--;
            return s->item[s->top+1];
    }
    return INT_MIN;
}

stype pull(STACK s){
    if(s_is_empty(s)){
        return INT_MIN;
    }
    return s.item[s.top];
}

void s_shuffle(STACK* s){
    int i,r,r2;
    stype aux;
    for(i = 0 ; i <= s->top ; i++){
        r = rand()%(s->top+1);
        r2 = rand()%(s->top+1);
        aux = s->item[r];
        s->item[r] = s->item[r2];
        s->item[r2] = aux;
    }
}
