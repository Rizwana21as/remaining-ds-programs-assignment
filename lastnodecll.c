#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
   
//Represents the node of list.  
struct node
{  
    int data;  
    struct node *next;  
};  
   
//Declaring head and tail pointer as null.  
struct node *head = NULL;  
struct node *tail = NULL;  
   
//This function will add the new node at the end of the list.  
void add(int data)
{  
    //Create new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    //Checks if the list is empty.  
    if(head == NULL)
    {  
        //If list is empty, both head and tail would point to new node.  
        head = newNode;  
        tail = newNode;  
        newNode->next = head;  
    }else 
    {  
        //tail will point to new node.  
        tail->next = newNode;  
        //New node will become new tail.  
        tail = newNode;  
        //Since, it is circular linked list tail will point to head.  
        tail->next = head;  
    }  
}  
   
//Deletes node from end of the list  
void deleteEnd() 
{  
    //Checks whether list is empty  
    if(head == NULL)
    {  
        return;  
    }  
    else 
    {  
        //Checks whether contain only one element  
        if(head != tail )
        {  
            struct node *current = head;  
            //Loop will iterate till the second last element as current.next is pointing to tail  
            while(current->next != tail)
            {  
                current = current->next;  
            }  
            //Second last element will be new tail  
            tail = current;  
            //Tail will point to head as it is a circular linked list  
            tail->next = head;  
        }  
        //If the list contains only one element   
        //Then it will remove it and both head and tail will point to null  
        else 
        {  
            head = tail = NULL;  
        }  
    }  
}  
      
//This function will display the nodes of circular linked list  
void display(){  
    struct node *current = head;  
    if(head == NULL)
    {  
        printf("List is empty");  
    }  
    else
    {  
         do
         {  
             //Prints each node by incrementing pointer.  
            printf("%d ", current->data);  
            current = current->next;  
        }
        while(current != head);  
        printf("\n");  
    }  
}  
      
int main()  
{  
   //Adds data to the list  
   add(1);  
   add(2);  
   add(3);  
   add(4);  
   //Printing original list  
   printf("Original List:\n ");  
   display();  
   while(head != NULL)
   {  
        deleteEnd();  
        //Printing updated list  
        printf("Updated List:\n ");  
        display();  
    }  
     
   return 0;  
}  


