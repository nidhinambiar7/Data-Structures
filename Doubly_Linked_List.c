#include<stdio.h>
#include<stdlib.h>

struct Node
{
     int data;
     struct Node* next;
     struct Node* prev;
};

struct Node* insert(struct Node* head, int data)
{
     struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
     newnode->data=data;
     newnode->next=head;
     newnode->prev=NULL;
     if (head!=NULL)
       head->prev=newnode;
    head=newnode;
    return head;
}

struct Node* create(struct Node* head)
{
  int n;
  printf("Enter the number of elements to be inserted:");
  scanf("%d", &n);
  for(int i=0; i<n; i++)
    {
      int value;
      printf("Enter the %dth element:", i+1);
      scanf("%d", &value);
      head=insert(head, value);
    }
  printf("The values have been inserted\n");
  return head;
}

void display(struct Node *head)
{
  struct Node* temp=head;
  while(temp!=NULL)
    {
      printf("%d->", temp->data);
      temp=temp->next;
    }
  printf("NULL\n");
}

struct Node* insertToLeft(struct Node* head, int target, int data)
{
  struct Node * temp=head;
  while(temp!=NULL&&temp->data!=target)
    {
      temp=temp->next;
    }
  if(temp==NULL)
  {
    printf("node not found");
    return head;
  }
  struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
  newnode->data=data;
  newnode->next=temp;
  newnode->prev=temp->prev;
  if(temp->prev!=NULL)
  {
    temp->prev->next=newnode;
  }
  else{
    head=newnode;
  }
  temp->prev=newnode;
  return head;
 
}

struct Node* deleteByValue(struct Node* head, int target)
{
  if( head==NULL)
  {
    printf("List is empty. Element cannot be deleted\n");
    return head;
  }
  struct Node* temp=head;
  while(temp!=NULL&&temp->data!=target)
    {
      temp=temp->next;
    }
  if(temp==NULL)
  {
    printf("Element not found.");
    return head;
  }

  if(temp==head)
  {
    head=head->next;
    if(head!=NULL)
    {
      head->prev=NULL;
    }
    free(temp);
    return head;
  }

  if(temp->next!=NULL)
  {
    temp->next->prev=temp->prev;
  }
  if(temp->prev!=NULL)
  {
    temp->prev->next=temp->next;
  }
  free(temp);
  return head;
}
int main()
{
  struct Node* head=NULL;
  int choice;
  int value, target;
  do
    {
      printf("1. Create a doubly linked list\n");
      printf("2. Insert to the left of a node\n");
      printf("3. Delete by value\n");
      printf("4. Exit\n");
      printf("Enter your choice:");
      scanf("%d", &choice);

      switch(choice)
        {
          case 1:
                 head=create(head);
                 display(head);
                 break;
          case 2:
               printf("Enter node:");
               scanf("%d", &target);
               printf("Enter value to be inserted:");
               scanf("%d", &value);
               head=insertToLeft(head,target, value);
               display(head);
               break;
          case 3:
               printf("Enter value to be deleted:");
               scanf("%d", &value);
               head=deleteByValue(head, value);
               display(head);
               break;
          case 4:
               printf("terminating the program");
               break;
          default:
              printf("Please enter a valid choice.");
              break;
        }
    }while(choice!=4);
 
 
  return 0;
}