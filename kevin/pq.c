/*
 Priority Queue using heap data structure.  
 
 Instead of linked list, I used an array of structs.
 Each struct has a priority, and some data assoc.
 The total field is only used by index 0, to count
 total members in queue.
 
 Using linked lists with a heap seems to be really
 bad, I think it's even worse than bubble sort?
 
 A way to get around the static assignment, might be
 to realloc() with double the set heapsize?
 
 Note: calling quickSort() will de-queue all 
 elements of current queue
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int total;
  int priority;
  char data[50];
} queue;

#define HEAPSIZE 100
#define PARENT(i) i/2
#define LEFT(i) i*2
#define RIGHT(i) (i*2)+1

void swap(queue* a, queue* b) { queue temp = *a; *a = *b; *b = temp;  }

void heapify(queue* q, int i,int max) {
  if (LEFT(i) > q[0].total) max=i;
  else if (RIGHT(i) > q[0].total) max=LEFT(i);
  else max = q[LEFT(i)].priority > q[RIGHT(i)].priority ? LEFT(i) : RIGHT(i);
  q[max].priority > q[i].priority ? swap(&q[max],&q[i]), heapify(q,max,0) : NULL;
}

void pop(queue* q) {
  if (q[0].total==0) printf("error: empty heap\n");
  else {
    printf("popped %d\n",q[1].priority);
    swap(&q[1],&q[q[0].total--]);
    heapify(q,1,0);
  }
}

void printHeap(queue* q,int i,int total) {
  if (q[0].total==0) printf("error: empty heap\n");
  else {
    printf("-- heap contents --\n");
    for(;i < total;i++) {
      printf("priority: %d\n",q[i].priority);
      printf("data: %s",q[i].data);
      printf("-------------------\n");
    }
  }
}

void enterData(queue* q,int i) {
  char* t = malloc(sizeof(char)*10);
  printf("enter priority:\n");
  fgets(t,10,stdin);
  q[i].priority = strtol(t,NULL,0);
  fflush(stdin);
  printf("enter data:\n");
  fgets(q[i].data,50,stdin);
  fflush(stdin);
}

void push(queue* q,int i) {
  enterData(q,i);
  while(i>1 && q[PARENT(i)].priority < q[i].priority) {
      swap(&q[PARENT(i)],&q[i]);
      i = PARENT(i);
  }
}

void heapSort(queue* q) {
  if (q[0].total==0) printf("error: empty heap\n");
  else {
    queue sortedQueue[HEAPSIZE];
    int total = q[0].total,i=0;
    for(;i<total;i++) {
      sortedQueue[i] = q[1];
      pop(q);
    }
    printHeap(sortedQueue,0,total);
    }
 }

void printOptions() {
  printf(
  "\n\t-------------------\n"
  "\t1: add data to heap\n"
  "\t2: remove top elem \n"
  "\t3: print heap      \n"
  "\t4: heap sort       \n"
  "\t5: quit program    \n"
  "\t-------------------\n\n"
  );
}

int main() {
  queue q[HEAPSIZE];
  char opt[100];
  q[0].total = 0;
  while(1) {
    printOptions();
    fgets(opt,100,stdin);
    switch(strtol(opt,NULL,0)) {
    case 1:
      push(q,++q[0].total); 
      break;
    case 2:
      pop(q);
      break;
    case 3:
      printHeap(q,1,q[0].total+1);
      break;
    case 4:
      heapSort(q);
      break;
   case 5:
      exit(0); 
   default:
      printf("error: invalid input\n"); 
      break;
    }
    fflush(stdin);
  }
  return 0;
}