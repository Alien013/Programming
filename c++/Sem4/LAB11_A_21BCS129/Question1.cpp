#include <bits/stdc++.h>
using namespace std;

int fun(int num, int s, vector<int> &v, vector<int> &subset)
{
    if (s == 0)
        return 1;

    else if (s < 0)
        return 0;

    if (num == v.size())
        return 0;

    subset.push_back(v[num]);

    if (fun(num + 1, s - v[num], v, subset))
        return 1;

    subset.pop_back();

    if (fun(num + 1, s, v, subset))
        return 1;

    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s += v[i];
    }
    if (s % 2 != 0)
        cout << "NOT POSSIBLE.";
    else {
        vector<int> ans;
        int x = fun(0, s / 2, v, ans);
        if (ans.size() == 0)
            cout << "NOT POSSIBLE.";
        else {
            cout << "SUBSET1 is: ";

            for (auto m : ans)
                cout << m << " ";
            cout << "\n";
        }
    }
    return 0;
}