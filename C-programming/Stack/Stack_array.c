#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 4
int stack_arr[n];
int top=-1;

int isFull() {
    if(top == n-1)
    return 1;
    else
    return 0;
}
void push(int data) {
    if(top == n-1) {
    printf("Stack Overflow\n");
    return;
    }
    top=top+1;
    stack_arr[top] =data;
}
int isEmpty() {
    if(top == -1) 
    return 1;
    else
    return 0; 
}
int pop(){
    int num;
    // if(top == -1) {
    if(isEmpty()) {
        printf("\nStack underfllow\n");
        exit(1);
    }
    num = stack_arr[top];
    top=top-1;
    return num;
}
int peek() {
    if(isEmpty()){
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack_arr[top];
}
void print(){
    // if(top == -1) {
        if(isFull()) {
        printf("Stack Underflow\n");
        return;
    }
    for(int i=top;i>=0;i--) {
        printf("%d ",stack_arr[i]);
    }
        printf("\n");
}
int main() {
    int num;
    // for(int i=top+1;i<n;i++){
    //     scanf("%d",&num);
    //     push(num);
    // }
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    print();   
    // for(int i=0;i<n;i++) {   
    // printf("%d ",stack_arr[i]);
    // }
    num=pop();
    print();
    printf("%d\n",num);
    num=pop();
    print();
    printf("%d\n",num);
    num=pop();
    print();
    printf("%d\n",num);
    num=pop();
    print();
    printf("%d\n",num);
    // num=pop();
    // for(int i=0;i<n;i++) {   
    // printf("\n%d ",stack_arr[i]);
    // }
    
    return 0;
}
// int main() {

//     int ch,data;
//     while(1){
//         printf("\n");
//         printf("1: Push\n");
//         printf("2: Pop\n");
//         printf("3: Print the top element\n");
//         printf("4: Print the all elements\n");
//         printf("5: Quit\n");
//         printf("Enter the choice:");
//         scanf("%d",&ch);
//         switch (ch)
//         {
//         case 1:
//             printf("Enter the element to to be pushed\n");
//             scanf("%d",&data);
//             push(data);
//             break;
//         case 2:
//             data = pop();
//             printf("Deleted element is %d\n",data);
//             break;
//         case 3:
//             printf("THe topmost element is %d\n",peek());
//             break;
//         case 4:
//             print();
//             break;
//         case 5:
//             exit(1);
//             break;
        
//         default:
//         printf("Invalid Choice");
//             break;
//         }
//     }
//     return 0;
// }
