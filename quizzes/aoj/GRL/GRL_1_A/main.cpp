#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

int main()
{
    // input
    int V, E, r;
    cin >> V >> E >> r;

    vector<vector<pair<int, int>>> G(V);
    for (int i = 0; i < E; i++)
    {
        int s, t, d;
        cin >> s >> t >> d;
        G[s].emplace_back(t, d);
    }

    // Dijkstra's algorithm
    vector<ll> dist(V, INF);
    dist[r] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.emplace(0, r);

    while (!pq.empty())
    {
        auto [d, v] = pq.top();
        pq.pop();

        if (dist[v] < d)
            continue;

        for (auto [to, cost] : G[v])
        {
            if (dist[to] > dist[v] + cost)
            {
                dist[to] = dist[v] + cost;
                pq.emplace(dist[to], to);
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }

    return 0;
}
