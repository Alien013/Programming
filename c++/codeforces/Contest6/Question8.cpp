#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << (n * n - n + 2) / 2 << endl;
    }
    return 0;
}

// #include <iostream>

// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int Smax = n;
//         int Smin = 1;
//         for (int i = 1; i < n; i++){
//             cout << Smax - Smin << " ";
//             if ((n - i) % 2 == 1)
//                 Smin++;
//             else
//                 Smax--;
//         }
//         cout << endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <set>
// using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         multiset<int> S;
//         for (int i = 1; i <= n; i++)
//         {
//             S.insert(i);
//         }
//         while (S.size() > 1)
//         {
//             int Smax = *prev(S.end());
//             S.erase(prev(S.end()));
//             int Smin = *S.begin();
//             S.erase(S.begin());
//             int diff = Smax - Smin;
//             S.insert(diff);
//         }
//         cout << *S.begin() << endl;
//     }
//     return 0;
// }
