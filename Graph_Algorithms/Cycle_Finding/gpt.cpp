#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
int n, m;
vector<vector<long long>> edges;
vector<long long> dist;
vector<int> parent;

int main() {
    cin >> n >> m;
    edges.reserve(m);
    for (int i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a - 1, b - 1, c});
    }

    dist.assign(n, 0);
    parent.assign(n, -1);

    int x = -1; // will store last relaxed vertex (part of a cycle)

    // Bellman-Ford core
    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto e : edges) {
            int u = e[0], v = e[1];
            long long w = e[2];
            if (dist[v] > dist[u] + w) {
                dist[v] = max(-INF, dist[u] + w);
                parent[v] = u;
                x = v; // last relaxed vertex
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";

        // Reconstruct the cycle
        // To ensure we are inside the cycle, go n steps back
        for (int i = 0; i < n; i++) x = parent[x];

        vector<int> cycle;
        for (int v = x;; v = parent[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());

        for (int v : cycle) cout << v + 1 << " ";
        cout << "\n";
    }
}
