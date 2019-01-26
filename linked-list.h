#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

/*
 * Declarations.
 */
typedef struct s_node {
  long value;
  struct s_node *next;
} s_node;

typedef struct s_list {
  long num_elements;
  struct s_node *first;
} s_list;

/*
 * Function prototypes for the functions we provide.
 */
extern s_list *create_list(void);
extern void print(s_list *list);
extern void insert_front(s_list *list, long value);

/*
 * Function prototypes for the functions you need to write.
 */
extern void print_with_positions(s_list *list);
extern long get_element_at(s_list *list, int position);
extern long get_sum_of_elements(s_list *list);
extern void free_list(s_list *list);
extern int insert_at(s_list *list, int position, long value);
extern int insert_list_at(s_list *list, int position, s_list *other_list);
extern s_list *extract_sublist(s_list *list, int position, int nb_of_elements);


#endif
