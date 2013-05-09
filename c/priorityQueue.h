#include<stdlib.h>
#include <stdbool.h>

/************************
 * Forward declarations *
 ************************/
struct PriorityQueue;


/**********************
 * Struct definitions *
 **********************/
struct PriorityObject
{
    int priority;
    void* object_data;
};

/************************
 * Function Definitions *
 ************************/

bool push(struct PriorityQueue* queue,
	  struct PriorityObject* new_object,
	  int* error);

void* pop(struct PriorityQueue* queue,
	  int* error);

void* peek(const struct PriorityQueue* queue,
	   int* error);

int size(const struct PriorityQueue* queue,
	 int* error);

bool isEmpty(const struct PriorityQueue* queue,
	     int* error);
