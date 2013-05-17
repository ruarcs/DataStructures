#include<stdlib.h>
#include <stdbool.h>


/********************
 * Enum definitions *
 ********************/
enum ERRORS
{
    PQ_NO_ERROR,
    PQ_NULL_POINTER,
    PQ_EMPTY_QUEUE,
    PQ_BAD_ALLOC
};

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

struct PriorityQueue* init_PriorityQueue(int* error);

void free_PriorityQueue(struct PriorityQueue* queue,
                        int* error);

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

struct PriorityObject* createPriorityObject(void* data,
                                            int priority);
