#include <bits/stdc++.h>
using namespace std;

// Compute the prefix function for the KMP algorithm
vector<int> computePrefixFunction(string pattern)
{
    int m = pattern.length();
    vector<int> pi(m);

    pi[0] = 0;
    int k = 0;
    for (int i = 1; i < m; i++)
    {
        while (k > 0 && pattern[k] != pattern[i])
        {
            k = pi[k - 1];
        }
        if (pattern[k] == pattern[i])
        {
            k++;
        }
        pi[i] = k;
    }

    return pi;
}

// Search for the pattern in the text using the KMP algorithm
int search(string pattern, string text)
{
    int m = pattern.length();
    int n = text.length();
    vector<int> pi = computePrefixFunction(pattern);

    int q = 0;
    for (int i = 0; i < n; i++)
    {
        while (q > 0 && pattern[q] != text[i])
        {
            q = pi[q - 1];
        }
        if (pattern[q] == text[i])
        {
            q++;
        }
        if (q == m)
        {
            return i - m + 1;
        }
    }

    return -1;
}

int main()
{
    string pattern = "abc";
    string text = "abcbcabcdabc";

    int pos = search(pattern, text);

    if (pos == -1)
        cout << "Pattern not found." << endl;
    else
        cout << "Pattern found at position " << pos << "." << endl;

    return 0;
}
