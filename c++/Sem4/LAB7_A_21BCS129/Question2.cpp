#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const int INF = 0x3f3f3f3f;

int n, x[N], y[N], dist[N];
bool vis[N];

int calc_dist(int i, int j)
{
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

void prim()
{
    memset(vis, false, sizeof vis);

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        int v = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        }
        if (v == -1)
            break;
        vis[v] = true;
        for (int u = 1; u <= n; u++)
        {
            if (!vis[u])
                dist[u] = min(dist[u], calc_dist(u, v));
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += dist[i];
    cout << res << endl;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    prim();
    return 0;
}