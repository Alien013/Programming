#include <bits/stdc++.h>
using namespace std;

// Find the length of string
int getLength(char ch[]) {
    int c=0;
    for(int i=0; ch[i] !='\0'; i++) 
        c++;
    return c;
}

// Reverse the string
void reverse(char name[], int n) {
    int start = 0,end = n-1;
    while(start < end)
        swap(name[start++], name[end--]);
} 

int main() {
    char ch[10];

    cout << "Enter your name" << endl;
    cin >> ch;
    // ch[2] = '\0';
    cout << "Your name is " << ch << endl;
    int len = getLength(ch);
    cout << "The length of string is " << len << endl;

    reverse(ch,len);
    cout << "Your name is " << ch << endl;



    return 0;
}