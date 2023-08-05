#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct node
{
    int key;
    struct Node *left, *right;
};

struct node *insertBST(struct node *root, int k)
{
    if (root == NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->key = k;
        newnode->left = NULL;
        newnode->right = NULL;
        root = newnode;
    }
    if (k < root->key)
    {
        root->left = insertBST(root->left, k);
    }
    else if (k > root->key)
    {
        root->right = insertBST(root->right, k);
    }
    return root;
}

struct node *mini(struct node *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node *succ(struct node *root)
{
    if (root->right == NULL)
    {
        return NULL;
    }
    else
    {
        return mini(root->right);
    }
}

struct node *deleteBST(struct node *root, int k)
{
    if (root == NULL)
        return root;

    if (k < root->key)
        root->left = deleteBST(root->left, k);

    else if (k > root->key)
        root->right = deleteBST(root->right, k);

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

        struct node *suc = succ(root);
        root->key = suc->key;
        root->right = deleteBST(root->right, suc->key);
    }
    return root;
}

struct node *search(struct node *root, int k)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->key < k)
    {
        return search(root->right, k);
    }
    else if (root->key > k)
    {
        return search(root->left, k);
    }
    else
    {
        return root;
    }
}

int hash(int k)
{
    return k % MAX;
}

void hashInsert(struct node **ht, int k)
{
    ht[hash(k)] = insertBST(ht[hash(k)], k);
}

struct node *hashSearch(struct node **ht, int k)
{
    if (hash(k) == hash(k + 1))
    {
        printf("Duplicate found!");
    }
    else
    {

        return search(ht[hash(k)], k);
    }
}

void hashDelete(struct node **ht, int k)
{
    ht[hash(k)] = deleteBST(ht[hash(k)], k);
}

void inorder_traversal(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->key);
    inorder_traversal(root->right);
}

int main()
{
    struct node *hash_table[MAX];

    for (size_t i = 0; i < MAX; i++)
    {
        hash_table[i] = NULL;
    }

    int option = 0;

    do
    {
        printf("Choose an option :\n 1. Insert\n 2. Delete\n 3. Search\n 4. Print\n 5.Update\n 6. Quit\n\nEnter choice : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            int ki;
            printf("\nEnter a number to insert : ");
            scanf("%d", &ki);
            if (hashSearch(hash_table, ki))
            {
                printf("\nid already present!\n\n");
            }
            else
            {
                hashInsert(hash_table, ki);
                printf("\n\t%d inserted!\n\n", ki);
                printf("No duplicate found.");
            }
            break;
        case 2:
            int kd;
            printf("\nEnter a number to delete : ");
            scanf("%d", &kd);
            if (hashSearch(hash_table, kd))
            {
                hashDelete(hash_table, kd);
                printf("\n\t%d deleted!\n\n", kd);
            }
            else
            {
                printf("\nid not present!\n\n");
            }
            break;
        case 3:
            int ks;
            printf("\nEnter a number to search : ");
            scanf("%d", &ks);
            (hashSearch(hash_table, ks)) ? printf("\n\tYes, %d is present in the Hash Table.\n\n", ks) : printf("\n\tNo, %d is not present in the Hash Table.\n\n", ks);
            break;
        case 4:
            printf("\nCurrent Hash Table :\n");
            for (size_t i = 0; i < MAX; i++)
            {
                if (hash_table[i])
                {
                    printf("%d : ", i);
                    inorder_traversal(hash_table[i]);
                    printf("\n");
                }
            }
            printf("\n");
            break;
        case 5:
            printf("\nCurrent Hash Table :\n");
            for (size_t i = 0; i < MAX; i++)
            {
                if (hash_table[i])
                {
                    printf("Duplicate found :");
                    inorder_traversal(hash_table[i]);
                    printf("\n");
                }
            }
            printf("\n");
            break;
        default:
            printf("\n\n Wrong choice.");
            break;
        }

    } while (option <= 4);

    return 0;
}