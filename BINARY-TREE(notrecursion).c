// 근데 이제 재귀를 곁들이지 않은
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct stack
{
    struct node *data;
    struct stack *next;
};
void append(struct stack *head, struct node *data)
{
    struct stack *newnode = (struct stack *)malloc(sizeof(struct stack));
    newnode->next = head->next;
    newnode->data = data;
    head->next = newnode;
}
struct node *pop(struct stack *head)
{
    struct node *data;
    struct stack *tmp;
    tmp = head->next;
    data = tmp->data;
    head->next = tmp->next;
    free(tmp);
    return data;
}
struct node *maketree(struct node *root, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    if (root == NULL)
        root = newnode;
    else
    {
        struct node *tmp;
        struct node *target;
        target = root;
        tmp = root;
        while (1)
        {
            if (tmp->data > data)
            {
                if (tmp->left == NULL)
                {
                    target = tmp;
                    tmp = tmp->left;
                    break;
                }
                target = tmp;
                tmp = tmp->left;
            }
            else
            {
                if (tmp->right == NULL)
                {
                    target = tmp;
                    tmp = tmp->right;
                    break;
                }
                target = tmp;

                tmp = tmp->right;
            }
        }
        if (target->data > data)
        {
            target->left = newnode;
        }
        else
        {
            target->right = newnode;
        }
    }
    return root;
}
void preorder(struct node *root)
{
    struct node *cur;
    struct stack *head = (struct stack *)malloc(sizeof(struct stack));
    head->next = NULL;
    append(head, root);
    while (head->next != NULL)
    {
        cur = pop(head);
        if (cur != NULL)
        {
            printf("%d ", cur->data);
            append(head, cur->left);
            append(head, cur->right);
        }
    }
    free(head);
}
void inorder(struct node *root)
{
    struct node *cur;
    struct stack *head = (struct stack *)malloc(sizeof(struct stack));
    head->next = NULL;
    cur = root;
    while (cur != NULL)
    {
        append(head, cur);
        cur = cur->left;
    }
    while (head->next != NULL)
    {
        cur = pop(head);
        printf("%d ", cur->data);
        cur = cur->right;
        while (cur != NULL)
        {
            append(head, cur);
            cur = cur->left;
        }
    }
}
void postorder(struct node *root)
{
    struct node *cur;
    struct stack *head = (struct stack *)malloc(sizeof(struct stack));
    struct stack *output = (struct stack *)malloc(sizeof(struct stack));
    head->next = NULL;
    output->next = NULL;
    cur = root;
    append(head, root);
    while (head->next != NULL)
    {
        cur = pop(head);
        append(output, cur);
        if (cur->left != NULL)
        {
            append(head, cur->left);
        }
        if (cur->right != NULL)
        {
            append(head, cur->right);
        }
    }
    while (output->next != NULL)
    {
        printf("%d ", pop(output)->data);
    }
}
int main()
{
    int x;
    struct node *root = NULL;
    int random;
    srand(time(NULL));
    printf("랜덤 생성 : ");
    for (x = 0; x < 10; x++)
    {
        random = rand();
        printf("%d ", random);
        root = maketree(root, random);
    }
    printf("\n");
    printf("전위 순회 : ");
    preorder(root);
    printf("\n중위순회 : ");
    inorder(root);
    printf("\n후위순회 : ");
    postorder(root);
}