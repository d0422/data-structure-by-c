// 근데 이제 인접리스트와 재귀를 곁들인
#include <stdio.h>
#include <stdlib.h>
#define vertices 10
int vis[vertices] = {0};
struct node
{
    int data;
    struct node *next;
};
struct graph
{
    struct node *v[vertices];
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
        return 1;
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
void init_graph(struct graph *g)
{
    int x;
    for (x = 0; x < vertices; x++)
    {
        g->v[x] = (struct node *)malloc(sizeof(struct node));
        g->v[x]->next = NULL;
    }
}
void insert_edge(struct graph *g, int x, int y)
{
    struct node *newnode1 = (struct node *)malloc(sizeof(struct node));
    newnode1->data = y;
    newnode1->next = NULL;
    newnode1->next = g->v[x]->next;
    g->v[x]->next = newnode1;

    struct node *newnode2 = (struct node *)malloc(sizeof(struct node));
    newnode2->data = x;
    newnode2->next = NULL;
    newnode2->next = g->v[y]->next;
    g->v[y]->next = newnode2;
}
void init_vis()
{
    int x;
    for (x = 0; x < vertices; x++)
    {
        vis[x] = 0;
    }
}
void dfs(struct graph *g, int start)
{
    printf("%d ", start);
    vis[start] = 1;
    struct node *cur;
    cur = g->v[start]->next;
    while (cur != NULL)
    {
        if (vis[cur->data] == 0)
        {
            dfs(g, cur->data);
        }
        cur = cur->next;
    }
}
void bfs(struct graph *g, int start)
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    init_queue(q);
    struct node *cur;
    int tmp = 0;
    enqueue(q, start);
    vis[start] = 1;
    while (!isempty(q))
    {
        tmp = dequeue(q);
        printf("%d ", tmp);
        cur = g->v[tmp]->next;
        while (cur != NULL)
        {
            if (vis[cur->data] == 0)
            {
                enqueue(q, cur->data);
                vis[cur->data] = 1;
            }
            cur = cur->next;
        }
    }
}
int main()
{
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    struct node *cur;
    init_graph(g);
    insert_edge(g, 1, 2);
    insert_edge(g, 1, 6);
    insert_edge(g, 2, 4);
    insert_edge(g, 1, 3);
    insert_edge(g, 3, 5);
    insert_edge(g, 5, 7);
    insert_edge(g, 8, 7);
    insert_edge(g, 8, 4);
    printf("노드 출력 \n");
    for (int x = 0; x < vertices; x++)
    {
        printf("%d : ", x);
        cur = g->v[x]->next;
        while (cur != NULL)
        {
            printf("%d ", cur->data);
            cur = cur->next;
        }
        printf("\n");
    }
    init_vis();
    dfs(g, 1);
    printf("\n");
    init_vis();
    bfs(g, 1);
}