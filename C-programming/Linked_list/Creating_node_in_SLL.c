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
    int data;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    
    printf("%d", head->data);
    return 0;
}