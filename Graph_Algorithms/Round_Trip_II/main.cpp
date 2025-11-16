#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n, m;
vector<int> inStack;
vector<int> visited;
vector<int> parent;
int cs = -1, ce = -1;

bool dfs(int source, int par){
    visited[source] = 1;
    inStack[source] = 1;
    for(auto v : adj[source]){
        if(inStack[v]){
            cs = v;
            ce = source;
            return true;
        }else if(!visited[v]){
            parent[v] = source;
            if(dfs(v,source)) return true;
        }
    }

    inStack[source] = 0;
    return false;

}

int main(){
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    for(int i = 0; i < m;i++){
        int a,b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
    }
    inStack  = visited = vector<int>(n,0);
    parent = vector<int>(n,-1);
    for(int i = 0; i< n; i++){
        if(!visited[i]){
            if(dfs(i,-1)) break;
        }
    }

    if(ce == -1 && cs == -1){
        cout << "IMPOSSIBLE" << endl;
    }else{
        int node = ce;
        vector<int> res;
        res.push_back(cs);
        while(node!= cs){
            res.push_back(node);
            node = parent[node];
        }
        res.push_back(cs);
        reverse(res.begin(), res.end());

        cout << res.size() << endl;
        for(auto r : res){
            cout << r + 1 << " ";
        }
        cout << endl;

    }
    
    return 0;
}