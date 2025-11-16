#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int,int>>> adj;
vector<long long> dist, paths;
vector<int> minHops, maxHops;
const long long INF = 1e18;
int MOD = 1e9 + 7;

void performDijkstra(){
    priority_queue<tuple<long long,int,int>, vector<tuple<long long,int,int>>, greater<>> pq;

    dist[0] = 0;
    paths[0] = 1;
    minHops[0] = maxHops[0] = 0;

    pq.push({0,0,0});

    while(!pq.empty()){
        auto [d,u,h] = pq.top();
        pq.pop();

        if(d != dist[u]) continue;

        for(auto &edge : adj[u]){
            int v, w;
            tie(v,w) = edge;
            long long nd = d + w;

            // CASE 1: better distance found
            if(nd < dist[v]){
                dist[v] = nd;
                paths[v] = paths[u] % MOD;
                minHops[v] = minHops[u] + 1;
                maxHops[v] = maxHops[u] + 1;

                pq.push({dist[v], v, minHops[v]});
            }

            // CASE 2: another shortest path found
            else if(nd == dist[v]){
                paths[v] = (paths[v] + paths[u]) % MOD;

                minHops[v] = min(minHops[v], minHops[u] + 1);
                maxHops[v] = max(maxHops[v], maxHops[u] + 1);

                // still push because need to propagate the hop DP - no
                // pq.push({dist[v], v, minHops[u] + 1});
            }
        }
    }
}

int main(){
    cin >> n >> m;

    adj.assign(n, {});
    for(int i = 0; i < m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u-1].push_back({v-1, w});
    }

    dist.assign(n, INF);
    paths.assign(n, 0);
    minHops.assign(n, INT_MAX);
    maxHops.assign(n, 0);

    performDijkstra();

    cout << dist[n-1] << " " << paths[n-1] << " " << minHops[n-1] << " " << maxHops[n-1] << "\n";

    return 0;
}
