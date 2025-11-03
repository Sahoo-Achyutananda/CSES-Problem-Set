#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> edges;
vector<vector<int>> adj;
vector<int> visited;

void dfs(int u){
    visited[u] = 1;
    for(auto v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}

void solve(){
    vector<int> representative;
    for(int u = 0; u < n; u++){
        if(!visited[u]){
            dfs(u);
            representative.push_back(u);
        }
    }

    int x = representative.size();
    cout << x - 1 << endl;
    for(int i = 1; i < x; i++){
        cout << representative[i-1] + 1 << " " << representative[i] + 1 << endl;
    }
}

int main(){
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    for(int i = 0; i< m; i++){
        int a,b;
        cin >> a >> b;
        edges.push_back({a-1,b-1});
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    visited = vector<int>(n,0);

    solve();

    return 0;
}