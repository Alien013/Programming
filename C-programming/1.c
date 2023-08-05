#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;

    return newnode;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
        return newNode(value);

    if (root->data > value)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

int arr[100] = {0};
int a = 0;
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    arr[a] = root->data;
    a++;
    inorder(root->right);
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

struct node *minVal(struct node *root)
{
    struct node *current = root;
    while (current != NULL && current->left != NULL)
        current = current->left;
    return current;
}

struct node *maxVal(struct node *root)
{
    struct node *current = root;
    while (current != NULL && current->right != NULL)
        current = current->right;
    return current;
}

struct node *successor(struct node *root)
{
    if (root == NULL)
        return NULL;
    return minVal(root->right);
}
struct node *predecessor(struct node *root)
{
    if (root == NULL)
        return NULL;
    return maxVal(root->left);
}

struct node *searchTree(struct node *root, int value)
{
    if (root == NULL || root->data == value)
        return root;

    if (root->data > value)
        return searchTree(root->left, value);
    else
        return searchTree(root->right, value);
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
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = minVal(root->right);
        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    int choice = 0;
    printf("Options: \n");
    printf("1-> Insertion: \n");
    printf("2-> Deletion: \n");
    printf("3-> Traversals: \n");
    printf("4-> Find min & max: \n");
    printf("5-> Find no closer to given no.: \n");
    printf("-1 -> To exit. \n");
    struct node *root;
    while (choice != -1)
    {
        printf("\nEnter the choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            int n;
            printf("Enter the no. of nodes: ");
            scanf("%d", &n);
            int val;
            printf("Enter the data in the nodes: ");
            scanf("%d", &val);
            root = newNode(val);
            for (int a = 0; a < (n - 1); a++)
            {
                scanf("%d", &val);
                insert(root, val);
            }
            break;
        }
        case 2:
        {
            int Delete;
            printf("\nEnter node data to be deleted: ");
            scanf("%d", &Delete);
            deleteNode(root, Delete);

            break;
        }
        case 3:
        {
            printf("\nPreorder: ");
            preorder(root);
            printf("\nInorder: ");
            inorder(root);
            printf("\nPostorder: ");
            postorder(root);

            break;
        }
        case 4:
        {
            printf("\nMinimum element: %d", (minVal(root))->data);
            printf("\nMaximum element: %d", (maxVal(root))->data);

            break;
        }

        case 5:
        {
            int val;
            printf("\nEnter the element to find closer value: ");
            scanf("%d", &val);
            int ans = 10000;
            int check = 10000;
            for (int a = 0; a < 50; a++)
            {
                int diff;
                if (arr[a] != val)
                {
                    diff = abs(arr[a] - val);
                    if (diff < check)
                    {
                        check = diff;
                        ans = arr[a];
                    }
                }
            }
            printf("\nCloser value is: %d", ans);
            break;
        }
        default:
        {
            printf("\nInvalid Choice!");
            break;
        }
        }
    }

    return 0;
}