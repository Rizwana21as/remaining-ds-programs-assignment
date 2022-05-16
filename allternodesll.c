#include<stdio.h>
#include<stdlib.h>

//Structure of node 
struct Node
{
    int data;
    struct Node *next;
};

//display the nodes
void display(struct Node* node)
{

    //as linked list will end when Node is Null
    while(node!=NULL)
    {
        printf("%d ",node->data);
        node = node->next;
    }
    printf("\n");
}

void insert(struct Node** head, int data)
{

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = *head;

    //changing the new head to this freshly entered node
    *head = newNode;
}

// function to delete alternate nodes
void delete_Alt(struct Node *head)  
{
    if (head == NULL)
        return;
  
    // prev req so its next node can be changed
    struct Node *prev = head;
    struct Node *curr = head->next;
  
    while (prev != NULL && curr != NULL)
    {
        // changing next of previous node
        prev->next = curr->next;
  
        // free the memory
        free(curr);
  
        // Update prev and curr 
        prev = prev->next;
        if (prev != NULL)
            curr = prev->next;
    }
}
int main()
{
    struct Node *head = NULL;
    
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    
    printf("Before deletion: ");
    display(head);
    
    delete_Alt(head);
    
    printf("After deletion: ");
    display(head);
    return 0;
}


