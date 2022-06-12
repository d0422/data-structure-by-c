// 연결리스트 기반
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};
struct stack
{
    struct node *head;
};
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
int main()
{
    struct stack s1;
    struct node *cur;
    s1.head = (struct node *)malloc(sizeof(struct node));
    s1.head->next = NULL;
    append(s1.head, 1);
    append(s1.head, 2);
    append(s1.head, 3);
    append(s1.head, 4);
    append(s1.head, 5);
    append(s1.head, 6);
    while (s1.head->next != NULL)
    {
        printf("pop : %d \n", pop(s1.head));
    }
}