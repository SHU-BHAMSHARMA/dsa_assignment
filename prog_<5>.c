#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10

// Stack for DFS logic
struct NodeStack {
    int data[MAX_NODES];
    int top;
};

// Queue for BFS logic
struct NodeQueue {
    int data[MAX_NODES];
    int front, rear;
};

void push(struct NodeStack *s, int val) {
    s->data[++(s->top)] = val;
}

int pop(struct NodeStack *s) {
    return s->data[(s->top)--];
}

void enqueue(struct NodeQueue *q, int val) {
    if (q->front == -1) q->front = 0;
    q->data[++(q->rear)] = val;
}

int dequeue(struct NodeQueue *q) {
    int val = q->data[q->front++];
    if (q->front > q->rear) q->front = q->rear = -1;
    return val;
}

void performDFS(int adj[MAX_NODES][MAX_NODES], int n, int start) {
    struct NodeStack s;
    s.top = -1;
    int visited[MAX_NODES] = {0};

    push(&s, start);
    printf("DFS Traversal: ");

    while (s.top != -1) {
        int curr = pop(&s);
        if (!visited[curr]) {
            printf("%d ", curr);
            visited[curr] = 1;
            for (int i = n - 1; i >= 0; i--) {
                if (adj[curr][i] == 1 && !visited[i]) push(&s, i);
            }
        }
    }
    printf("\n");
}

void performBFS(int adj[MAX_NODES][MAX_NODES], int n, int start) {
    struct NodeQueue q;
    q.front = q.rear = -1;
    int visited[MAX_NODES] = {0};

    visited[start] = 1;
    enqueue(&q, start);
    printf("BFS Traversal: ");

    while (q.front != -1) {
        int curr = dequeue(&q);
        printf("%d ", curr);
        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n = 4; // Example with 4 nodes
    int adjMatrix[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    performBFS(adjMatrix, n, 0);
    performDFS(adjMatrix, n, 0);

    return 0;
}
