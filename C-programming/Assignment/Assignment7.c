#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *left, *right;
};

void insert(struct node **tree, int val)
{
    struct node *temp = NULL;
    if (!(*tree))
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if (val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if (val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}
struct node *Search(struct node **tree, int val)
{
    if (!(*tree))
    {
        return NULL;
    }
    if (val == (*tree)->data)
    {
        return *tree;
    }
    else if (val < (*tree)->data)
    {
        Search(&((*tree)->left), val);
    }
    else if (val > (*tree)->data)
    {
        Search(&((*tree)->right), val);
    }
}

void print_inorder(struct node *tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d ", tree->data);
        print_inorder(tree->right);
    }
}

int MaxValue(struct node* node)
{
    struct node* temp = node;
 
    while (temp->right != NULL) {
        temp = temp->right;
    }
    return (temp->data);
}

int main()
{

    struct node *root = NULL;
    struct node *temp;
    int n, num;

    printf("Enter number of nodes present in tree\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        insert(&root, num);
    }

    printf("\nIn Order Display tree\n");
    print_inorder(root);

    int n1;
    printf("\nEnter the element to be searched\n");
    scanf("%d", &n1);
    temp = Search(&root, n1);

    if (temp)
    {
        printf("Searched node found \nData found is - %d\n", temp->data);
    }
    else
    {
        printf("Data not found in tree\n");
    }
    printf("\n Minimum value in BST is %d", MaxValue(root));

    return 0;
}