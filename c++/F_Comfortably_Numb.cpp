#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int mx, nb, mxnb = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                nb = arr[i];
                mx = arr[i];
                for (int k = i + 1; k <= j; k++)
                {
                    // cout << 1 << nb <<" " << arr[i]<<"\n";
                    nb ^= arr[k];
                    if (mx < arr[k])
                    {
                        mx = arr[k];
                    }

                    // cout << arr[k] << " ";
                }
                // cout << 2 << nb <<" " << mx<<"\n";
                nb ^= mx;
                if (mxnb < nb)
                {
                    mxnb = nb;
                }
                // cout << endl;
            }
        }

        cout << mxnb << "\n";
    }
    return 0;
}