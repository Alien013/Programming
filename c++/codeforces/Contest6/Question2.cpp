#include <bits/stdc++.h>
using namespace std;
void Solve() {
    int n;
    cin >> n;
    if (n % 2 == 0)
    cout << -1 << endl;
    else {
        int c = 40;
        vector<int> moves;
        while (n != 1 && c--) {
            if (((n + 1) / 2) % 2) {
                n = (n + 1) / 2;
                moves.push_back(1);
            }
            else {
                n = (n - 1) / 2;
                moves.push_back(2);
            }
        }

        if (c < 0)
        cout << -1 << endl;
        else if (n == 1) {
            cout << moves.size() << endl;
            reverse(moves.begin(), moves.end());
            for (auto i : moves)
                cout << i << " ";
            cout << endl;
        }
        else
        cout << -1 << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while (t--)
    Solve();
    return 0;
}
