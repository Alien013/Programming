// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int arr[n];
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         for (int i = 0; i < n; i++)
//         {
//             cout << arr[i];
//         }
//         int count;
//         for (int i = 0; i < n; i++)
//         {
//             if(arr[i+1] > arr[i]) {
//                 count = arr[i];
//             }
//             else 
//             continue;
//         }
//         cout << endl << count << endl;
//         int res=arr[0];
//         for (int i = 1; i < n; i++)
//         {
//             res ^= arr[i];
//         }
//         cout << endl << count << endl;
//         int ans=res^count;
//         cout << ans;
//     }
//     return 0;
// }

