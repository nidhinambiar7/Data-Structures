#include<stdio.h>
#define MAX 5

void bfs(int adj[][MAX], int visited[], int start)
{
    int queue[MAX], rear=-1, front=-1;
    for(int k=0; k<MAX; k++)
    {
        visited[k]=0;
    }
    queue[++rear]=start;
    ++front;
    visited[start]=1;

    while(rear>=front)
    {
        start=queue[front++];
        printf("%d->", start);
        for(int i=0; i<MAX; i++)
        {
            if( adj[start][i]&&visited[i]==0)
            {
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}

int main()
{
    int choice,i,j,start;
    int adj[MAX][MAX];
    int visited[MAX]={0};

    do
    {
        printf("\nMENU:\n");
        printf("1. Give the adjacency matrix: \n");
        printf("2. BFS traversal: \n");
        printf("3. Exit \n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Enter the elements for the adjacency matrix: \n");
            for(int i=0;i<MAX; i++)
            {
                for(int j=0; j<MAX; j++)
                {
                    scanf("%d", &adj[i][j]);
                }
            }
            printf("The adjacency matrix is created");
            break;
        case 2:
            printf("Enter the node to start with: \nA:0\nB:1\nC:2\nD:3\nE:4\n");
            scanf("%d", &start);
            bfs(adj, visited, start);
            break;
        case 3:
            printf("The program has been terminated");
            break;
        default:
            printf("Please enter a valid choice:");
            break;
        }
    }while(choice!=3);
    return 0;
}
