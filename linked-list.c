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
  return 0;
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
  return 0;
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
int insert_at(s_list *list, int position, long value) {
  /* TO BE COMPLETED BY THE STUDENT. */
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
  return 0;
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
  return NULL;
}
