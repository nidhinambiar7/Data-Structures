#include<stdio.h>
#include<stdlib.h>

struct Node{
      int data;
       struct Node* next;
};

struct Node* CreateNode(int data)
{
  struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
  newnode->data=data;
  newnode->next=NULL;
  return newnode;
}

void InsertAtFirst(struct Node** head, int data)
{
  struct Node* newnode=CreateNode(data);
  newnode->next=*head;
  *head=newnode;
  return;
}

void InsertAtEnd(struct Node** head, int data)
{
  struct Node* newnode=CreateNode(data);
  if(*head==NULL)
  {
    *head=newnode;
    return;
  }
  struct Node* temp=*head;
  while(temp->next!=NULL)
    {
      temp=temp->next;
    }
  temp->next=newnode;
}

void InsertAtPosition(struct Node** head, int data, int position)
{
  struct Node* newnode=CreateNode(data);
  if(position==0)
  {
    InsertAtFirst(head, data);
    return;
  }
  struct Node* temp=*head;
  for(int i=0; temp!=NULL&&i<position-1; i++)
    {
      temp=temp->next;
    }
  if(temp==NULL)
  {
    printf("Position out of bound\n");
  }
  newnode->next=temp->next;
  temp->next=newnode;

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

int main()
{
  struct Node* head=NULL;
  int choice, value, position;
  do{
  printf("Menu\n");
  printf("1.Insert at first\n");
  printf("2. Insert at position\n");
  printf("3. Insert at end\n");
  printf("4. Exit\n");

  scanf("%d", &choice);
  switch(choice)
    {
      case 1:
          printf("Enter the value to be inserted:");
          scanf("%d", &value);
          InsertAtFirst(&head, value);
          print(head);
          break;

      case 2:
          printf("Enter the value to be inserted:");
          scanf("%d", &value);
          printf("Enter the position:");
          scanf("%d", &position);
          InsertAtPosition(&head, value, position);
          print(head);
          break;

      case 3:
          printf("Enter the value to be inserted:");
          scanf("%d", &value);
          InsertAtEnd(&head, value);
          print(head);
          break;

      case 4:
          printf("The program has been terminated");
          break;
    }
  }while (choice!=4);

return 0;
}
