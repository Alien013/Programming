#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair<long long, pair<int, int>> p[MAX];

void initialize()
{
    for (int i = 0; i < MAX; ++i)
        id[i] = i;
}

int root(int x)
{
    while (id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int>> p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for (int i = 0; i < edges; ++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;

        if (root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

int main()
{
    int x, y;
    long long weight, minimumCost;
    initialize();

    cin >> nodes;
    
    pair<int, int> nd[nodes];

    edges = (nodes * (nodes - 1)) / 2;

    for (int i = 0; i < nodes; ++i)
    {
        cin >> x >> y;
        nd[i] = {x, y};
    }

    int ind = 0;
    for (int i = 0; i < nodes - 1; i++)
    {
        for (int j = i + 1; j < nodes; j++)
        {
            p[ind++] = {(abs(nd[i].first - nd[j].first) + abs(nd[i].second - nd[j].second)), {i, j}};
        }
    }

    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}
