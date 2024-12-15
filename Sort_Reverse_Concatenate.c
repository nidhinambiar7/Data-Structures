#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node *next;
}Node;

Node *createNode(int value)
{
  Node *newNode=(Node *)malloc(sizeof(Node));
  if (newNode==NULL)
  {
    printf("memory allocation failed.");
    exit(1);
  }
  newNode->data=value;
  newNode->next=NULL;
  return newNode;
}

Node *insert(Node *head, int value)
{
  Node *newNode=createNode(value);
  newNode->next=head;
  return newNode;
}

Node *sort(Node *head)
{
  Node *temp, *current;
  int t;
  current=head;
  while(current!=NULL)
    {
      temp=head;
      while(temp->next!=NULL)
        {
          if(temp->data>temp->next->data)
          {
            t=temp->data;
            temp->data=temp->next->data;
            temp->next->data=t;
          }
          temp=temp->next;
        }
      current=current->next;
    }
  return head;
}

Node *concat(Node *head1, Node *head2)
{
  Node *temp=head1;
  while(temp->next!=NULL)
    {
      temp=temp->next;
    }
  temp->next=head2;
  return head1;
}

Node *reverse(Node *head)
{
  Node *prev=NULL;Node *temp, *next;
  temp=head;
  while(temp!=NULL)
    {
      next=temp->next;
      temp->next=prev;
      prev=temp;
      temp=next;
    }
  head=prev;
  return head;
}
void display(Node *head1, Node *head2)
{
  while(head1!=NULL)
    {
      printf("%d->", head1->data);
      head1=head1->next;
    }
    printf("NULL\n");
  while(head2!=NULL)
    {
      printf("%d->", head2->data);
      head2=head2->next;
    }
    printf("NULL\n");

}
int main()
{
  Node *list1=NULL;
  Node *list2=NULL;
  int value, choice;

  do
    {
      printf("\n1. Insert in list 1.\n");
      printf("2. Insert in list2\n");
      
      printf("3. Sort the lists\n");
      printf("4. Concatenation\n");
      printf("5. Reverse\n");
      printf("6. Exit\n");
      printf("Enter your choice: \n\n");
      scanf("%d", &choice);

      switch(choice)
        {
          case 1:
             printf("Enter the value to be inserted:");
             scanf("%d", &value);
             list1=insert(list1, value);
             display(list1, list2);
             break;
          case 2:
             printf("Enter the value to be inserted:");
             scanf("%d", &value);
             list2=insert(list2, value);
             display(list1, list2);
             break;

          case 6:
             printf("Exiting the program");
             break;
          case 3:
             list1=sort(list1);
             list2=sort(list2);
             display(list1, list2);
          case 4:
             list1=concat(list1, list2);
             display(list1, list2);
             break;
          case 5:
             list1=reverse(list1);
             list2=reverse(list2);
             display(list1, list2);
             break;
          default:
             printf("Invalid choice.");
             break;
        }
    }while(choice!=3);
  return 0;
}