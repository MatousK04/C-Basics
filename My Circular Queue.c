#include <stdio.h>
#include <stdlib.h>

struct CircQ 
{
   int value;
   struct CircQ *next;
};
typedef struct CircQ CQ;

void enqueue(CQ **head, int value);
void dequeue(CQ **head);
void printQ(CQ *head);
void menu(CQ **head);

int main()
{
   CQ *head = NULL;
   menu(&head);
   return 0;
}
void enqueue(CQ **head, int value)
{
   CQ *newBit = malloc(sizeof(CQ));
   CQ *temp = *head;
   if(newBit == NULL)
   {
      return;
   }
   newBit->value = value;
   newBit->next = NULL;
   if(*head == NULL)
   {
      *head = newBit;
      newBit->next = *head;
   }
   else
   {
      while(temp->next != *head)
      {
         temp = temp->next;
      }
      temp->next = newBit;
      newBit->next = *head;
   }
}
void dequeue(CQ **head)
{
   CQ *delete = *head;
   if(*head == NULL)
   {
      printf("Nothing to delete");
      return;
   }
   if((*head)->next == *head)
   {
      *head = NULL;
   }
   else
   {
      (*head) = (*head)->next;
      CQ *temp = *head;
      while(temp->next != delete)
      {
         temp = temp->next;
      }
      temp->next = *head;
   }
   free(delete);
}
void printQ(CQ *head)
{
   CQ *temp = head;
   if(head == NULL)
   {
      printf(" This Array is Empty");
      return;
   }
   do
   {
      printf(" %d - ",temp->value);
      temp = temp->next;
   }
   while(temp != head);
}
void menu(CQ **head)
{
   int choice = 0;
   int value;
   while(choice != 3)
   {
      printf("\nEnter 1 to enqueue \n");
      printf("Enter 2 to dequeue \n");
      printf("Enter 3 to end \n");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1:
         {
            printf("What do you wish to enqueue?\n");
            scanf("%d",&value);
            enqueue(head,value);
            printQ(*head);
            break;
         }
         case 2:
         {
            dequeue(head);
            printQ(*head);
            break;
         }
         case 3:
         {
            printf("DONE!\n");
            break;
         }
      }
      if(choice > 3 || choice < 1)
      {
         printf("Try again!\n");
      }
   }
}