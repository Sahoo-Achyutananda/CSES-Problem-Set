#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>>adj;
vector<int> indegree, visited;

void solve(){
    // find topological sort sequence
    queue<int> q; 
    vector<int> topo;
    for(int i = 0; i < n; i++)
        if(indegree[i] == 0){ 
            q.push(i);
            visited[i] = 1;
        }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto neigh : adj[node]){
            indegree[neigh]--;
            if(indegree[neigh] == 0){
                q.push(neigh);
                visited[neigh] = 1;
            }
        }
    }

    vector<int> dist(n,INT_MIN);
    vector<int> parent(n,-1);
    dist[0] = 0; // i wrote it as dist[topo[0]] = 0 before - it gave error
    // relax the edges based on the topo order
    for(auto node : topo){
        visited[node] = 1;
        for(auto neigh : adj[node]){
            // if(visited[neigh]) continue;
            if(dist[neigh] < dist[node] + 1){
                dist[neigh] = dist[node] + 1;
                parent[neigh] = node;
            }
        }
    }
    if(dist[n-1] < 0){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << dist[n-1] + 1 << endl;
    int node = n - 1;
    vector<int> path;
    while(parent[node] != -1){
        path.push_back(node + 1);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    for(auto p : path){
        cout << p << " ";
    }
    cout << endl;
    
}

int main(){

    cin >> n >> m;
    adj = vector<vector<int>>(n);
    indegree = vector<int>(n,0);
    visited = vector<int>(n,0);

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        indegree[b-1]++;
    }

    solve();

    return 0;
}