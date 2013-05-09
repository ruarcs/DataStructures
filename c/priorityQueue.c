#include<stdlib.h>
#include <stdbool.h>

struct element
{
    const void* data;
    int priority;
}

struct priorityQueue
{
    int* head_of_list_of_priorities;
    unsigned long* head_of_list_of_pointers;
    struct element* head_of_list_of_elements;

    int current_highest;
    int current_lowest;
}

/****************************************************************************
 We will intentionally prevent the user from duplicating priorities.
 If we attempt to push with a priority in the array then return false.
 It's up to the calling file to check this.
 ***************************************************************************/
bool push(struct priorityQueue* queue, const void* data, int priority)
{
    
}

void* pop(struct priorityQueue* queue)
{
    
}

void* peek(const struct priorityQueue* queue)
{
    
}

int size(const struct priorityQueue* queue)
{
    
}

bool isEmpty(const struct priorityQueue* queue)
{
    
}

int highestPriority(const struct priorityQueue* queue)
{
    
}

int lowestPriority(const struct priorityQueue* queue)
{
    
}



