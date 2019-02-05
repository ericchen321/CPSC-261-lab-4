#include <stdio.h>
#include <limits.h>
#include "linked-list.h"

typedef int bool;
#define true 1
#define false 0

#define CONTENTS_0_LENGTH 7
#define CONTENTS_1_LENGTH 1
#define SUM 

int main(int argc, char *argv[]) {
  
  int i;
  long contents_0[CONTENTS_0_LENGTH] = { 8, 5, -6, 13, -17, 4, 2 };
  long contents_1[CONTENTS_1_LENGTH] = {99};
  
  struct s_list *test_list_0 = create_list();
  for (i = 0; i <CONTENTS_0_LENGTH; i++) {
    insert_front(test_list_0, contents_0[i]);
  }

  struct s_list *test_list_1 = create_list();
  for (i = 0; i <CONTENTS_1_LENGTH; i++) {
    insert_front(test_list_1, contents_1[i]);
  }
  
  struct s_list *test_list_2 = create_list();

  // tests: print_with_positions
  print_with_positions(test_list_0);
  print_with_positions(test_list_1);
  
  // tests: get_element_at
  if(get_element_at(test_list_0, 5) != 5)
    printf("get_element_at(test_list_0,5) failed");
  if(get_element_at(test_list_0, 2) != -17)
    printf("get_element_at(test_list_0, 2) failed");
  if(get_element_at(test_list_0, 7) != LLONG_MIN)
    printf("get_element_at(test_list_0,9) failed");
  if(get_element_at(test_list_0, -1) != LONG_MIN)
    printf("get_element_at(test_list_0, -1) failed");
  if(get_element_at(test_list_1, 0) != 99)
    printf("get_element_at(test_list_1, 0) failed");
  if(get_element_at(test_list_2, 0) != LONG_MIN)
    printf("get_element_at(test_list_2, 0) failed");
    
  free_list(test_list_0);
  return 0;
}
