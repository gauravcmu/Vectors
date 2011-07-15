#include <stdio.h>


typedef struct node_ {
   int value;
   struct node_ * next;
} node;

list_add_front(node ** head, int value)
{
   node * new_node =NULL;

    if (*head == NULL) { 
        new_node = (node *)malloc(sizeof(node)); 
        new_node->value = value;
        new_node->next = NULL;
        *head = new_node;
        return;
    }
    new_node = malloc(sizeof(node)); 
    new_node->value = value;
    new_node->next = *head; 
    *head = new_node;
}

dump_list(node * head)
{
    node * node_tmp = head;
    while(node_tmp) {
        printf("\n [%d]", node_tmp->value);
        node_tmp = node_tmp->next;
    }
}

int main()
{
  node * head = NULL;
  list_add_front(&head, 3); 
  list_add_front(&head, 4); 
  list_add_front(&head, 5); 
  list_add_front(&head, 6); 
  list_add_front(&head, 7); 
  dump_list(head);
}
