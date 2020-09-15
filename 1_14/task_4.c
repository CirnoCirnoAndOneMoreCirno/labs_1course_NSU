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

int countOfNodesOnLevel(tree *root, int k)
{
    if (root == NULL)
        return 0;
    if (k == 0)
        return 1;
    return countOfNodesOnLevel(root->left, k-1) + countOfNodesOnLevel(root->right, k-1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, count, k;
    tree *root = NULL;
    scanf("%d", &k);
    while(scanf("%d ", &n) != EOF)
    {
        root = addNode(root, n);
    }
    count = countOfNodesOnLevel(root, k);
    printf("%d", count);
}
