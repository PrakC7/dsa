#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

void addEdge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = u;
    newNode->next = adj[v];
    adj[v] = newNode;
}

void printGraph(int n) {
    for (int i = 0; i < n; i++) {
        struct Node* temp = adj[i];
        printf("%d: ", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int dfs(int v, int parent) {
    visited[v] = 1;
    struct Node* temp = adj[v];
    while (temp) {
        int u = temp->data;
        if (!visited[u]) {
            if (dfs(u, v))
                return 1;
        } else if (u != parent) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int hasCycle(int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    int n = 5;

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    addEdge(0, 1);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 4);

    printGraph(n);

    if (hasCycle(n))
        printf("Cycle exists\n");
    else
        printf("No cycle\n");

    return 0;
}
