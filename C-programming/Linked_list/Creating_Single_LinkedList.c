#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int data, n;
    scanf("%d", &n);
    struct node *head = malloc(sizeof(struct node));
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;

    struct node *current = malloc(sizeof(struct node));
    scanf("%d", &data);
    current->data = data;
    head->next = current;

    current = malloc(sizeof(struct node));
    scanf("%d", data);
    current->data = data;
    head->next->next = current;

    return 0;
}