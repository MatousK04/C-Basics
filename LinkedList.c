#include <stdio.h>
#include <stdlib.h>

typedef struct Nodes NODE;

struct Nodes 
{
    int value;
    NODE *next;
};
NODE * createNode(int value);
void append(NODE **head, int value);
void displayList(NODE *head);
int main()
{
    NODE *head = NULL;
    int choice = 1;
    int newNum = 0;
    while(choice != 0)
    {
        printf("\nEnter any number to add a value to the list:\n");
        printf("Enter 2 to display the list :\n");
        printf("Enter 0 to exit:\n");
        scanf("%d",&choice);
        if(choice == 2)
        {
            displayList(head);
        }
        if(choice == 0)
        {
            break;
        }
        if(choice != 0 && choice != 2)
        {
            printf("What number? :");
            scanf("%d",&newNum);
            append(&head,newNum);
        }
    }
    return 0;
}
NODE * createNode(int value)
{
    NODE * newNode = (NODE *)malloc(sizeof(NODE));
    if(newNode == NULL)
    {
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
void append(NODE **head,int value)
{
    NODE *newNode = createNode(value);
    NODE *temp = *head;
    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next; 
        }
        temp->next = newNode;
    }
}
void displayList(NODE *head)
{
    NODE *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ",temp->value);
        temp = temp->next;
    }
}