#include <bits/stdc++.h>
using namespace std;

void printVector(vector<pair<int,int> > &v1) {
    // cout << "Size: " << v.size() << endl;
    for(int i=0;i<v1.size();i++)
        cout << v1[i].first << " " << v1[i].second << endl;
    // v.push_back(2);
    cout << endl;
}
// void printVector(vector<string> &v) {
//     cout << "Size: " << v.size() << endl;
//     for(int i=0;i<v.size();i++)
//         cout << v[i] << " ";
//     // v.push_back(2);
//     cout << endl;
// }

int main() {
    vector<string> v;
    vector<pair<int,int>> v1 = {{1,2}, {2,3}, {3,4}};
    // int n;
    // cin >> n;
    // for(int i=0;i < n ; i++) {
    //     string s;
    //     cin >> s;
    //     v.push_back(s);
    // }
    // printVector(v);
    printVector(v1);
    return 0;
}

// int main() {
//     vector<int> v;
//     // int n;
//     // cin >> n;
//     // for(int i=0; i <n; i++)
//     // {
//     //     int x;
//     //     cin >> x;
//     //     printVector(v);

//     //     v.push_back(x);
//     // }
//     // printVector(v);

//     v.push_back(7);
//     v.push_back(6);
//     // printVector(v);
//     // v.pop_back();
//     // printVector(v);

//     // Copying vector into another vector
//     vector<int> v1 = v;
    
//     v1.push_back(5);
//     printVector(v);
//     printVector(v);
//     printVector(v1);
    // return 0;
// }