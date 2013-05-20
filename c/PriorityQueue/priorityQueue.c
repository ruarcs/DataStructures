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
free_PriorityQueue(struct PriorityQueue* pq, int* error)
{
    *error = PQ_NO_ERROR;
    if(!pq)
    {
        *error = PQ_NULL_POINTER;
        return;
    }

    struct Element* temp = pq->tail;
    struct Element* next_to_delete = NULL;

    if(temp)
    {
        do
        {
            next_to_delete = temp->previous;
            free(temp);
            pq->size--;
            temp = next_to_delete;
        }
        while(next_to_delete != NULL);
    }
  
    return;
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

    if(temp == NULL)
    {
    	//Zero element list. Make it the tail
        struct Element* new_element = malloc(sizeof(struct Element));
        if(!new_element)
        {
        	*error = PQ_BAD_ALLOC;
    	    return false;
        }

        new_element->elem_data = new_object;
        new_element->previous = NULL;
        new_element->next = NULL;

        queue->tail = new_element;
        queue->size = 1;
        return true;
    }
    
    void* holder = NULL;

    do
    {
	    if(has_greater_priority(new_object, temp->elem_data))
	    {
            //Place new object after temp
	        place_after_current(queue, temp, new_object);
            return true;
	    }
        holder = temp;
        temp = temp->previous;
    }
    while(temp != NULL);

    //Place new object before temp
    place_before_current(queue, (struct Element*)holder, new_object);
    return true;
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
    void* holder = temp->elem_data;
    free(temp);
    queue->size--;
    return(holder);
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
    assert(queue != NULL);
    assert(current != NULL);
    assert(new != NULL);

    struct Element* new_element = malloc(sizeof(struct Element));

    if(!new_element)
    {
	    return false;
    }
    new_element->elem_data = new;

    //Place new object before current one:
    void* holder = current->previous;

    if(current->previous)
    {
    	current->previous->next = new_element;
    }
    current->previous = new_element;

    new_element->next = current;
    new_element->previous = holder;

    if(new_element->next == NULL)
    {
    	queue->tail = new_element;
    }
    queue->size++;

    return true;
}

static
bool
place_after_current(struct PriorityQueue* queue,
		    struct Element* current,
		    struct PriorityObject* new)
{
    assert(queue != NULL);
    assert(current != NULL);
    assert(new != NULL);

    struct Element* new_element = malloc(sizeof(struct Element));

    if(!new_element)
    {
	    return false;
    }
    new_element->elem_data = new;

    //Place new object after current one
    void* holder = current->next;

    if(current->next)
    {
    	current->next->previous = new_element;
    }
	current->next = new_element;

    new_element->previous = current;
    new_element->next = holder;

    if(new_element->next == NULL)
    {
    	queue->tail = new_element;
    }
    queue->size++;

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


/**********************
 *       Helpers      *
 **********************/
struct PriorityObject* 
createPriorityObject(void* data, int priority)
{
     struct PriorityObject* obj = malloc(sizeof(struct PriorityObject));
     obj->priority = priority;
     obj->object_data = data;
     return obj;
 }
