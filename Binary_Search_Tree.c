#include<stdio.h>
#include<stdlib.h>

struct Node{
     int data;
     struct Node* right;
     struct Node* left;
};

struct Node* newNode(int data)
{
  struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
  temp->data=data;
  temp->right=temp->left=NULL;
  return temp;
}

struct Node* insert(struct Node* node, int value)
{
  if(node==NULL)
  {
    return newNode(value);
   
  }
  if(value<node->data)
  {
    node->left=insert(node->left, value);
  }
  else if(value>node->data)
  {
    node->right=insert(node->right, value);
  }
  return node;
}

void postOrder(struct Node* root)
{
  if (root != NULL)
  {
    postOrder(root->left);
    postOrder(root->right);
    printf(" %d ", root->data);
  }
}
void inOrder(struct Node* root)
{
  if (root != NULL)
  {
    inOrder(root->left);
    printf(" %d ", root->data);
    inOrder(root->right);
  }
}

void preOrder(struct Node* root)
{
  if (root != NULL)
  {
    printf(" %d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}

int main()
{
  struct Node* root=NULL;
  int value, choice;
  do
    {
      printf("\n\n1. Create a tree.\n");
      printf("2. PostOrder\n");
      printf("3. InOrder\n");
      printf("4. PreOrder\n");
      printf("5. Exit\n");
      printf("Enter choice: ");
      scanf("%d", &choice);

      switch(choice)
        {
          case 1:
               printf("Enter your value: ");
               scanf("%d", &value);
               root=insert(root, value);
               break;
          case 5:
               printf("Exiting...");
               break;
          case 2:
               printf("PostOrder: \n");
               postOrder(root);
               break;
          case 3:
               printf("InOrder: \n");
               inOrder(root);
               break;
          case 4:
               printf("PreOrder: \n");
               preOrder(root);
               break;
          default:
               printf("Invalid choice.");
               break;    
        }
    }while(choice!=5);
  return 0;
}