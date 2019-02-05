#include <stdio.h>
#include <limits.h>
#include "linked-list.h"

typedef int bool;
#define true 1
#define false 0

#define CONTENTS_0_LENGTH 7
#define CONTENTS_1_LENGTH 1
#define SUM 

/*
 * effects: initialize 3 test lists:
 *          list_0: 2 4 -17 13 -6 5 8
 *          list_1: 99
 *          list_2: empty
 */
void initialize_test_lists(s_list **list_0, s_list **list_1, s_list **list_2){
  int i;
  long contents_0[CONTENTS_0_LENGTH] = { 8, 5, -6, 13, -17, 4, 2 };
  long contents_1[CONTENTS_1_LENGTH] = {99};
  
  *list_0 = create_list();
  for (i = 0; i <CONTENTS_0_LENGTH; i++) {
    insert_front(*list_0, contents_0[i]);
  }

  *list_1 = create_list();
  for (i = 0; i <CONTENTS_1_LENGTH; i++) {
    insert_front(*list_1, contents_1[i]);
  }
  
  *list_2 = create_list();
}

int main(int argc, char *argv[]) {
  struct s_list* test_list_0;
  struct s_list* test_list_1;
  struct s_list* test_list_2;    

  // tests: print_with_positions
  initialize_test_lists(&test_list_0, &test_list_1, &test_list_2);
  print_with_positions(test_list_0);
  print_with_positions(test_list_1);
  free_list(test_list_0);
  free_list(test_list_1);
  free_list(test_list_2);
  
  // tests: get_element_at
  initialize_test_lists(&test_list_0, &test_list_1, &test_list_2);
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
  free_list(test_list_1);
  free_list(test_list_2);

  // tests: insert_at

  
  return 0;
}
