#include <stdio.h>
#include "linked-list.h"

typedef int bool;
#define true 1
#define false 0

#define INITIAL_LENGTH 7
#define SUM 

int main(int argc, char *argv[]) {
  
  long contents[INITIAL_LENGTH] = { 8, 5, -6, 13, -17, 4, 2 };
  int i;
  
  struct s_list *mylist = create_list();
  for (i = 0; i < INITIAL_LENGTH; i++) {
    insert_front(mylist, contents[i]);
  }
  
  insert_at(mylist,1,6);
  //print(mylist); 
   print_with_positions(mylist);
  long first = get_element_at(mylist,6);
  long second = get_element_at(mylist,5);
  printf("This is not a valid position: %ld\n",first);
  printf("Element at this pos is: %ld\n",second);
  


  printf("the Sum is: %ld\n",get_sum_of_elements(mylist));
  
  free_list(mylist);
  return 0;
}
