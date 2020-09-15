#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct tree_s
{
    char data;
    struct Tree_s *left;
    struct Tree_s *right;
}tree;

int globalError = 0;

tree *buildTreeByPref(tree *root)
{
    char ch;
    scanf("%c", &ch);
    tree *node = malloc(sizeof(tree));
    node->data = ch;
    if ((ch >= '0') && (ch <= '9'))
    {
        node->left = NULL;
        node->right = NULL;
    }
    else
    {
        node->left = buildTreeByPref(root->left);
        node->right = buildTreeByPref(root->left);
    }
    return node;
}

void printTreeStraight (tree *root)
{
    if (root == NULL)
        return;
    printf("%c ", root->data);
    printTreeStraight(root->left);
    printTreeStraight(root->right);
}

int calcFormula(tree *root)
{
    if (globalError)
        return -1;
    if ((root->left == NULL) && (root->right == NULL))
        return root->data - '0';
    int leftCalc = calcFormula(root->left);
    int rightCalc = calcFormula(root->right);
    switch (root->data)
    {
    case '+':
    {
        return leftCalc + rightCalc;
        break;
    }
    case '-':
    {
        return leftCalc - rightCalc;
        break;
    }
    case '*':
    {
        return leftCalc*rightCalc;
        break;
    }
    case '/':
    {
        if (rightCalc == 0)
        {
            globalError = 1;
            return -1;
        }
        return leftCalc/rightCalc;
        break;
    }
    default:
        break;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int res;
    tree *root = malloc(sizeof(tree));
    root = buildTreeByPref(root);
    res = calcFormula(root);
    if (globalError)
        printf("NO");
    else
        printf("%d", res);
    return 0;
}
