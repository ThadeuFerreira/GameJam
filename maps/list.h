#ifndef _LIBRARY_LIST_H_
#define _LIBRARY_LIST_H

struct listNode_t{
   int data;
   struct listNode_t* next;
   struct listNode_t* prev;
};

struct list_t{
   int size;
   struct listNode_t* start;
   struct listNode_t* end;
};

//creates the list, alocating its memory
struct list_t* list_create();

//creates a node, alocating its memory
struct listNode_t* listNode_create();

//puts a new element at the end of the list
void list_push(struct list_t*, void*);

//puts a new element at the start of the list
void list_unshift(struct list_t*, void*);

//removes and return the last element of the list
void* list_pop(struct list_t*);

//removes and returns the first element of the list
void* list_shift(struct list_t*);

//same as list_pop, but doesnt remove the element
void* list_noPop(struct list_t*);

//same as list_shift, but doesnt remove the element
void* list_noShift(struct list_t*);

//free all memory and destroy the list
void list_delete(struct list_t*);

//return the value of the element given, without deleting it
void* list_getElement(struct list_t*, int);

//same as list_getElement, but removes the element
void* list_removeElement(struct list_t*, int);

//removes the first element with a given value
void* list_removeValue(struct list_t*, void*);

//function for debugging purposes, prints the whole list without removing its elements
void list_print(struct list_t*);
void list_bubbleSort(struct list_t* list, int (*compareFunction)(void*, void*));
void list_swapNodes(struct list_t* list, struct listNode_t* node1, struct listNode_t* node2);
void list_printBySize(struct list_t* list);
void list_printInverted(struct list_t* list);
void list_printInvertedBySize(struct list_t* list);
int list_hasData(struct list_t* list, void* data, void* (*getData)(void*));
void list_printObject(struct list_t* list, void(*printObject)(void*));
void* list_removeNode(struct list_t* list, struct listNode_t* node);

#endif
