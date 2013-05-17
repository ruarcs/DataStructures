#include "person.h"

/*
  This function will make you a whole new person........hweh hweh hweh........
 */

struct person*
init_person(int age, int height, const char* name)
{
    struct person* new_person = malloc(sizeof(struct person));

    if(!person)
    {
        return NULL;
    }

    new_person->age = age;
    new_person->height = height;
    new_person->name = name;

    return new_person;
}
