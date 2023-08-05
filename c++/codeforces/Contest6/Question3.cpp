#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define pb push_back
const int N = (int)1e6 + 5;
const int M = (int)1e9 + 5;
const int MOD = (int)1000000007;
const int max_prime = (int)1e6 + 3;
const int BLK = (int)700;
const int X = 100000;
bool prime(int n){
    if (n < 2)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void dfs(ll v, vector<ll> &monsters_defeated, vector<vector<ll>> &graph, vector<ll> &a)
{
    monsters_defeated[v] = true;
    for (ll u : graph[v])
    {
        if (!monsters_defeated[u])
        {
            if (a[u] <= count(monsters_defeated.begin(), monsters_defeated.end(), true))
                dfs(u, monsters_defeated, graph, a);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        vector<vector<ll>> graph(n);
        for (ll i = 0; i < m; i++) {
            ll u, v;
            cin >> u >> v;
            u--; // convert to 0-based indexing
            v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<ll> monsters_defeated(n, false);
        ll start_vertex = min_element(a.begin(), a.end()) - a.begin();
        dfs(start_vertex, monsters_defeated, graph, a);
        if (count(monsters_defeated.begin(), monsters_defeated.end(), true) == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}