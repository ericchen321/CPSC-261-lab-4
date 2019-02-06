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
  print_with_positions(test_list_2);
  free_list(test_list_0); free_list(test_list_1); free_list(test_list_2);
  
  // tests: get_element_at
  initialize_test_lists(&test_list_0, &test_list_1, &test_list_2);
  if(get_element_at(test_list_0, 5) != 5)
    printf("get_element_at(test_list_0,5) failed\n");
  if(get_element_at(test_list_0, 2) != -17)
    printf("get_element_at(test_list_0, 2) failed\n");
  if(get_element_at(test_list_0, 7) != LLONG_MIN)
    printf("get_element_at(test_list_0,9) failed\n");
  if(get_element_at(test_list_0, -1) != LONG_MIN)
    printf("get_element_at(test_list_0, -1) failed\n");
  if(get_element_at(test_list_1, 0) != 99)
    printf("get_element_at(test_list_1, 0) failed\n");
  if(get_element_at(test_list_2, 0) != LONG_MIN)
    printf("get_element_at(test_list_2, 0) failed\n");
  free_list(test_list_0); free_list(test_list_1); free_list(test_list_2);

  // tests: get_sum_of_elements
  initialize_test_lists(&test_list_0, &test_list_1, &test_list_2);
  // case: sum of list 0 (non-empty list)
  if(get_sum_of_elements(test_list_0) == 9){}
  else{
    printf("get sum of list 0 failed\n");
  }
  free_list(test_list_0); free_list(test_list_1); free_list(test_list_2);

  initialize_test_lists(&test_list_0, &test_list_1, &test_list_2);
  // case: sum of list 1 (one-element list)
  if(get_sum_of_elements(test_list_1) == 99){}
  else{
    printf("get sum of list 1 failed\n");
  }
  free_list(test_list_0); free_list(test_list_1); free_list(test_list_2);

  initialize_test_lists(&test_list_0, &test_list_1, &test_list_2);
  // case: sum of empty list
  if(get_sum_of_elements(test_list_2) == 0){}
  else{
    printf("get sum of empty list failed\n");
  }
  free_list(test_list_0); free_list(test_list_1); free_list(test_list_2);

  // tests: insert_at
  initialize_test_lists(&test_list_0, &test_list_1, &test_list_2);
  // case: insert new node at pos 0 in the empty list
  if(insert_at(test_list_2, 0, 33) 
      && get_element_at(test_list_2, 0) == 33
      && test_list_2->num_elements == 1){}
  else{
    printf("insert 33 to empty list failed\n");
  }
  free_list(test_list_0); free_list(test_list_1); free_list(test_list_2);

  initialize_test_lists(&test_list_0, &test_list_1, &test_list_2);
  // case: insert new node at pos 0 in list 0 (non-empty list)
  if(insert_at(test_list_0, 0, 161)
      && get_element_at(test_list_0, 0) == 161
      && get_element_at(test_list_0, 1) == 2
      && get_element_at(test_list_0, 2) == 4
      && get_element_at(test_list_0, 3) == -17
      && get_element_at(test_list_0, 4) == 13
      && get_element_at(test_list_0, 5) == -6
      && get_element_at(test_list_0, 6) == 5
      && get_element_at(test_list_0, 7) == 8
      && test_list_0->num_elements == 8){}
  else{
    printf("insert 161 to list 0 failed\n");
  }
  free_list(test_list_0); free_list(test_list_1); free_list(test_list_2);

  initialize_test_lists(&test_list_0, &test_list_1, &test_list_2);
  // case: add a new node to the end of list 0 (non-empty list)
  if( insert_at(test_list_0, 7, 9999)
      && get_element_at(test_list_0, 0) == 2
      && get_element_at(test_list_0, 1) == 4
      && get_element_at(test_list_0, 2) == -17
      && get_element_at(test_list_0, 3) == 13
      && get_element_at(test_list_0, 4) == -6
      && get_element_at(test_list_0, 5) == 5
      && get_element_at(test_list_0, 6) == 8
      && get_element_at(test_list_0, 7) == 9999
      && test_list_0->num_elements == 8){}
  else
  {
    printf("insert 9999 to end of list 0 failed\n");
  }
  free_list(test_list_0); free_list(test_list_1); free_list(test_list_2);

  initialize_test_lists(&test_list_0, &test_list_1, &test_list_2);
  // case: insert new node at pos 1 in the empty list
  if(!insert_at(test_list_2, 4, 11)
      && test_list_2->num_elements == 0){}
  else{
    printf("empty list overflow insert test failed\n");
  }
  free_list(test_list_0); free_list(test_list_1); free_list(test_list_2);

  initialize_test_lists(&test_list_0, &test_list_1, &test_list_2);
  // case: insert new node at pos 8 in list 0
  if(!insert_at(test_list_0, 8, 444)
      && test_list_0->num_elements == 7
      && get_element_at(test_list_0, 6) == 8){}
  else{
    printf("list 0 overflow insert test failed\n");
  }
  free_list(test_list_0); free_list(test_list_1); free_list(test_list_2);

  initialize_test_lists(&test_list_0, &test_list_1, &test_list_2);
  // case: insert new node at pos -1 in the empty lsit
  if(!insert_at(test_list_2, -1, 222)
    && test_list_2->num_elements == 0){}
  else{
    printf("empty list underflow insert test failed\n");
  }
  free_list(test_list_0); free_list(test_list_1); free_list(test_list_2);

  initialize_test_lists(&test_list_0, &test_list_1, &test_list_2);
  // case: insert new node at pos -1 in list 1
  if(!insert_at(test_list_1, -1, 355)
      && test_list_1->num_elements == 1){}
  else{
    printf("one element underflow insert test failed\n");
  }
  free_list(test_list_0); free_list(test_list_1); free_list(test_list_2);

  initialize_test_lists(&test_list_0, &test_list_1, &test_list_2);
  // case: insert new node at  pos 3 in list 0
  if(insert_at(test_list_0, 3, 555)
      && get_element_at(test_list_0, 0) == 2
      && get_element_at(test_list_0, 1) == 4
      && get_element_at(test_list_0, 2) == -17
      && get_element_at(test_list_0, 3) == 555
      && get_element_at(test_list_0, 4) == 13
      && get_element_at(test_list_0, 5) == -6
      && get_element_at(test_list_0, 6) == 5
      && get_element_at(test_list_0, 7) == 8
      && test_list_0->num_elements == 8){}
  else
  {
    printf("insert 555 to pos 3 in list 0 failed");
  }
  free_list(test_list_0); free_list(test_list_1); free_list(test_list_2);

  initialize_test_lists(&test_list_0, &test_list_1, &test_list_2);
  // case: insert new node at  pos 6 in list 0
  if(insert_at(test_list_0, 6, 3721)
      && get_element_at(test_list_0, 0) == 2
      && get_element_at(test_list_0, 1) == 4
      && get_element_at(test_list_0, 2) == -17
      && get_element_at(test_list_0, 3) == 13
      && get_element_at(test_list_0, 4) == -6
      && get_element_at(test_list_0, 5) == 5
      && get_element_at(test_list_0, 6) == 3721
      && get_element_at(test_list_0, 7) == 8
      && test_list_0->num_elements == 8){}
  else
  {
    printf("insert 3721 to pos 6 in list 0 failed");
  }
  free_list(test_list_0); free_list(test_list_1); free_list(test_list_2);
  
  return 0;
}
