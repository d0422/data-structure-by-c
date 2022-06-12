// 근데 이제 인접행렬을 곁들인
// 근데 이제 재귀는 하지 않은
#define vertices 10
#include <stdio.h>
#include <stdlib.h>
struct graph
{
    int n;
    int matrix[vertices][vertices];
};
struct node
{
    struct node *next;
    int data;
};
struct queue
{
    struct node *front;
    struct node *rear;
    int count;
};
int isempty(struct queue *q)
{
    if (q->count == 0)
    {
        return 1;
    }
    else
        return 0;
}
void init_queue(struct queue *q)
{
    q->count = 0;
    q->front = q->rear = NULL;
}
void enqueue(struct queue *q, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (q->front == NULL)
    {
        q->front = newnode;
    }
    else
    {
        q->rear->next = newnode;
    }
    q->rear = newnode;
    q->count++;
}
int dequeue(struct queue *q)
{
    int data;
    struct node *tmp;
    if (isempty(q))
        return 0;
    tmp = q->front;
    q->front = tmp->next;
    data = tmp->data;
    free(tmp);
    q->count--;
    return data;
}
void append(struct node *head, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head->next;
    head->next = newnode;
}
int pop(struct node *head)
{
    struct node *tmp;
    int data;
    tmp = head->next;
    data = tmp->data;
    head->next = tmp->next;
    free(tmp);
    return data;
}
void graph_init(struct graph *g)
{
    int x, y;
    g->n = 0;
    for (x = 0; x < vertices; x++)
    {
        for (y = 0; y < vertices; y++)
        {
            g->matrix[x][y] = 0;
        }
    }
}
void insert_edge(struct graph *g, int x, int y)
{
    g->matrix[x][y] = 1;
    g->matrix[y][x] = 1;
    g->n++;
}
void dfs(struct graph *g, int start)
{
    int x = 0;
    int vis[vertices] = {0};
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->next = NULL;
    int cur;
    append(head, start);
    vis[start] = 1;
    printf("방문 경로 : ");
    while (head->next != NULL)
    {
        cur = pop(head);
        printf("%d ", cur);
        for (x = 0; x < vertices; x++)
        {
            if (g->matrix[x][cur] != 0 && vis[x] == 0)
            {
                append(head, x);
                vis[x] = 1;
            }
        }
    }
}
void bfs(struct graph *g, int start)
{
    int vis[vertices] = {0};
    int x;
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    init_queue(q);
    int cur;
    enqueue(q, start);
    vis[start] = 1;
    printf("BFS : ");
    while (!isempty(q))
    {
        cur = dequeue(q);
        printf("%d ", cur);
        for (int x = 0; x < vertices; x++)
        {
            if (g->matrix[x][cur] == 1 && vis[x] == 0)
            {
                enqueue(q, x);
                vis[x] = 1;
            }
        }
    }
}
int main()
{
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    graph_init(g);
    insert_edge(g, 1, 2);
    insert_edge(g, 1, 6);
    insert_edge(g, 2, 4);
    insert_edge(g, 1, 3);
    insert_edge(g, 3, 5);
    insert_edge(g, 5, 7);
    insert_edge(g, 8, 7);
    insert_edge(g, 8, 4);
    dfs(g, 1);
    printf("\n");
    bfs(g, 1);
}