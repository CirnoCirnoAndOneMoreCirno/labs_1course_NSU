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

int leavesCount(tree *root)
{
    if (root == NULL)
        return 0;
    if ((root->left == NULL) && (root->right == NULL))
        return 1;
    return leavesCount(root->left) + leavesCount(root->right);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, count;
    tree *root = NULL;

    while(scanf("%d ", &n) != EOF)
    {
        root = addNode(root, n);
    }
    count = leavesCount(root);
    printf("%d", count);
}
