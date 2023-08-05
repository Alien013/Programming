#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, string> dp;
int c1 = 0, c2 = 0, c3 = 0;

void lcs_memo(string str1, string str2, int i, int j, string &ans) {
    c1++;
    if (i == str1.length() or j == str2.length()) {
        return;
    }

    if (dp.find({i, j}) == dp.end()){
        if (str1[i] == str2[j]) {
            ans.push_back(str1[i]);
            lcs_memo(str1, str2, i+1, j+1, ans);
            // cout << "1. " << ans <<"\n";
        }
        else {
            string choice1 = "", choice2 = "";
            lcs_memo(str1, str2, i+1, j, choice1);
            lcs_memo(str1, str2, i, j+1, choice2);
            (choice1.length() >= choice2.length()) ? ans += choice1 : ans += choice2;
            // cout << "2. " << ans <<"\n";
        }
        dp[{i, j}] = ans;
    }
    else {
        ans = dp[{i, j}];
    }
}

void lcs(string str1, string str2, int i, int j, string &ans) {
    c3++;
    if (i == str1.length() or j == str2.length()) {
        return;
    }

    if (str1[i] == str2[j]) {
        ans.push_back(str1[i]);
        lcs(str1, str2, i+1, j+1, ans);
        // cout << "1. " << ans <<"\n";
    }
    else {
        string choice1 = "", choice2 = "";
        lcs(str1, str2, i+1, j, choice1);
        lcs(str1, str2, i, j+1, choice2);
        (choice1.length() >= choice2.length()) ? ans += choice1 : ans += choice2;
        // cout << "2. " << ans <<"\n";
    }
}

int main()
{
    string str1, str2, s1 = "", s2 = "", s3 = "";
    cin >> str1 >> str2;

    lcs(str1, str2, 0, 0, s1);
    lcs_memo(str1, str2, 0, 0, s2);

    cout << s1 << "\n";
    cout << s2 << "\n";
    cout << c1 << " " << c2 << " " << c3 << "\n";

    return 0;
}