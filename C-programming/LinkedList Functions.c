#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node  {
    int data;
    struct node *next;
};

void Count_Nodes(struct node *head) {
    int count=0;
    if(head==NULL)
    printf("list is empty");
    struct node *ptr=NULL;
    ptr=head;
    while(ptr != NULL) {
        count++;
        ptr=ptr->next;
    }
    printf("%d",count);
}

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

void Insert_at_AnyPosition(struct node *head,int data,int position) {
    struct node *ptr;
    struct node *ptr1=malloc(sizeof(struct node));
    ptr1->data=data;
    ptr1->next=NULL;
    position--;
    while(position != 1) {
        ptr=ptr->next;
        position--;
    }
    ptr1->next=ptr->next;
    ptr->next=ptr1;
}

struct node* Del_FirstNode(struct node *head) {
    if(head == NULL) 
    printf("List is already empty");
    else {
        struct node *temp=head;
        head=head->next;
        free(temp);
        temp=NULL;
    }
    return head;
}

struct node* Del_LastNode(struct node *head) {

    if(head == NULL)
    printf("List is already Empty");
    else if(head->next == NULL) {
        free(head);
        head=NULL;
    }
    else {
        struct node *temp=head;
        while(temp->next->next != NULL) {
            temp= temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
    // else {
    //     struct node *temp=head;
    //     struct node *temp1=head;
    //     while(temp->next != NULL) {
    //         temp1 = temp;
    //         temp=temp->next;
    //     }
    //     temp1->next = NULL;
    //     free(temp);
    // }
    // return head;
}

void Del_at_AnyPosition(struct node **head,int position) {
    struct node *current=*head;
    struct node *previous=*head;
    if(*head == NULL) 
    printf("List is empty");
    else if(position == 1) {
        *head=current->next;
        free(current);
        current=NULL;
    }
    else {
        while(position != 1) {
            previous=current;
            current=current->next;
            position--;
        }
        previous->next=current->next;
        free(current);
        current=NULL;
    }
}

struct node* Del_List(struct node *head) {
    struct node *temp=head;
    while(temp != NULL) {
        temp=temp->next;
        free(head);
        head=temp;
    }
    return head;
}

struct node* Reverse_LinkedList(struct node *head) {
    struct node *previous=NULL;
    struct mode *next = NULL;
    while(head != NULL) {
        next = head->next;
        head->next=previous;
        previous=head;
        head=next;
    }
    head=previous;
    return head;
}


int main() {
    
    return 0;
}