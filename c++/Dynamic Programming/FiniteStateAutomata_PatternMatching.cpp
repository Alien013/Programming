#include <bits/stdc++.h>
using namespace std;

const int MAX_CHARS = 256;
// Compute the transition function for the FSA
void computeTransitionFunction(string p, vector<vector<int>> &delta){
    int m = p.length();
    // Initialize the transition function to 0 for all states and characters
    for (int q = 0; q <= m; q++) {
        for (int a = 0; a < MAX_CHARS; a++) {
            delta[q][a] = 0;
        }
    }
    // Compute the transition function using the Knuth-Morris-Pratt algorithm
    int k = 0;
    for (int q = 0; q < m; q++) {
        for (int a = 0; a < MAX_CHARS; a++) {
            if (a == p[q]) {
                delta[q][a] = q + 1;
            }

            else {
                delta[q][a] = delta[k][a];
            }
        }
        if (q < m) {
            k = delta[k][p[q]];
        }
    }
}

// Search for the p in the t using the FSA
int search(string p, string t) {
    int m = p.length();
    int n = t.length();

    // Compute the transition function for the FSA
    vector<vector<int>> delta(m + 1, vector<int>(MAX_CHARS));
    computeTransitionFunction(p, delta);

    // Run the FSA on the t
    int q = 0;
    for (int i = 0; i < n; i++) {
        q = delta[q][t[i]];
        if (q == m) {
            return i - m + 1;
        }
    }
    return -1;
}

int main() {
    string t, p;
    cin >> p >> t;
    int pos = search(p, t);
    if (pos == -1)
        cout << "Pattern not found." << endl;
    else
        cout << "Pattern found at position " << pos << "." << endl;
    return 0;
}
