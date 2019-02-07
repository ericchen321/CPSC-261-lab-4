#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "linked-list.h"

/*
 * Function to create a new list.
 *
 * Parameters:
 *     none
 * Returns:
 *     a pointer to the new list.
 */
s_list *create_list() {

  s_list *list = malloc(sizeof(s_list));
  list->num_elements = 0;
  list->first = NULL;
  
  return list;
}

/*
 * Function to print every element of the list.
 * 
 * Parameters:
 *     a pointer to the list struct.
 * Returns:
 *     nothing, but prints out the list elements, one per line.
 */
void print(s_list *list) {
  
  s_node *node = list->first;
  while (node != NULL) {
    printf("Element: %ld\n", node->value);
    node = node->next;
  }
}

/*
 * Function to insert an element at the front in the list.
 *
 * Parameters:
 *     a pointer to the list struct.
 *     the new value to insert.
 *
 * Returns:
 *     nothing, but inserts the element at the front of the list.
 */
void insert_front(s_list *list, long value) {
  
  s_node *new_node = malloc(sizeof(s_node));
  new_node->next = list->first;
  new_node->value = value;
  list->first = new_node;
  list->num_elements++;
}

/*
 * Function to print every element of the list, with positions.
 *
 * Parameters:
 *     a pointer to the list struct.
 * Returns:
 *     nothing, but prints out the list elements with their positions, one per line.
 */
void print_with_positions(s_list *list) {
  /* TO BE COMPLETED BY THE STUDENT. */
  int position = 0;
  s_node *next_Node = list -> first;

  while(next_Node!=NULL){
    printf("Element: %ld, position: %d\n",(long)next_Node->value,position);
    next_Node=next_Node->next;
    position++;
  }

}

/*
 * Function to retrieve the element at the position specified.
 *
 * Parameters:
 *     a pointer to the list struct.
 *     the position of the element to retrieve.
 *
 * Returns:
 *     the value of the element at the given position in the list,
 *     or the constant LLONG_MIN if the position is out of range.
 */
long get_element_at(s_list *list, int position) {
  /* TO BE COMPLETED BY THE STUDENT. */
  int currPos = 0;
  long value=LLONG_MIN;
  s_node *next_Node = list -> first;

  while(next_Node!=NULL){
    if(currPos == position){
        value=next_Node->value;
        break;
      }
    next_Node=next_Node->next;
    currPos++;
  }

  return value;
}

/*
 * Function to retrieve the sum of all the elements in the list.
 *
 * Parameters:
 *     a pointer to the list struct.
 *
 * Returns:
 *     the sum of the values of all the element in the list,
 *     or 0 (zero) if the list is empty.
 */
long get_sum_of_elements(s_list *list) {
  /* TO BE COMPLETED BY THE STUDENT. */
  long sum = 0;
  s_node *next_Node = list -> first;

  while(next_Node!=NULL){
    sum+=next_Node->value;
    next_Node=next_Node->next;
  }

  return sum;
}

/* 
 * effects: free all nodes starting from given node
 */
void free_nodes(s_node *s_node){
  if(s_node == NULL){
    return;
  }
  free_nodes(s_node->next);
  free(s_node);
}

/*
 * Function to delete a list and free all of its nodes (including the node struct).
 *
 * Parameters:
 *     a pointer to the list struct.
 * Returns:
 *     nothing.
 */
void free_list(s_list *list) {
  /* TO BE COMPLETED BY THE STUDENT. */
  free_nodes(list->first);
  free(list);
}

/*
 * Function to insert a new element at given position.
 *
 * Parameters:
 *     a pointer to the list struct.
 *     the position the new element should occupy (0 for inserting at front).
 *     the value of the new element.
 * Returns
 *     1 if successful, 0 if the position is out of range.
 */
/*int insert_at(s_list *list, int position, long value) {

  if(position<0 
      || (list->num_elements == 0 && position != 0)
      || (list->num_elements > 0 && position>list->num_elements)){
    return 0;
  }

  if(position==0){
    s_node* new_node = malloc(sizeof(s_node));
    new_node->value = value;
    new_node->next = list->first;
    list->first = new_node;
    list->num_elements += 1;
    return 1;
  }
  else{
    int i = 0;
    s_node* cursor = list->first;
    while(cursor!=NULL && i<position-1){
      cursor = cursor->next;
      i+=1;
    }
    s_node* new_node = malloc(sizeof(s_node));
    new_node->value = value;
    new_node->next = cursor->next;
    cursor->next = new_node;
    list->num_elements += 1;
    return 1;
  }
}
*/

/*
 * Function to insert a new element at given position.
 *
 * Parameters:
 *     a pointer to the list struct.
 *     the position the new element should occupy (0 for inserting at front).
 *     the value of the new element.
 * Returns
 *     1 if successful, 0 if the position is out of range.
 */
int insert_at(s_list *list, int position, long value) {
  if(position == 0){
    insert_front(list,value);
    return 1;
  }
  else if(position<=list->num_elements && position >0){
    s_node* prev = list->first;
    int currPos = 0; 
    while(prev!=NULL){
    if(currPos == position-1){
        break;
      }
    prev = prev->next;
    currPos++; 
  }
  s_node *curr = malloc(sizeof(s_node));
  curr->next = prev->next;
  curr->value = value;
  prev->next = curr;
  list->num_elements++;
  return 1;
  }
  return 0;
}
 

/*
 * Function to insert a list inside another list. The list being inserted
 * becomes part of the other list, and its list struct is free()'d.
 *
 * Parameters:
 *     a pointer to the list struct of the target list.
 *     the position of the first element of the inserted list should occupy.
 *     a pointer to the list struct to insert.
 * Returns
 *     1 if successful, 0 if the position is invalid.
 */
int insert_list_at(s_list *list, int position, s_list *other_list) {
  /* TO BE COMPLETED BY THE STUDENT. */

  // case: invalid pos
  if(position<0
      || (position!=0 && list->num_elements==0)
      || (position>list->num_elements && list->num_elements>0)){
      return 0;
  }

  // case: other_list is empty
  if(other_list->num_elements == 0){
    free_list(other_list);
    return 1;
  }

  // case: other list is non-empty and this list is empty
  if(list->num_elements == 0){
    list->first = other_list->first;
    list->num_elements = other_list->num_elements;
    free(other_list);
    return 1;
  }

  // for cases below, pos is valid, either list has >=1 elements
  if (position == 0){
    s_node* temp = list->first;
    list->first = other_list->first;
    s_node* target_cursor = list->first;
    while(target_cursor->next != NULL){
      target_cursor = target_cursor->next;
    }
    target_cursor->next = temp;
  }
  else{
    int i;
    s_node* target_cursor = list->first;
    s_node* temp;
    for(i=0; i<position-1; i++){
      target_cursor = target_cursor->next;
    }
    temp = target_cursor->next;
    target_cursor->next = other_list->first;
    while(target_cursor->next != NULL){
      target_cursor = target_cursor->next;
    }
    target_cursor->next = temp;
  }
  list->num_elements = list->num_elements + other_list->num_elements;
  free(other_list);
  
  return 1;
}

/*
 * Function to extract a sublist located inside another list. The extracted
 * list is no longer part of the other list, and gets its own list node.
 *
 * Parameters:
 *     a pointer to the list node of the target list.
 *     the position of the first element of the list to extract.
 *     the number of elements to extract.
 *     
 * Returns
 *     the list struct of the sublist if successful, NULL if the position or
 *     number of elements to extract are invalid. In the latter case the original
 *     list is unmodified.
 */
s_list *extract_sublist(s_list *list, int position, int nb_of_elements) {
  /* TO BE COMPLETED BY THE STUDENT. */
  if(position<0
      || (list->num_elements==0 && position!=0)
      || nb_of_elements<0
      || (list->num_elements==0 && nb_of_elements!=0)
      || (position+nb_of_elements > list->num_elements)){
    return NULL;
  }

  // for cases below, pos is valid
  // case: extract no elements
  if(nb_of_elements == 0){
    return create_list();
  }

  // case: extract >= 1 elements; list has >= 1 elements
  int i;
  s_list *sublist = create_list();
  if(position==0){
    sublist->first = list->first;
    s_node *sub_cursor=sublist->first;
    for(i=0; i<nb_of_elements-1; i++){
      sub_cursor = sub_cursor->next;
    }
    list->first = sub_cursor->next;
    sub_cursor->next = NULL;
  }
  else{
    s_node *list_cursor = list->first;
    s_node *sub_cursor;
    for(i=0; i<position-1; i++){
      list_cursor = list_cursor->next;
    }
    sublist->first = list_cursor->next;
    sub_cursor = sublist->first;
    for(i=0; i<nb_of_elements-1; i++){
      sub_cursor = sub_cursor->next;
    }
    list_cursor->next = sub_cursor->next;
    sub_cursor->next = NULL;
  }
  sublist->num_elements = nb_of_elements;
  list->num_elements = list->num_elements - nb_of_elements;
  return sublist;
}
