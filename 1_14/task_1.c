#include <stdio.h>
#include <stdlib.h>

typedef struct tree_s
{
    int data;
    struct Tree_s *left;
    struct Tree_s *right;
}tree;

tree *addNode(tree *root, int num)
{
    if (root == NULL)
    {
        root = malloc(sizeof(tree));
        root->data = num;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (root->data > num)
        root->left = addNode(root->left, num);
    else if (root->data < num)
        root->right = addNode(root->right, num);
    return root;
}

void printTreeStraight (tree *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    printTreeStraight(root->left);
    printTreeStraight(root->right);
}

void printTreeReverse(tree *root)
{
    if (root == NULL)
        return;
    printTreeReverse(root->left);
    printTreeReverse(root->right);
    printf("%d ", root->data);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    tree *root = NULL;

    while(scanf("%d ", &n) != EOF)
    {
        root = addNode(root, n);
    }
    printTreeStraight(root);
    printf("\n");
    printTreeReverse(root);
}
