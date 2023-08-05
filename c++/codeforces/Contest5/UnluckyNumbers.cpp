#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        if (r >= 10 * l)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << ((r % 10) - (l % 10) + 10) % 10 << endl;
        }
    }
    return 0;
}
