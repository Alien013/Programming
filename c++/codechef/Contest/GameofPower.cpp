#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, h, a, k;
        cin >> n >> h >> a >> k;
        vector<int> c(n), health(n);
        for (int i = 0; i < n; i++)
        {
            cin >> c[i] >> health[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (k > 0)
            {
                k--;
                continue;
            }
            health[i] -= a;
            if (health[i] > 0)
            {
                h -= c[i];
                if (h <= 0)
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        cout << "YES" << endl;
    }
    return 0;
}
