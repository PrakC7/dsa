#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* next;
};

struct Node* adj[MAX];

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

int main() {
    int n = 4;

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    addEdge(0, 1);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 4);

    printGraph(n);

    return 0;
}
