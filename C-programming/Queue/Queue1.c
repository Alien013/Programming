#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 10
int arr[size];
int rear = -1;
int front = -1;

void enqueue(){
    int insert;
    if(rear == size-1) {
        printf("Overflow\n");
    }
    else {
        if(front == -1)
        front=0;
        printf("Enter the element to be inserted\n");
        scanf("%d",&insert);
        rear=rear+1;
        arr[rear] = insert;
    }
}
void dequeue(){
    if(front==-1 || front>rear) {
        printf("Underflow\n");
        return;
    }
    else {
        printf("Element deleted from the queue is %d\n",arr[front]);
        front+=1;
    }
}
void display(){
    if(front == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue :\n");
        for(int i=front;i<=rear;i++) {
            printf("%d ",arr[i]);
        }
    }
}



int main()
{
    int ch;
    
    while (1)
    {
        printf("Press 1. Enqueue Operation\n");
        printf("Press 2. Dequeue Operation\n");
        printf("Press 3. Display Queue\n");
        printf("Press 4. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice!");
        }
    }
    return 0;
}

