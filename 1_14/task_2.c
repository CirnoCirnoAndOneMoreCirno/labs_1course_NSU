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

int heightOfTree(tree *root)
{
    if (root == NULL)
        return -1;
    int heightLeft = heightOfTree(root->left), heightRight = heightOfTree(root->right);
    if (heightRight > heightLeft)
        return heightRight + 1;
    return heightLeft+1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, height;
    tree *root = NULL;

    while(scanf("%d ", &n) != EOF)
    {
        root = addNode(root, n);
    }
    height = heightOfTree(root);
    printf("%d", height);
}
