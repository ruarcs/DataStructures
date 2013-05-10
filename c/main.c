#include "priorityQueue.h"

int main()
{
    int error;
    struct PriorityQueue* pq = init_PriorityQueue(&error);

    int test_data = 999;
    struct PriorityObject* obj = malloc(sizeof(struct PriorityObject));
    
    if(obj)
    {
	obj->priority = 100;
	obj->object_data = &test_data;
    }

    push(pq, obj, &error);
}
