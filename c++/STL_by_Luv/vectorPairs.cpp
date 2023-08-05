#include <bits/stdc++.h>
using namespace std;

void printVector(vector<pair<int, int>> &v1)
{
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i].first << " " << v1[i].second << endl;
    cout << endl;
}

int main()
{
    vector<pair<int, int>> v;
    // vector<pair<int, int>> v1 = {{1, 2}, {2, 3}, {3, 4}};
    int n;
    cin >> n;
    for(int i=0;i <n;i++) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    printVector(v);
    // printVector(v1);
    return 0;
}

