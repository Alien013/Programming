#include <bits/stdtr1c++.h>
using namespace std;
void select(int start[], int end[], int n)
{
    printf("The following activities are selected:\n");
    int j = 0;
    printf("%d ", j);
    int i;
    for (i = 1; i < n; i++)
    {
        if (start[i] >= end[j])
        {
            printf("%d ", i);
            j = i;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int start[n];
    for(int i=0;i<n;i++) {
        cin >> start[i];
    }
    for(int i=0;i<n;i++) {
        cout << start[i] +" ";
    }

    int END[n];
    for(int i=0;i<n;i++) {
        cin >> END[i];
    }
    for(int i=0;i<n;i++) {
        cout << END[i] +" ";
    }
    select(start, END, n);
    return 0;
}
