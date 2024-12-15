#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};

void push(struct node **head, int value)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = value;
  newnode->next=*head;
  *head=newnode;
}

void pop(struct node **head)
{
  if(*head==NULL)
  {
    printf("Stack is empty");
    return;
  }
  struct node *temp=*head;
  printf("popped element is %d\n", (*head)->data);
  *head=(*head)->next;
  free(temp);
}

void printstack(struct node *head)
{
  if(head==NULL)
  {
    printf("Stack is empty");
    return;
  }
  struct node *temp=head;
  while(temp!=NULL)
    {
      printf("%d->", temp->data);
      temp=temp->next;
    }
  printf("NULL\n");
}

void enqueue(struct node **front, struct node **rear, int value)
{
  struct node *newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=value;
  newnode->next=NULL;

  if((*rear)==NULL&&(*front)==NULL)
  {
    (*rear)=(*front)=newnode;
  }
  (*rear)->next=newnode;
  (*rear)=newnode;
 }

void dequeue(struct node **front, struct node **rear)
{
  struct node *temp=*front;
  if((*front)==NULL)
  {
    printf("Empty queue");
    return;
  }
  else
  {
    (*front)=(*front)->next;
    printf("The deleted element is %d", temp->data);
    free(temp);
    if((*front)==NULL)
    {
      (*rear)=NULL;
    }
  }
}

void printqueue(struct node *front)
{
  if(front==NULL)
  {
    printf("Queue is empty");
    return;
  }
  struct node *temp=front;
  while(temp!=NULL)
    {
      printf("%d->", temp->data);
      temp=temp->next;
    }
  printf("NULL\n");
}

int main()
{
  struct node *head=NULL;
  struct node *front=NULL;
  struct node *rear=NULL;
  int value, choice;
  do
  {
     printf("1.Push\n");
     printf("2.Pop\n");
     printf("3.Display\n");
     printf("5. Enqueue\n");
     printf("6. Dequeue\n");
     printf("7. Display queue\n");
     printf("4.Exit\n");
     printf("Enter your choice: ");
     scanf("%d", &choice);

     switch(choice)
       {
         case 1:
             printf("Enter the value to be pushed: ");
             scanf("%d", &value);
             push(&head, value);
             break;
         case 2:
             pop(&head);
             break;
         case 3:
             printstack(head);
             break;
         case 4:
            printf("Exiting...\n");
            break;
         case 5:
             printf("Enter the value to be enqueued: ");
            scanf("%d", &value);
            enqueue(&front, &rear, value);
            break;
         case 6:
             dequeue(&front, &rear);
             break;
         case 7:
             printqueue(front);
             break;
         default:
            printf("Invalid choice. Please try again.\n");
       }
  }while(choice!=4);
  return 0;
 
}