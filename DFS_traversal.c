#include<stdio.h>
#define MAX 5
void dfs(int adj[][MAX], int visited[], int start) {
    int stack[MAX];
    int top = -1, i, k;
    for (k = 0; k < MAX; k++)
        visited[k] = 0;
    stack[++top] = start;
    visited[start] = 1;

    printf("DFS Traversal: ");
    while (top != -1) {
        start = stack[top--];
        printf("%d -> ", start);
        for (i = 0; i < MAX; i++) {
            if (adj[start][i] && visited[i] == 0) {
                stack[++top] = i;
                visited[i] = 1;

            }
        }
    }

}

int main() {
    int visited[MAX] = {0};
    int adj[MAX][MAX], i, j, option, start;

    do {
        printf("\nDFS Menu\n");
        printf("1. Enter Adjacency Matrix\n");
        printf("2. Perform DFS Traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the adjacency matrix (%dx%d):\n", MAX, MAX);
                for (i = 0; i < MAX; i++)
                    for (j = 0; j < MAX; j++)
                        scanf("%d", &adj[i][j]);
                break;

            case 2:
                printf("Enter the node to start with:\nA:0\nB:1\nC:2\nD:3\nE:4\n");
                scanf("%d", &start);
                dfs(adj, visited, start);
                break;

            case 3:
                printf("Exiting DFS Program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (option != 3);

    return 0;
}
