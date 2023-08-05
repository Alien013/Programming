#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
    };

void PrintNodes(struct node *head) {
    struct node *ptr = NULL;
    if(head == NULL) 
    printf("List is empty");
    ptr=head;
    while(ptr != NULL) {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}

void Add_at_END(struct node *head, int data) {
    struct node *ptr,*temp;
    ptr=head;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    while(ptr->next != NULL) {
        ptr=ptr->next;
    }
    ptr->next = temp;
}

struct node* Add_at_Beginning(struct node *head,int data) {
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->next = head;
    head=ptr;
    return head;
}



int main() {
    struct node *head=NULL;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=45;
    head->next=NULL;

    // printf("%d",head->data);
    struct node *current=(struct node *)malloc(sizeof(struct node));

    current->data = 98;
    current->next = NULL;
    head->next = current;

    current=(struct node *)malloc(sizeof(struct node));

    current->data = 3;
    current->next = NULL;
    head->next->next = current;

    PrintNodes(head);


    // struct node *ptr=(struct node *)malloc(sizeof(struct node));
    // ptr = Add_at_END(head,98);
    // ptr = Add_at_END(head,3);
    // ptr = Add_at_END(head,67);
    // ptr=head;
    // while(ptr->next != NULL) {
    //     printf("%d\t",ptr->data);
    // }
    // Add_at_END(head,67);

    int data=100;
    Add_at_Beginning(head,data);

    return 0;
}