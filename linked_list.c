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


void 
recursive_reverse(node **head)
{
    node * left, * right;

    if (*head == NULL)
    { return ;}
  
    //left is head, right is assumed to be reversed list 

    left = *head;
    right = left->next;
 
    if (right == NULL)
    {
       return;
    }

    recursive_reverse(&right); 
  
    left->next->next = left;    
    left->next = NULL;
    *head = right;
}

void 
reverse(node **head)
{
    node * temp = *head;
    node * next_temp;
    node * result = NULL;
  
    while (temp) {
        next_temp = temp->next;
        temp->next = result;
        result = temp;
        temp = next_temp;
    }
    *head = result;
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
  
  recursive_reverse(&head);  
  dump_list(head);
}
