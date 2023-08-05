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

void Delete_Binary_Tree(struct node *tree)
{
    if (tree)
    {
        Delete_Binary_Tree(tree->left);
        Delete_Binary_Tree(tree->right);
        free(tree);
    }
}

void print_preorder(struct node *tree)
{
    if (tree)
    {
        printf("%d ", tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
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
void print_postorder(struct node *tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d ", tree->data);
    }
}
int minValue(struct node *node)
{
    struct node *current = node;

    while (current->left != NULL)
    {
        current = current->left;
    }
    return (current->data);
}
int maxValue(struct node *node)
{
    struct node *current = node;

    while (current->right != NULL)
    {
        current = current->right;
    }
    return (current->data);
}

struct node *deleteNode(struct node *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);

    else
    {
        if (root->left == NULL)
        {
            struct node *temp1 = root->right;
            free(root);
            return temp1;
        }
        else if (root->right == NULL)
        {
            struct node *temp1 = root->left;
            free(root);
            return temp1;
        }

        struct node *temp1 = minValue(root->right);
        root->data = temp1->data;

        root->right = deleteNode(root->right, temp1->data);
    }
    return root;
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
    printf("\nPre Order Display tree\n");
    print_preorder(root);

    printf("\nIn Order Display tree\n");
    print_inorder(root);
    printf("\nPost Order Display tree\n");
    print_postorder(root);

    int n1;
    printf("\nEnter the element to be searched\n");
    scanf("%d", &n1);
    temp = Search(&root, n1);
    if (temp)
        printf("Searched node - %d\n", temp->data);
    else
        printf("Data not found in tree\n");

    printf("\n Minimum value in BST is %d", minValue(root));
    printf("\n Maximum value in BST is %d", maxValue(root));

    int temp1;
    printf("\nEnter node data to be deleted: ");
    scanf("%d", &temp1);
    deleteNode(root, temp1);

    Delete_Binary_Tree(root);

    return 0;
}