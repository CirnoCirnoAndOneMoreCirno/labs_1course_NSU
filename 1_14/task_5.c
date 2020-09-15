#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree_s
{
    char data[101];
    struct Tree_s *left;
    struct Tree_s *right;
}tree;

tree *addNode(tree *root, char *str)
{
    if (root == NULL)
    {
        root = malloc(sizeof(tree));
        strcpy(root->data, str);
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    int comp = strcmp(str, root->data);
    if (comp < 0)
        root->left = addNode(root->left, str);
    else if (comp > 0)
        root->right = addNode(root->right, str);
    return root;
}

void printInfix(tree *root)
{
    if (root == NULL)
        return;
    printInfix(root->left);
    printf("%s\n", root->data);
    printInfix(root->right);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char str[101];
    tree *root = NULL;
    while(scanf("%s", str) != EOF)
    {
        root = addNode(root, str);
    }
    printInfix(root);
}
