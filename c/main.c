#include "priorityQueue.h"
#include <assert.h>
#include "person.h"

int main()
{
    int error;
    struct PriorityQueue* pq = init_PriorityQueue(&error/*, PQ_TYPES_PERSON*/);

    const char* name1[] = "John";
    const char* name2[] = "Mary";
    const char* name3[] = "Pete";

    struct person person1 = init_person(25, 145, name1);
    struct person person2 = init_person(67, 125, name2);
    struct person person3 = init_person(44, 132, name3);
    
    struct PriorityObject* obj1 = createDummyObject(&person1, person1->age);
    struct PriorityObject* obj2 = createDummyObject(&person2, person2->age;
    struct PriorityObject* obj3 = createDummyObject(&person3, person3->age;

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
