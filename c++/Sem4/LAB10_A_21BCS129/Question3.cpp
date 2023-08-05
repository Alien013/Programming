#include <bits/stdc++.h>
using namespace std;

int LCS(string str1, string str2)
{
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> matrix(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            }
            else
            {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }

    return matrix[m][n];
}

int main()
{
    string str1 ,str2;
    cin >> str1;
    cin >> str2;
    int result = LCS(str1, str2);
    cout << result << endl;
    return 0;
}
