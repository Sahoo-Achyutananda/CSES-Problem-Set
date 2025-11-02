#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> visited, parent;

int startNode = -1, endNode = -1;

bool dfs(int u, int par) {
    visited[u] = 1;
    for (auto v : adj[u]) {
        if (v == par) continue; // ignore the edge back to parent
        if (!visited[v]) {
            parent[v] = u;
            if (dfs(v, u))
                return true;
        } else {
            // Found a back edge → cycle detected
            startNode = v;
            endNode = u;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, {});
    visited.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, -1))
            break;
    }

    if (startNode == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(startNode);
        for (int v = endNode; v != startNode; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(startNode);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << "\n";
        for (auto v : cycle)
            cout << v << " ";
        cout << "\n";
    }

    return 0;
}
