// �ٵ� ���� ��͸� �����
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *recursion(struct node *root, int data)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->left = NULL;
        root->right = NULL;
        root->data = data;
        return root;
    }
    else
    {
        if (root->data > data)
            root->left = recursion(root->left, data);
        else
            root->right = recursion(root->right, data);
    }
    return root;
}
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
int main()
{
    int x;
    struct node *root = NULL;
    int random;
    srand(time(NULL));
    printf("���� ���� : ");
    for (x = 0; x < 10; x++)
    {
        random = rand();
        printf("%d ", random);
        root = recursion(root, random);
    }
    printf("\n");
    printf("���� ��ȸ : ");
    preorder(root);
    printf("\n������ȸ : ");
    inorder(root);
    printf("\n������ȸ : ");
    postorder(root);
}
