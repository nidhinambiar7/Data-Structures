#include<stdio.h>
#include<stdlib.h>

struct Node{
     int data;
     struct Node* next;
};

struct Node* CreateNode(int data)
{
  struct Node* newnode= (struct Node*)malloc(sizeof(struct Node));
  newnode->data=data;
  newnode->next=NULL;

  return newnode;
}

void InsertAtFront(struct Node** head, int data)
{
  struct Node* newnode= CreateNode(data);
  newnode->next=*head;
  *head=newnode;
  return;
}

void print(struct Node* head)
{
  struct Node* temp=head;
  while(temp!=NULL)
    {
      printf("%d->", temp->data);
      temp=temp->next;
    }
  printf("NULL\n");
}

void DeleteFromFirst(struct Node** head)
{
  if(*head==NULL)
  {
    printf("Linked list is empty.");
    return;
  }
  struct Node* temp=*head;
  *head=temp->next;
  free(temp);
}

void DeleteFromEnd(struct Node** head)
{
  if(*head==NULL)
  {
    printf("Linked List is empty");
    return;
  }
  struct Node* temp=*head;
  if(temp->next==NULL)
  {
    free(temp);
    *head=NULL;
    return;
  }
  while(temp->next->next!=NULL)
    {
      temp=temp->next;
    }
  free(temp->next);
  temp->next=NULL;
}

void DeleteFromPosition(struct Node** head, int position)
{
  if(*head==NULL)
  {
    printf("Linked list is empty");
    return;
  }
  struct Node* temp=*head;
  if(position==0)
  {
    DeleteFromFirst(head);
    return;
  }
  for(int i=0; temp!=NULL && i<position-1; i++)
    {
      temp=temp->next;
    }
  if(temp==NULL||temp->next==NULL)
  {
    printf("Position out of bound");
    return;
  }
  struct Node* next=temp->next->next;
  free(temp->next);
  temp->next=next;

}

int main()
{
  struct Node* head=NULL;
  int choice, value, position;
  do
    {
      printf("Menu\n");
      printf("1. Insert\n");
      printf("2. Delete at first\n");
      printf("3. Delete at end\n");
      printf("4. Delete at position\n");
      printf("5. Exit\n");

      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch(choice)
        {
          case 1:
              printf("Enter the value to insert: ");
              scanf("%d", &value);
              InsertAtFront(&head, value);
              print(head);
              break;
          case 2:
             DeleteFromFirst(&head);
             print(head);
             break;
          case 3:
             DeleteFromEnd(&head);
             print(head);
             break;
          case 4:
             printf("Enter the position to delete: ");
             scanf("%d", &position);
             DeleteFromPosition(&head, position);
             print(head);
             break;

          case 5:
             printf("Exiting the program.\n");
             break;

          default:
             printf("Invalid choice. Please try again.\n");
             break;
        }
    }while(choice!=5);
return 0;
}
