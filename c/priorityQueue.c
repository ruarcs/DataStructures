#include "priorityQueue.h"
#include <assert.h>

/**********************
 * Struct definitions *
 **********************/
struct Element
{
    struct PriorityObject* elem_data;
    struct Element* next;
    struct Element* previous;
};

struct PriorityQueue
{
    struct Element* tail;
    int size;
};




/**********************
 *  Static function   *
 *   declarations     *
 **********************/
static
bool
place_before_current(struct PriorityQueue* queue,
		     struct Element* current,
		     struct PriorityObject* new);

static
bool
place_after_current(struct PriorityQueue* queue,
		    struct Element* current,
		    struct PriorityObject* new);

static
bool
has_greater_priority(struct PriorityObject* new_object,
		     struct PriorityObject* current);





/**********************
 *      Function      *
 *     Definitions    *
 **********************/

struct PriorityQueue*
init_PriorityQueue(int* error)
{
    *error = PQ_NO_ERROR;
    struct PriorityQueue* pq = malloc(sizeof(struct PriorityQueue));

    if(!pq)
    {
	    *error = PQ_BAD_ALLOC;
	    return NULL;
    }
    
    pq->tail = NULL;
    pq->size = 0;

    return pq;
}

void
free_PriorityQueue(struct PriorityQueue* p, int* error)
{
    error = PQ_NO_ERROR;
    //TO BE COMPLETED
}

bool 
push(struct PriorityQueue* queue,
     struct PriorityObject* new_object,
     int* error)
{
    // This is the most work! Start at tail of list.
    // If the new object has gearter priority then
    // place after the current one.
    // If we get to the start and we haven't found a
    // place for it then put it at the start.

    *error = PQ_NO_ERROR;
    if(!queue)
    {
	    *error = PQ_NULL_POINTER; 
	    return false;
    }

    struct Element* temp = queue->tail;

    int count = 0;
    
    while(count++ < queue->size)
    {
	    if(has_greater_priority(new_object, temp->elem_data))
	    {
	        place_after_current(queue, temp, new_object);
	    }
    }

    //Make the new object the head of the list.
    //Place new object after this one
    place_before_current(queue, temp, new_object);
}

void* 
pop(struct PriorityQueue* queue, int* error)
{
    *error = PQ_NO_ERROR;
    if(!queue)
    {
	    *error = PQ_NULL_POINTER;	
	    return NULL;
    }

    if(queue->size == 0)
    {	
	    *error = PQ_EMPTY_QUEUE;	
	    return NULL;
    }  

    struct Element* temp = queue->tail;
    queue->tail = queue->tail->previous;
    return(temp->elem_data->object_data);
}

void* 
peek(const struct PriorityQueue* queue, int* error)
{
    *error = PQ_NO_ERROR;
    if(!queue)
    {
	    *error = PQ_NULL_POINTER;
	    return NULL;
    }

    if(queue->size == 0)
    {	
	    *error = PQ_EMPTY_QUEUE;	
	    return NULL;
    }

    return(queue->tail->elem_data->object_data);
}

int 
size(const struct PriorityQueue* queue, int* error)
{
    *error = PQ_NO_ERROR;
    if(!queue)
    {
	    *error = PQ_NULL_POINTER;
	    return 0;
    }

    return (queue->size);
}

bool 
isEmpty(const struct PriorityQueue* queue, int* error)
{
    *error = PQ_NO_ERROR;
    if(!queue)
    {
	*error = PQ_NULL_POINTER;
	return true;
    }

    return (queue->size == 0);   
}





/***********************************************************
                      * STATIC FUNCTIONS *
 ***********************************************************/

static
bool
place_before_current(struct PriorityQueue* queue,
		     struct Element* current,
		     struct PriorityObject* new)
{
    assert(false);
    return false;
}

static
bool
place_after_current(struct PriorityQueue* queue,
		    struct Element* current,
		    struct PriorityObject* new)
{
    struct Element* new_element = malloc(sizeof(struct Element));

    if(!new_element)
    {
	    return false;
    }

    //Place new object after current one
    struct Element* holder = current;    
    current->next->previous = new_element;
    current->next = new_element;

    new_element->previous = current;
    new_element->next = holder->next;  

    return true;
}

static
bool
has_greater_priority(struct PriorityObject* new_object,
		     struct PriorityObject* current)
{
    assert(new_object != NULL);
    assert(current != NULL);
    
    if(current->priority < new_object->priority)
    {
	    return true;
    }
    return false;
}
