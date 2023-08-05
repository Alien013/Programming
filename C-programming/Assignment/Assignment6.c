#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
int queue[N];
int front = -1;
int rear = -1;
int size = -1;
void enqueue(int value)
{
    if (size < N)
    {
        if (size < 0)
        {
            queue[0] = value;
            front = rear = 0;
            size = 1;
        }
        else if (rear == N - 1)
        {
            queue[0] = value;
            rear = 0;
            size++;
        }
        else
        {
            queue[rear + 1] = value;
            rear++;
            size++;
        }
    }
    else
    {
        printf("Queue is full\n");
    }
}
int dequeue()
{
    if (size < 0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        size--;
        front++;
    }
}
int Front()
{
    return queue[front];
}

void display()
{
    int i;
    if (rear >= front)
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
    else
    {
        for (i = front; i < N; i++)
        {
            printf("%d\n", queue[i]);
        }
        for (i = 0; i <= rear; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

void Max(int value){
    int max=queue[0];
    value=queue[0];
    front == rear==0;
    for(int i=0;i<size;i++) {

    if(queue[i] > max) {
        max=queue[i];
    }
    }
    printf("Max element is %d",max);
}

int main()
{
    enqueue(4);
    enqueue(8);
    enqueue(10);
    enqueue(20);
    display();
    dequeue();
    printf("After dequeue\n");
    display();
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    dequeue();
    enqueue(90);
    enqueue(100);
    enqueue(110);
    enqueue(120);
    printf("After enqueue\n");
    display();

    Max(queue[N]);
    return 0;
}