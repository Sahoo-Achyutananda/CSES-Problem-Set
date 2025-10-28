// Longest flight path
#include <bits/stdc++.h>
using namespace std;

// vector<vector<pair<int,int>>> adj;
vector<tuple<int,int,int>> edges;
vector<int> dist;
vector<int> parent;
vector<int> visited;

int n,m;

void solve(){
    for (int i = 0; i < n - 1; i++) {
        for (auto [u,v,wt] : edges){
            if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                parent[v] = u;
            }
        }
    }

    if (dist[n - 1] == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    // pq.push({0,0});

    // while(!pq.empty()){
    //     auto [d,u] = pq.top();
    //     pq.pop();

    //     if(visited[u]) continue;
    //     visited[u] = 1;

    //     for(auto v : adj[u]){
    //         if(visited[v]) continue;
    //         if(dist[v] > d - 1){
    //             dist[v] = d - 1;
    //             parent[v] = u;
    //             pq.push({d-1,v});
    //         }
    //     }
    // }

    cout << -dist[n-1] + 1 << endl;

    vector<int> path;
    int node = n-1;
    while(parent[node] != -1){
        path.push_back(node + 1);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    for(auto n : path){
        cout << n << " ";
    }
    cout << endl;
}

int main(){

    cin >> n >> m;

    // adj = vector<vector<pair<int,int>>>(n);
    edges = vector<tuple<int,int,int>>();
    for(int i = 0; i< m; i++){
        int a,b;
        cin >> a >> b;
        edges.push_back({a-1,b-1,-1});
    }

    visited = vector<int>(n,0);
    dist = vector<int>(n,INT_MAX);
    dist[0] = 0;
    parent = vector<int>(n,-1);
    
    solve();

    return 0;
}