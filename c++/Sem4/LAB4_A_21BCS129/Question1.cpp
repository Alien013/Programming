#include <bits/stdc++.h>
using namespace std;
#define PI 3.14
#define ll long long int

int main()
{
    int n = 11, m = 6;
    int Arr1[n] = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    int Arr2[m] = {2, 1, 4, 3, 9, 6};
    int freq[1000] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[Arr1[i]]++;
    }
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        while (freq[Arr2[i]]--)
        {
            Arr1[k++] = Arr2[i];
        }
    }
    
    for (int i = 0; i < 10000; i++)
    {
        if (freq[i] > 0)

            while (freq[i]--)

                Arr1[k++] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << Arr1[i] << " ";
    }

    return 0;
}
