#include <bits/stdc++.h>
using namespace std;

int naiveStringMatch(string p, string t) {
    int m = p.length();
    int n = t.length();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (t[i+j] != p[j])
                break;
        }
        if (j == m)
            return i;
    }
    return -1;
}

int main() {
    string t, p;
    cin >> p >> t;
    int pos = naiveStringMatch(p, t);
    if (pos == -1)
        cout << "Pattern not found." << endl;
    else
        cout << "Pattern found at position " << pos << "." << endl;

    return 0;
}
