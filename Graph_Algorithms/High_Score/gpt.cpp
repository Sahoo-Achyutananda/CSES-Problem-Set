#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;

int n, m;
vector<tuple<int,int,ll>> edges;
vector<vector<int>> adj, rev;

void solve() {
    vector<ll> dist(n, -INF);
    dist[0] = 0;

    // Bellman-Ford relaxation for n-1 iterations
    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] == -INF) continue;
            if (dist[v] < dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Detect nodes affected by positive cycles
    vector<int> affected(n, 0);
    for (auto [u, v, w] : edges) {
        if (dist[u] != -INF && dist[v] < dist[u] + w) {
            affected[v] = 1;
        }
    }

    // Mark all nodes reachable from any affected node (forward)
    queue<int> q;
    vector<int> reachableFromCycle(n, 0);
    for (int i = 0; i < n; i++) {
        if (affected[i]) {
            q.push(i);
            reachableFromCycle[i] = 1;
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!reachableFromCycle[v]) {
                reachableFromCycle[v] = 1;
                q.push(v);
            }
        }
    }

    // Check if destination (n-1) is reachable from a positive cycle
    if (reachableFromCycle[n-1]) {
        cout << -1 << endl;  // infinite score
    } else {
        cout << dist[n-1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    edges.clear();
    adj.assign(n, {});
    rev.assign(n, {});

    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a; --b;
        edges.push_back({a, b, c});
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    solve();
    return 0;
}
