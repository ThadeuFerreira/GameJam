#include<stdio.h>
#include<limits.h>
#include<queue.h>

void create_queue(QUEUE* q){
    q->head = 0;
    q->tail = 0;
    q->total = 0;
    q->max = qtotal+1;
}

int q_is_empty(QUEUE q){
    if(q.total == 0){
        return 1;
    }
    return 0;
}

int q_is_full(QUEUE q){
    if(q.total == q.max-1){
        return 1;
    }
    return 0;
}

int in_queue(QUEUE* q,qtype n){
    if(!q_is_full(*q)){
        q->item[q->tail] = n;
        if(q->tail==q->max-1){
            q->tail = 0;
        }
        else{
            q->tail++;
        }
        q->total++;
        return 0;
    }
    return -1;
}

qtype out_queue(QUEUE* q){
    if(!q_is_empty(*q)){
        q->total--;
        if(q->head == q->max-1){
            q->head = 0;
            return q->item[q->max-1];
        }
        else{
            q->head++;
            return q->item[q->head-1];
        }
    }
    return INT_MIN;
}

qtype peek(QUEUE q){
    if(!q_is_empty(q)){
        return q.item[q.head];
    }
    return INT_MIN;
}
