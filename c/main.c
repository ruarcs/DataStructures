#include "priorityQueue.h"
#include <assert.h>

struct PriorityObject* createDummyObject(void* test_data, int test_priority)
{
    struct PriorityObject* obj = malloc(sizeof(struct PriorityObject));
    obj->priority = test_priority;
    obj->object_data = test_data;
    return obj;
}

int main()
{
    int error;
    struct PriorityQueue* pq = init_PriorityQueue(&error);

    int test_data1 = 100;
    int test_data2 = 1000;
    int test_data3 = 1;
    
    struct PriorityObject* obj1 = createDummyObject( (void*)&test_data1, 100);
    struct PriorityObject* obj2 = createDummyObject( (void*)&test_data2, 1000);
    struct PriorityObject* obj3 = createDummyObject( (void*)&test_data3, 1);

    push(pq, obj1, &error);
    push(pq, obj2, &error);
    push(pq, obj3, &error);


    void* data = pop(pq, &error);
    assert(data == &test_data2);

    data = pop(pq, &error);
    assert(data == &test_data1);

    assert(!(isEmpty(pq, &error)));
    assert(size(pq, &error) == 1);

    data = pop(pq, &error);
    assert(data == &test_data3);

    assert(isEmpty(pq, &error));

    free_PriorityQueue(pq, &error);

    return 0;
}
