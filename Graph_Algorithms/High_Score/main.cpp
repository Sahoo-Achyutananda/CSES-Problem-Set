#include<bits/stdc++.h>
using namespace std;

long long m,n;
vector<vector<pair<long long,long long>>> adj;
vector<tuple<long long,long long,long long>> edges;
vector<long long> dist;
long long NEG_INF = -1e18;

void solve(){
    dist[0] = 0;

    for(long long i = 0; i <n-1 ;i ++){
        for(auto [u,v,d] : edges){
            if(dist[u] == NEG_INF)continue;
            if(dist[v] < dist[u] + d){
                dist[v] = dist[u] + d;
            }
        }
    }

    

    // the destination is not necessarily a part of a positive weight cycle ->
    // in this case the output must be valid 

    // getting the affected edges -
    queue<long long> q;
    vector<bool>affected(n,false);
    for(auto [u,v,d] : edges){
        if(dist[u] !=NEG_INF && dist[v] < dist[u] + d){
            affected[v] = true;
            q.push(v);
        }
    }

    while(!q.empty()){
        long long u = q.front();
        q.pop();

        for(auto [v,d] : adj[u]){
            if(!affected[v]){
                affected[v] = 1;
                q.push(v);
            }
        }
    }
    
    if(affected[n-1]){
        cout << -1 << endl;
    }else
        cout << dist[n-1] << endl;
} 

int main(){
    cin >> n >> m;
    edges = vector<tuple<long long,long long,long long>>();
    adj = vector<vector<pair<long long,long long>>>(n);
    dist = vector<long long>(n,NEG_INF);
    for(long long i = 0; i< m; i++){
        long long a,b, c;
        cin >> a >> b >> c;
        edges.push_back({a-1,b-1, c});
        adj[a-1].push_back({b-1,c});
    }

    solve();

    return 0;
}