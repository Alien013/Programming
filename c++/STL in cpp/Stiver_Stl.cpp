#include <bits/stdc++.h>
using namespace std;
array<int, 3> arr; //-->  {0,0,0}

struct node
{
    string str;
    int num;
    double doub;
    char x;

    // Create constructor
    node(string str_, int num_, double doub_, char x_)
    {
        str = str_;
        num = num_;
        doub = doub_;
        x = x_;
    }
};

int main()
{
    double val = 10.0;
    cout << val << endl;

    // Wrong way
    // node raj;
    // raj.str = "Manoj";
    // raj.num = 12;
    // raj.doub = 10.0;

    node *xyz = new node("Manoj", 12, 13.0, ' ');

    // cout << xyz->str << " ";
    // cout << xyz->num << " ";
    // cout << xyz->doub << " ";
    // cout << xyz->x;

    // Arrays  -->  int arr[100];

    array<int, 3> arr;             //--> garbage value
    array<int, 5> arr = {1, 2, 3}; //-->{1.2,3,0,0}
    array<int, 5> arr = {1};       //-->{1.0,0,0,0}
    array<int, 5> arr = {0};       //-->{0.0,0,0,0}

    int arr[1000];
    arr.fill(5);

    
    return 0;
}