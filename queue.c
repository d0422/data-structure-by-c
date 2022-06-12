// 연결리스트 기반 큐
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front;
    struct node *rear;
    int count;
};
void initqueue(struct queue *q)
{
    q->front = q->rear = NULL;
    q->count = 0;
}
int isempty(struct queue *q)
{
    if (q->count == 0)
        return 1;
    else
        return 0;
}
void enqueue(struct queue *q, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (isempty(q))
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
    int data = 0;
    struct node *cur;
    if (isempty(q))
    {
        return data;
    }
    cur = q->front;
    data = cur->data;
    q->front = cur->next;
    free(cur);
    q->count--;
    return data;
}
int main()
{
    struct queue q;
    initqueue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    while (q.count != 0)
    {
        printf("%d \n", dequeue(&q));
    }
}