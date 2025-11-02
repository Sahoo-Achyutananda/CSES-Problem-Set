#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adj;
vector<int> visited, parent;

vector<vector<int>> cycles;

// int cycleStart = -1;
// int cycleEnd = -1;

void dfs(int u, int par){
    visited[u] = 1;
    for(auto v : adj[u]){
        // this line is important
        if(v == par) continue;

        if(!visited[v]){
            parent[v] = u;
            dfs(v,u);
        }else{
            cycles.push_back({v,u});
        }
    }
}

void solve(){

    for(int i = 0; i< n; i++){
        if(!visited[i]){
            dfs(i,-1);
        }
    }

    // printing cycle
    if(cycles.size() == 0){
        cout << "IMPOSSIBLE" << endl;
    }else{
        // printing only the first cycle -
        auto cycle = cycles[0];
        int v = cycle[0];
        int u = cycle[1];
        
        vector<int> cycleNodes;
        cycleNodes.push_back(v);
        int node = u;
        while(node != v && node != -1){
            cycleNodes.push_back(node);
            node = parent[node];
        }
        cycleNodes.push_back(v);

        cout << cycleNodes.size() << endl;
        reverse(cycleNodes.begin(), cycleNodes.end());
        for(auto node : cycleNodes)
            cout << node + 1 << " ";
        cout << endl;


    }
}

int main(){

    cin >> n >> m;
    adj = vector<vector<int>>(n);

    for(int i = 0; i< m; i++){
        int a,b;
        cin >> a >> b;

        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    visited = vector<int>(n,0);
    parent = vector<int>(n,-1);

    solve();

    return 0;
}