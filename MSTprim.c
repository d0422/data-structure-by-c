//근데 이제 재귀를 곁들인...
#include <stdio.h>
#include <stdlib.h>
#define vertices 10
#define MAX 999999
int result = 0;
int selected[vertices] = {
    0,
};
int dist[vertices] = {
    MAX, MAX, MAX, MAX, MAX, MAX, MAX, MAX, MAX, MAX};
struct node
{
    struct node *next;
    int dest;
    int cost;
};
struct graph
{
    struct node *v[vertices];
};
void insert_edge(struct graph *g, int x, int y, int cost)
{
    struct node *newnode1 = (struct node *)malloc(sizeof(struct node));
    newnode1->dest = y;
    newnode1->cost = cost;
    newnode1->next = NULL;
    newnode1->next = g->v[x]->next;
    g->v[x]->next = newnode1;

    struct node *newnode2 = (struct node *)malloc(sizeof(struct node));
    newnode2->dest = x;
    newnode2->next = NULL;
    newnode2->next = g->v[y]->next;
    newnode2->cost = cost;
    g->v[y]->next = newnode2;
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
int min(int a, int b)
{
    if (a >= b)
        return b;
    else
        return a;
}
void prim(struct graph *g, int start)
{
    struct node *cur;
    struct node *ck = NULL;
    int MIN = MAX;
    int x;
    int sel = -1;
    printf("%d ", start);
    selected[start] = 1;
    cur = g->v[start]->next;
    while (cur != NULL)
    {
        dist[cur->dest] = min(dist[cur->dest], cur->cost);
        cur = cur->next;
    }
    for (x = 0; x < vertices; x++)
    {
        if (MIN > dist[x] && selected[x] == 0)
        {
            MIN = dist[x];
            sel = x;
        }
    }
    if (sel != -1)
    {
        result += MIN;
        prim(g, sel);
    }
}
int main()
{
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    init_graph(g);
    insert_edge(g, 1, 2, 3);
    insert_edge(g, 1, 6, 4);
    insert_edge(g, 2, 4, 2);
    insert_edge(g, 1, 3, 1);
    insert_edge(g, 3, 5, 8);
    insert_edge(g, 5, 7, 5);
    insert_edge(g, 8, 7, 7);
    insert_edge(g, 8, 4, 9);
    insert_edge(g, 1, 8, 2);
    insert_edge(g, 5, 4, 1);
    printf("path : ");
    prim(g, 1);
    printf("\ncost : %d", result);
}