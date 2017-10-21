#include<stdlib.h>
#include<stdio.h>

struct listNode_t{
   void* data;
   struct listNode_t* next;
   struct listNode_t* prev;
};

struct list_t{
   int size;
   struct listNode_t* start;
   struct listNode_t* end;
};

struct list_t* list_create(){
   struct list_t* list;
   list = (struct list_t*) malloc(sizeof(struct list_t));
   list->size = 0;
   list->start = NULL;
   list->end = NULL;
   return list;
}

struct listNode_t* listNode_create(){
   struct listNode_t* node;
   node = (struct listNode_t*)malloc(sizeof(struct listNode_t));
   node->data = NULL;
   node->next = NULL;
   node->prev = NULL;
   return node;
}

void list_push(struct list_t* list, void* number){
   struct listNode_t* node;
   node = listNode_create();
   node->prev = list->end;
   if(list->size == 0) list->start = node;
   else list->end->next = node;
   list->end = node;
   node->data = number;
   list->size++;
}

void list_unshift(struct list_t* list, void* number){
   struct listNode_t* node;
   node = listNode_create();
   node->next = list->start;
   if(list->size == 0) list->end = node;
   else list->start->prev = node;
   list->start = node;
   node->data = number;
   list->size++;
}

void* list_shift(struct list_t* list){
   if(list->size <= 0) return (void*)-1;
   void* numberToReturn;
   struct listNode_t* node;
   node = list->start;
   list->start = node->next;
   if(list->size > 1) list->start->prev = NULL;
   else list->end = NULL;
   numberToReturn = node->data;
   free(node);
   list->size--;
   return numberToReturn;
}

void* list_pop(struct list_t* list){
   if(list->size <= 0) return (void*)-1;
   void* numberToReturn;
   struct listNode_t* node;
   node = list->end;
   list->end = node->prev;
   if(list->size > 1) list->end->next = NULL;
   else list->start = NULL;
   numberToReturn = node->data;
   free(node);
   list->size--;
   return numberToReturn;
}

void* list_noPop(struct list_t* list){
   if(list->size == 0) return (void*)-1;
   return list->end->data;
}

void* list_noShift(struct list_t* list){
   if(list->size == 0) return (void*)-1;
   return list->start->data;
}

void* list_removeNode(struct list_t* list, struct listNode_t* node){
   if(node != list->start){
      node->prev->next = node->next;
   }
   else list->start = node->next;
   if(node != list->end){
      node->next->prev = node->prev;
   }
   else list->end = node->prev;
   
}

void* list_getElement(struct list_t* list, int index){
   if(index >= list->size) return (void*)-1;
   struct listNode_t* node;
   int aux;
   node = list->start; 
   for(aux = 0;aux < index; node = node->next) aux++;
   return node->data;
}

void* list_removeElement(struct list_t* list, int index){
   if(index >= list->size) return (void*)-1;
   struct listNode_t* node;
   int aux;
   void* valueToReturn;
   node = list->start; 
   for(aux = 0;aux < index; node = node->next) aux++;
   if(index != 0) node->prev->next = node->next;
   else list->start = node->next;
   if(index != list->size-1) node->next->prev = node->prev;
   else list->end = node->prev;
   valueToReturn = node->data;
   free(node);
   list->size--;
   return valueToReturn;
}

void* list_removeValue(struct list_t* list, void* value){
   struct listNode_t* node;
   int aux;
   for(node = list->start; node->data != value && node->next != NULL; node = node->next);
   if(node->data == value){
      if(node->next != NULL) node->next->prev = node->prev;
      else list->end = node->prev;
      if(node->prev != NULL) node->prev->next = node->next;
      else list->start = node->next;
   }
   else return (void*)-1;
   return (void*)0;
}

int list_hasData(struct list_t* list, void* data, void* (*getData)(void*)){
   struct listNode_t* node;
   for(node = list->start; node != NULL; node = node->next){
      if(getData(node->data) == data){
         return 1;
      }
   }
   return 0;
}

void list_delete(struct list_t* list){
   while(list->size > 0) list_pop(list);
   free(list);
}

void list_printInverted(struct list_t* list){
   struct listNode_t* node;
   node = list->end;
   printf("{ ");
   while(node != NULL){
      printf("%lld ",(long long)node->data);
      node = node->prev;
   }
   printf("}\n");
}

void list_print(struct list_t* list){
   struct listNode_t* node;
   node = list->start;
   printf("{ ");
   while(node != NULL){
      printf("%lld ",(long long)node->data);
      node = node->next;
   }
   printf("}\n");
}

void list_printInvertedBySize(struct list_t* list){
   int aux;
   struct listNode_t* node;
   printf("{ ");
   for(aux = 0, node = list->end;aux < list->size; aux ++, node = node->prev){
      printf("%lld ",(long long)node->data);
   }
   printf("}\n");
}

void list_printBySize(struct list_t* list){
   int aux;
   struct listNode_t* node;
   printf("{ ");
   for(aux = 0, node = list->start;aux < list->size; aux ++, node = node->next){
      printf("%lld ",(long long)node->data);
   }
   printf("}\n");
}

void list_printObject(struct list_t* list, void(*printObject)(void*)){
   struct listNode_t* node;
   printf("{ ");
   for(node = list->start; node != NULL; node = node->next){
      printObject(node->data);
      printf(", ");
   }
   printf("}\n");
}

void list_swapNodes(struct list_t* list, struct listNode_t* node1, struct listNode_t* node2){
   struct listNode_t* aux;

   if(list->start == node1){
      if(list->start == node2) return;
      else if(node2->prev != node1) node2->prev->next = node1;
      list->start = node2;
   }
   else{
      if(node1->prev != node2) node1->prev->next = node2;
      if(list->start == node2) list->start = node1;
      else if(node2->prev != node1) node2->prev->next = node1;
   }

   if(list->end == node1){
      if(list->end == node2) return;
      else if(node2->next != node1) node2->next->prev = node1;
      list->end = node2;
   }
   else{
      if(node1->next != node2) node1->next->prev = node2;
      if(list->end == node2) list->end = node1;
      else if(node2->next != node1) node2->next->prev = node1;
   }

   if(node1->next == node2){
      aux = node1->prev;
      node1->prev = node2;
      node2->prev = aux;

      aux = node2->next;
      node2->next = node1;
      node1->next = aux;
   }
   else if(node2->next == node1){
      aux = node2->prev;
      node2->prev = node1;
      node1->prev = aux;

      aux = node1->next;
      node1->next = node2;
      node2->next = aux;
   }
   else{
      aux = node1->prev;
      node1->prev = node2->prev;
      node2->prev = aux;

      aux = node1->next;
      node1->next = node2->next;
      node2->next = aux;
   }
}

void list_bubbleSort(struct list_t* list, int (*compareFunction)(void*, void*)){
   struct listNode_t* nodeAux;
   int aux;
   for(aux = list->size-1;aux >= 0; aux --){
      struct listNode_t* nodeAux2;
      int aux1;
      for(aux1 = 0, nodeAux2 = list->start; aux1 < aux; aux1 ++, nodeAux2 = nodeAux2->next){
         if(compareFunction(nodeAux2->data, nodeAux2->next->data) == 0) {
            list_swapNodes(list, nodeAux2, nodeAux2->next);
            nodeAux2 = nodeAux2->prev;
         }
      }
   }
}

void list_insertSortedElement(struct list_t* list, void* data, void* (*getData)(void*)){
   struct listNode_t* node;
   struct listNode_t* newNode;
   if(list->size == 0){
      list_push(list, data);
      return;
   }
   for(node = list->start; node != NULL && getData(node->data) < data; node = node->next);
   if(node == list->start){
      list_unshift(list, node);
      return;
   }
   if(node == NULL){
      list_push(list, node);
      return;
   }
   newNode = listNode_create();
   newNode->prev = node->prev;
   newNode->next = node;
   node->prev->next = newNode;
   node->prev = newNode;
   list->size += 1;
}
