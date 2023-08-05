#include <bits/stdc++.h>
using namespace std;

int Solution(int a, int b, int n)
{
    a--;
    b--;
    a = min(a, n - a - 1);
    b = min(b, n - b - 1);
    return min(a, b);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;
        cout << abs(Solution(x1, y1, n) - Solution(x2, y2, n)) << endl;
    }
    return 0;
}