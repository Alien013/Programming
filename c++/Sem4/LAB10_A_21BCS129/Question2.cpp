#include <bits/stdc++.h>
using namespace std;

void MULTI_STAGE(vector<vector<int>> &G, int k, int n, vector<int> &p)
{
    vector<int> cost(n + 1, 0);
    vector<int> pi(n + 1, 0);
    // Step 1: Initialize cost array
    cost[n] = 0;

    // Step 2: Calculate costs for each vertex
    for (int j = n - 1; j >= 1; j--)
    {
        int min_cost = INT_MAX;
        int min_vertex = -1;
        for (int r = j + 1; r <= n; r++)
        {
            if (G[j][r] != -1 && G[j][r] + cost[r] < min_cost)
            {
                min_cost = G[j][r] + cost[r];
                min_vertex = r;
            }
        }
        cost[j] = min_cost;
        pi[j] = min_vertex;
    }

    // Step 3: Find minimum cost path
    p[0] = 1;
    p[k - 1] = n;
    for (int j = 1; j < k - 1; j++)
    {
        p[j] = pi[p[j - 1]];
    }
}

int main()
{
    int k, n;
    cin >> k >> n;
    vector<vector<int>> G(n + 1, vector<int>(n + 1, -1));
    vector<int> p(k, 0);
    // Step 0: Read input graph
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> G[i][j];
        }
    }
    // Step 4: Output minimum cost path
    MULTI_STAGE(G, k, n, p);
    for (int i = 0; i < k; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}