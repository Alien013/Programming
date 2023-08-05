#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
void dijkstra(vector<vector<pii>> graph, int source, vector<int> &dist)
{
    int n = graph.size();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist.assign(n, INT_MAX);
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto [v, w] : graph[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    vector<vector<pii>> graph = {
        {{1, 4}, {1, 4}, {1, 5}, {1, 6}},
        {{2, 6}, {2, 3}, {2, -3}},
        {{3, 1}, {3, 2}},
        {{4, 5}, {4, 2}},
        {{5, 2}, {5, 2}},
        {{6, 3}, {6, 4}},
        {{7, 8}}};

    int source = 0; 
    vector<int> dist;
    dijkstra(graph, source, dist);
    for (int i = 0; i < dist.size(); i++)
    {
        cout << "Distance from vertex " << source << " to " << i << " is " << dist[i] << endl;
    }
    return 0;
}
