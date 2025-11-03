#include<bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
int n,m;
vector<vector<long long>> edges;
vector<vector<pair<int,long long>>> adj;
vector<long long> dist;
vector<int> parent;
vector<int> affected;

int cycleStart, cycleEnd;
void performBellman(){
    dist[0] = 0;

    for(int i = 0; i< n-1; i++){
        for(auto e : edges){
            int u = e[0], v = e[1], d = e[2];
            if(dist[v] > dist[u] + d){
                dist[v] = dist[u] + d;
                parent[v] = u;
            }
        }
    }

    for(auto e : edges){
        int u = e[0], v = e[1], d = e[2];
        if(dist[v] > dist[u] + d){
            parent[v] = u;
            affected.push_back(v);
        }
    }
}

void detectCycle(){
    if(affected.size() == 0){
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    int source = affected.back(); 
    // important step -
    for(int i = 0; i< n; i++) source = parent[source];
    //
    // vector<int> cycle;

    // Reconstruct cycle
    vector<int> cycle;
    int node = source;
    // while(true){
    //     cycle.push_back(node);
    //     node = parent[node];
    //     if(node == source || node == -1) break;
    // }

    // cycle.push_back(source);
    // reverse(cycle.begin(), cycle.end());

    // for(auto node : cycle)
    //     cout << node + 1 << " ";
    // cout << endl;

    do{
        cycle.push_back(node);
        node = parent[node];
    }while(node != source && node != -1);

    // while(true){
    //     cycle.push_back(node);
    //     node = parent[node];
    //     if(node == source || node == -1) break;
    // }

    // for (int v = source;; v = parent[v]) {
    //     cycle.push_back(v);
    //     if (v == source && cycle.size() > 1) break;
    // }
    
    cycle.push_back(source);
    reverse(cycle.begin(), cycle.end());
    
    for(auto node : cycle){
        cout << node + 1 << " ";
    }
    cout << endl;

}

int main(){

    cin >> n >> m;

    adj = vector<vector<pair<int,long long>>>(n);
    for(int i = 0; i< m; i++){
        long long a,b,c;
        cin >> a >> b >> c;
        edges.push_back({a-1,b-1,c});
        adj[a-1].push_back({b-1,c});
    }
    dist = vector<long long>(n,0);
    parent = vector<int>(n,-1);

    performBellman();
    detectCycle();

    return 0;
}