// 크루스칼씨 왜그랬어
#include <stdio.h>
#include <stdlib.h>
#define vertices 10
#define edgenum 10
int COST[vertices];
int index = 0;
int edgeindex = 0;
struct node
{
    struct node *next;
    int data;
};
struct edge
{
    int start;
    int dest;
    int cost;
};
struct edge edge[edgenum];
void insert_edge(int g[][10], int x, int y, int cost)
{
    edge[edgeindex].start = x;
    edge[edgeindex].dest = y;
    edge[edgeindex].cost = cost;
    edgeindex++;
    g[x][y] = cost;
    g[y][x] = cost;
    COST[index++] = cost;
}
int find_parent(int *root, int v)
{
    while (root[v] != -1)
    {
        v = root[v];
    }
    return v;
}
void sort()
{
    int x, y;
    struct edge tmp;
    for (x = 0; x < edgeindex; x++)
    {
        for (y = 0; y < x; y++)
        {
            if (edge[x].cost < edge[y].cost)
            {
                tmp = edge[x];
                edge[x] = edge[y];
                edge[y] = tmp;
            }
        }
    }
}
int kruskal(int g[][10])
{
    int root[vertices];
    int cur;
    int result = 0;
    int x;

    int start, dest;
    sort();
    for (x = 0; x < vertices; x++)
    {
        root[x] = -1;
    }
    cur = 0;
    result = 0;
    for (x = 0; x < edgeindex; x++)
    {
        start = edge[x].dest;
        dest = edge[x].start;
        if (find_parent(root, start) != find_parent(root, dest))
        {
            root[find_parent(root, dest)] = find_parent(root, start);
            result += edge[x].cost;
        }
    }
    return result;
}
int main()
{
    int g[vertices][vertices] = {
        0,
    };
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
    printf("MST cost : %d", kruskal(g));
}