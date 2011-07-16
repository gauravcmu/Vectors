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
    printf("\n------\n");
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

void
sorted_insert( node **head, int value)
{
    node * new_node;
    node * temp = *head;
    if ((*head == NULL) || ((*head)->value > value))
    {
       new_node = malloc(sizeof(node)); 
       new_node->value = value;
       new_node->next = *head;
       *head = new_node;
       return;
    }

    while((temp->next) && ((temp->next)->value < value)) {
        temp = temp->next;
    }

    new_node = malloc(sizeof(node)); 
    new_node->value = value;
    new_node->next = temp->next;   
    temp->next = new_node;
}

void
splitList(node * head, node **head2)
{
    node * fast = NULL;
    node  *slow = NULL;

    if ((head == NULL) || (head->next == NULL))
    {
        *head2 = NULL;
        return;
    }

    slow = head;
    fast = head->next; 

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
   
    *head2 = slow->next;
    slow->next = NULL;
}

void
remove_duplicates_from_sorted_list(node * head)
{
   node *temp = head;
   node * save = NULL;
 
   if (temp == NULL) {
       return; 
   }

   while ((temp->next)) {
       if(temp->next->value == temp->value) {
           save = temp->next;
           temp->next = temp->next->next; 
           free(save);
       }
       temp = temp->next;
   }
}

//move first node from list head2 and prepend to head.
void
MoveNode(node ** head, node ** head2)
{
    node * save = NULL;
    if ((*head == NULL) || (*head2 == NULL)) return;
   
    save = *head2;
    *head2 = save->next;   
    save->next = *head;
    *head = save; 
}

int main()
{
  node * head = NULL;
  node * head2 = NULL;
#if 0
  list_add_front(&head, 3); 
  list_add_front(&head, 4); 
  list_add_front(&head, 5); 
  list_add_front(&head, 6); 
  list_add_front(&head, 7); 
#endif

  list_add_front(&head, 3); 
  list_add_front(&head, 4); 
  list_add_front(&head, 5); 

  sorted_insert(&head2, 2);
  sorted_insert(&head2, 7);
  sorted_insert(&head2, 8);
  sorted_insert(&head2, 9);
  dump_list(head);
  dump_list(head2);
  
  MoveNode(&head, &head2); 
  dump_list(head);
  dump_list(head2);
#if 0  
  remove_duplicates_from_sorted_list(head);
  dump_list(head);
#endif  

#if 0  
  splitList(head, &head2); 
  dump_list(head);
  dump_list(head2);
#endif  
  
//  recursive_reverse(&head);  
 // dump_list(head);
}
