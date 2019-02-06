#include <stdio.h>
#include <limits.h>
#include "linked-list.h"

typedef int bool;
#define true 1
#define false 0

#define CONTENTS_0_LENGTH 7
#define CONTENTS_1_LENGTH 1
#define CONTENTS_3_LENGTH 1
#define CONTENTS_5_LENGTH 3
#define SUM 

/*
 * effects: initialize 3 test lists:
 *          list_0: 2 4 -17 13 -6 5 8
 *          list_1: 99
 *          list_2: empty
 *          list_3: 88
 *          list_4: empty
 *          list_5: 33 500 -52
 */
void initialize_lists(s_list **list_0, s_list **list_1, s_list **list_2, s_list **list_3, s_list **list_4, s_list **list_5){
  int i;
  long contents_0[CONTENTS_0_LENGTH] = { 8, 5, -6, 13, -17, 4, 2 };
  long contents_1[CONTENTS_1_LENGTH] = {99};
  long contents_3[CONTENTS_3_LENGTH] = {88};
  long contents_5[CONTENTS_5_LENGTH] = {-52, 500, 33};
  
  *list_0 = create_list();
  for (i = 0; i <CONTENTS_0_LENGTH; i++) {
    insert_front(*list_0, contents_0[i]);
  }

  *list_1 = create_list();
  for (i = 0; i <CONTENTS_1_LENGTH; i++) {
    insert_front(*list_1, contents_1[i]);
  }
  
  *list_2 = create_list();

  *list_3 = create_list();
  for (i = 0; i <CONTENTS_3_LENGTH; i++) {
    insert_front(*list_3, contents_3[i]);
  }

  *list_4 = create_list();

  *list_5 = create_list();
  for (i = 0; i <CONTENTS_5_LENGTH; i++) {
    insert_front(*list_5, contents_5[i]);
  }
}

int main(int argc, char *argv[]) {
  struct s_list* list_0;
  struct s_list* list_1;
  struct s_list* list_2;
  struct s_list* list_3;
  struct s_list* list_4;
  struct s_list* list_5;    

  // tests: print_with_positions
  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  print_with_positions(list_0);
  print_with_positions(list_1);
  print_with_positions(list_2);
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);
  
  // tests: get_element_at
  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  if(get_element_at(list_0, 5) != 5)
    printf("get_element_at(list_0,5) failed\n");
  if(get_element_at(list_0, 2) != -17)
    printf("get_element_at(list_0, 2) failed\n");
  if(get_element_at(list_0, 7) != LLONG_MIN)
    printf("get_element_at(list_0,9) failed\n");
  if(get_element_at(list_0, -1) != LONG_MIN)
    printf("get_element_at(list_0, -1) failed\n");
  if(get_element_at(list_1, 0) != 99)
    printf("get_element_at(list_1, 0) failed\n");
  if(get_element_at(list_2, 0) != LONG_MIN)
    printf("get_element_at(list_2, 0) failed\n");
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);

  // tests: get_sum_of_elements
  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: sum of list 0 (non-empty list)
  if(get_sum_of_elements(list_0) == 9){}
  else{
    printf("get sum of list 0 failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: sum of list 1 (one-element list)
  if(get_sum_of_elements(list_1) == 99){}
  else{
    printf("get sum of list 1 failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: sum of empty list
  if(get_sum_of_elements(list_2) == 0){}
  else{
    printf("get sum of empty list failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);

  // tests: insert_at
  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: insert new node at pos 0 in the empty list
  if(insert_at(list_2, 0, 33) 
      && get_element_at(list_2, 0) == 33
      && list_2->num_elements == 1){}
  else{
    printf("insert 33 to empty list failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: insert new node at pos 0 in list 0 (non-empty list)
  if(insert_at(list_0, 0, 161)
      && get_element_at(list_0, 0) == 161
      && get_element_at(list_0, 1) == 2
      && get_element_at(list_0, 2) == 4
      && get_element_at(list_0, 3) == -17
      && get_element_at(list_0, 4) == 13
      && get_element_at(list_0, 5) == -6
      && get_element_at(list_0, 6) == 5
      && get_element_at(list_0, 7) == 8
      && list_0->num_elements == 8){}
  else{
    printf("insert 161 to list 0 failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: add a new node to the end of list 0 (non-empty list)
  if( insert_at(list_0, 7, 9999)
      && get_element_at(list_0, 0) == 2
      && get_element_at(list_0, 1) == 4
      && get_element_at(list_0, 2) == -17
      && get_element_at(list_0, 3) == 13
      && get_element_at(list_0, 4) == -6
      && get_element_at(list_0, 5) == 5
      && get_element_at(list_0, 6) == 8
      && get_element_at(list_0, 7) == 9999
      && list_0->num_elements == 8){}
  else
  {
    printf("insert 9999 to end of list 0 failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: insert new node at pos 1 in the empty list
  if(!insert_at(list_2, 4, 11)
      && list_2->num_elements == 0){}
  else{
    printf("empty list overflow insert test failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: insert new node at pos 8 in list 0
  if(!insert_at(list_0, 8, 444)
      && list_0->num_elements == 7
      && get_element_at(list_0, 6) == 8){}
  else{
    printf("list 0 overflow insert test failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: insert new node at pos -1 in the empty lsit
  if(!insert_at(list_2, -1, 222)
    && list_2->num_elements == 0){}
  else{
    printf("empty list underflow insert test failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: insert new node at pos -1 in list 1
  if(!insert_at(list_1, -1, 355)
      && list_1->num_elements == 1){}
  else{
    printf("one element underflow insert test failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: insert new node at  pos 3 in list 0
  if(insert_at(list_0, 3, 555)
      && get_element_at(list_0, 0) == 2
      && get_element_at(list_0, 1) == 4
      && get_element_at(list_0, 2) == -17
      && get_element_at(list_0, 3) == 555
      && get_element_at(list_0, 4) == 13
      && get_element_at(list_0, 5) == -6
      && get_element_at(list_0, 6) == 5
      && get_element_at(list_0, 7) == 8
      && list_0->num_elements == 8){}
  else
  {
    printf("insert 555 to pos 3 in list 0 failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: insert new node at  pos 6 in list 0
  if(insert_at(list_0, 6, 3721)
      && get_element_at(list_0, 0) == 2
      && get_element_at(list_0, 1) == 4
      && get_element_at(list_0, 2) == -17
      && get_element_at(list_0, 3) == 13
      && get_element_at(list_0, 4) == -6
      && get_element_at(list_0, 5) == 5
      && get_element_at(list_0, 6) == 3721
      && get_element_at(list_0, 7) == 8
      && list_0->num_elements == 8){}
  else
  {
    printf("insert 3721 to pos 6 in list 0 failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);

  // tests: insert_list_at
  int insert_success;
  // TODO: need to test inserting empty list to empty list

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: valid pos, insert empty list to non-empty list
  insert_success = insert_list_at(list_5, 0, list_2);
  if(insert_success
      && list_5->num_elements == 3
      && get_element_at(list_5, 0) == 33
      && get_element_at(list_5, 1) == 500
      && get_element_at(list_5, 2) == -52){}
  else{
    printf("insert empty list to non-empty list failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_3); free_list(list_4); free_list(list_5);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: valid pos, insert non-empty list to start of empty target list
  insert_success = insert_list_at(list_2, 0, list_5);
  if(insert_success
      && list_2->num_elements == 3
      && get_element_at(list_2, 0) == 33
      && get_element_at(list_2, 1) == 500
      && get_element_at(list_2, 2) == -52){}
  else{
    printf("insert non-empty list to start of empty target list failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: valid pos, insert one element list to front of one element list
  insert_success = insert_list_at(list_1, 0, list_3);
  if(insert_success
      && list_1->num_elements == 2
      && get_element_at(list_1, 0) == 88
      && get_element_at(list_1, 1) == 99){}
  else{
    printf("insert list 3 to front of list 1 failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_4); free_list(list_5);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: valid pos, insert one element list to end of one element list
  insert_success = insert_list_at(list_1, 1, list_3);
  if(insert_success
      && list_1->num_elements == 2
      && get_element_at(list_1, 0) == 99
      && get_element_at(list_1, 1) == 88){}
  else{
    printf("insert list 3 to end of list 1 failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_4); free_list(list_5);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: valid pos, insert multi-element list to middle of multi-element list
  insert_success = insert_list_at(list_0, 2, list_5);
  if(insert_success
      && list_0->num_elements == 10
      && get_element_at(list_0, 0) == 2
      && get_element_at(list_0, 1) == 4
      && get_element_at(list_0, 2) == 33
      && get_element_at(list_0, 3) == 500
      && get_element_at(list_0, 4) == -52
      && get_element_at(list_0, 5) == -17
      && get_element_at(list_0, 6) == 13
      && get_element_at(list_0, 7) == -6
      && get_element_at(list_0, 8) == 5
      && get_element_at(list_0, 9) == 8){}
  else{
    printf("insert list 5 to pos 2 of list 0 failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: valid pos, insert multi-element list to end of multi-element list
  insert_success = insert_list_at(list_0, 7, list_5);
  if(insert_success
      && list_0->num_elements == 10
      && get_element_at(list_0, 0) == 2
      && get_element_at(list_0, 1) == 4
      && get_element_at(list_0, 2) == -17
      && get_element_at(list_0, 3) == 13
      && get_element_at(list_0, 4) == -6
      && get_element_at(list_0, 5) == 5
      && get_element_at(list_0, 6) == 8
      && get_element_at(list_0, 7) == 33
      && get_element_at(list_0, 8) == 500
      && get_element_at(list_0, 9) == -52){}
  else{
    printf("insert list 5 to end of list 0 failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: invalid pos, position < 0 FIXME: now assuming other list untouched for invalid pos
  insert_success = insert_list_at(list_0, -1, list_5);
  if(!insert_success
      && list_0->num_elements == 7
      && list_5->num_elements == 3){}
  else{
    printf("insert list position < 0 test failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: invalid pos, position != 0 when target list is empty
  insert_success = insert_list_at(list_2, 1, list_5);
  if(!insert_success
      && list_2->num_elements == 0
      && list_5->num_elements == 3){}
  else
  {
    printf("insert list position != 0 when target list is empty test failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);

  initialize_lists(&list_0, &list_1, &list_2, &list_3, &list_4, &list_5);
  // case: invalid pos, position > num_of_elements when target list is non-empty
  insert_success = insert_list_at(list_0, 8, list_1);
  if(!insert_success
      && list_0->num_elements == 7
      && list_1->num_elements == 1){}
  else{
    printf("insert list position overflow test failed\n");
  }
  free_list(list_0); free_list(list_1); free_list(list_2); free_list(list_3); free_list(list_4); free_list(list_5);
  
  return 0;
}
