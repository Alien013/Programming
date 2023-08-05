#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;

    struct node *leftChild;
    struct node *rightChild;
};

struct node *root = NULL;

void insert(int data)
{
    struct node *tempNode = (struct node *)malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;

    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    // if tree is empty
    if (root == NULL)
    {
        root = tempNode;
    }
    else
    {
        current = root;
        parent = NULL;

        while (1)
        {
            parent = current;

            // go to left of the tree
            if (data < parent->data)
            {
                current = current->leftChild;

                // insert to the left
                if (current == NULL)
                {
                    parent->leftChild = tempNode;
                    return;
                }
            }
            // go to right of the tree
            else
            {
                current = current->rightChild;

                // insert to the right
                if (current == NULL)
                {
                    parent->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}

struct node *search(int data)
{
    struct node *current = root;
    printf("Visiting elements: ");

    while (current->data != data)
    {
        if (current != NULL)
            printf("%d ", current->data);

        // go to left tree
        if (current->data > data)
        {
            current = current->leftChild;
        }
        // else go to right tree
        else
        {
            current = current->rightChild;
        }

        // not found
        if (current == NULL)
        {
            return NULL;
        }
    }

    return current;
}

void pre_order_traversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        pre_order_traversal(root->leftChild);
        pre_order_traversal(root->rightChild);
    }
}

void inorder_traversal(struct node *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->leftChild);
        printf("%d ", root->data);
        inorder_traversal(root->rightChild);
    }
}

void post_order_traversal(struct node *root)
{
    if (root != NULL)
    {
        post_order_traversal(root->leftChild);
        post_order_traversal(root->rightChild);
        printf("%d ", root->data);
    }
}

int main()
{
    int i;
    int n;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    int array[n];

    printf("Enter the Elements of array\n");
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &array[j]);
    }

    for (i = 0; i < n; i++)
        insert(array[i]);

    printf("Enter the element for search\n");
    scanf("%d", &i);
    struct node *temp = search(i);

    if (temp != NULL)
    {
        printf("[%d] Element found.", temp->data);
        printf("\n");
    }
    else
    {
        printf("[ x ] Element not found (%d).\n", i);
    }

    printf("Enter the to search\n");
    scanf("%d", &i);
    temp = search(i);

    if (temp != NULL)
    {
        printf("[%d] Element found.", temp->data);
        printf("\n");
    }
    else
    {
        printf("[ x ] Element not found (%d).\n", i);
    }

    printf("\nPreorder traversal: ");
    pre_order_traversal(root);

    printf("\nInorder traversal: ");
    inorder_traversal(root);

    printf("\nPost order traversal: ");
    post_order_traversal(root);

    return 0;
}
