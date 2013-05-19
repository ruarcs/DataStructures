#include "priorityQueue.h"
#include <assert.h>
#include "person.h"

int main()
{
    int error;
    struct PriorityQueue* pq = init_PriorityQueue(&error);

    char name1[] = "John";
    char name2[] = "Mary";
    char name3[] = "Pete";

    struct person* person1 = init_person(25, 145, name1);
    struct person* person2 = init_person(67, 125, name2);
    struct person* person3 = init_person(44, 132, name3);
    
    struct PriorityObject* obj1 = createPriorityObject(&person1, person1->age);
    struct PriorityObject* obj2 = createPriorityObject(&person2, person2->age);
    struct PriorityObject* obj3 = createPriorityObject(&person3, person3->age);

    push(pq, obj1, &error);
    push(pq, obj2, &error);
    push(pq, obj3, &error);


    void* data = pop(pq, &error);
    assert(data == obj2);

    data = pop(pq, &error);
    assert(data == obj3);

    assert(!(isEmpty(pq, &error)));
    assert(size(pq, &error) == 1);

    data = pop(pq, &error);
    assert(data == obj1);

    assert(isEmpty(pq, &error));

    free_PriorityQueue(pq, &error);

    return 0;
}
