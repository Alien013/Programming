#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, product = 1, sum = 0, diff, rem;
    cin >> n;
    int i = n;
    while(i > 0)
    {
        rem = i % 10;
        product = product * rem;
        sum = sum + rem;
        i /= 10;
    }
    int res = product - sum;
    cout << res << endl;
    return 0;
}