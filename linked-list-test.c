#include <stdio.h>
#include "linked-list.h"

#define INITIAL_LENGTH 7

int main(int argc, char *argv[]) {
  
  long contents[INITIAL_LENGTH] = { 8, 5, -6, 13, -17, 4, 2 };
  int i;
  
  struct s_list *mylist = create_list();
  for (i = 0; i < INITIAL_LENGTH; i++) {
    insert_front(mylist, contents[i]);
  }
  
  print(mylist);
  print_with_positions(mylist);
  long first = get_element_at(mylist,6);
  long second = get_element_at(mylist,5);
  printf("%ld\n",first);
  printf("%ld\n",second);
  free_list(mylist);
  
  return 0;
}
