// 근데 이제 이중 연결리스트를 곁들인
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    struct node *prev;
    int data;
};
struct deque
{
    struct node *front;
    struct node *rear;
    int count;
};
int isempty(struct deque *d)
{
    if (d->count == 0)
        return 1;
    else
        return 0;
}
void init_deque(struct deque *d)
{
    d->front = d->rear = NULL;
    d->count = 0;
}
void append(struct deque *d, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (isempty(d))
    {
        d->front = newnode;
    }
    else
    {
        newnode->prev = d->rear;
        d->rear->next = newnode;
    }
    d->rear = newnode;
    d->count++;
}
void appendleft(struct deque *d, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    if (isempty(d))
    {
        d->rear = newnode;
    }
    else
    {
        d->front->prev = newnode;
        newnode->next = d->front;
    }
    d->front = newnode;
}
int pop(struct deque *d)
{
    struct node *tmp;
    int data;
    tmp = d->rear;
    data = tmp->data;
    d->rear = tmp->prev;
    free(tmp);
    return data;
}
int popleft(struct deque *d)
{
    struct node *tmp;
    int data;
    tmp = d->front;
    data = tmp->data;
    d->front = tmp->next;
    free(tmp);
    return data;
}
int main()
{
    struct deque *d = (struct deque *)malloc(sizeof(struct deque));
    init_deque(d);
    append(d, 1);
    append(d, 7);
    appendleft(d, 2);
    appendleft(d, 8);
    printf("%d ", popleft(d));
    printf("%d ", pop(d));
    printf("%d ", pop(d));
    printf("%d ", pop(d));
}