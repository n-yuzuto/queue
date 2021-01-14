#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
int main(void) {
  Queue *test_q = create_queue(3);
  enqueue(test_q, 1);
  printf("%d\n", dequeue(test_q));

  enqueue(test_q, 1);
  enqueue(test_q, 2);
  printf("%d\n", dequeue(test_q));
  printf("%d\n", dequeue(test_q));

  enqueue(test_q, 1);
  enqueue(test_q, 2);
  enqueue(test_q, 3);
  enqueue(test_q, 4); /*overflow*/

  printf("%d\n", dequeue(test_q));  
  enqueue(test_q, 4);
  enqueue(test_q, 5); /*overflow*/

  printf("%d\n", dequeue(test_q));
  printf("%d\n", dequeue(test_q));
  printf("%d\n", dequeue(test_q));
  printf("%d\n", dequeue(test_q)); /*underflow*/

  enqueue(test_q, 1);
  printf("%d\n", dequeue(test_q));

  enqueue(test_q, 1);
  printf("%d\n", dequeue(test_q)); 

  enqueue(test_q, 1);
  printf("%d\n", dequeue(test_q));
  printf("%d\n", dequeue(test_q));

  enqueue(test_q, 1);
  enqueue(test_q, 2);
  enqueue(test_q, 3);
  display(test_q);
  
  delete_queue(test_q);

  return EXIT_SUCCESS;
}