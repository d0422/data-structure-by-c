// 미완
#include <stdio.h>
#include <stdlib.h>
#define vertices 10
struct node
{
    struct node *next;
    int data;
};
struct graph
{
    struct node *v[vertices];
};
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
void init_graph(struct graph *g)
{
    int x;
    for (x = 0; x < vertices; x++)
    {
        g->v[x] = (struct node *)malloc(sizeof(struct node));
        g->v[x]->next = NULL;
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
}