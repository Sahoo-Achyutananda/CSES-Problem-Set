// Flight Routes

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<long long,long long>>> adj;
vector<vector<long long>> dist;
vector<long long> visited;
long long n,m,k;

void solve(){
    
    priority_queue<pair<long long,long long> , vector<pair<long long,long long>>, greater<>> pq;
    pq.push({0,0});
    dist[0].push_back(0);

    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();

        // if(visited[u]) continue;
        // if(dist[u].size() == k){
        //     visited[u] = 1;
        // }

        if (dist[u].size() == k && d > dist[u].back()) continue;

        for(auto [v,wt] : adj[u]){
            // if(visited[v]) continue;
            // relaxation -
            if(dist[v].size() < k){
                dist[v].push_back(d + wt);
                sort(dist[v].begin(), dist[v].end());
                pq.push({d+wt,v});
            }else if(dist[v].size() == k){
                if(dist[v].back() > d + wt){
                    dist[v].pop_back();
                    dist[v].push_back(d+wt);
                    sort(dist[v].begin(), dist[v].end());
                    pq.push({d+wt,v});
                }
            }
        }
    }

    for(auto d : dist[n-1]){
        cout << d << " ";
    }
    cout << endl;
}

int main(){

    cin >> n >> m >> k;

    adj = vector<vector<pair<long long,long long>>>(n);
    for(long long i = 0; i< m; i++){
        long long x,y,z;
        cin >> x >> y >> z;
        adj[x-1].push_back({y-1,z});
    }

    dist = vector<vector<long long>>(n);
    visited = vector<long long>(n,0);

    solve();

    // i have to revisit the cities to get the k shortest paths !
    // the logic to mark visited array will change
    // i'll mark it visited only if i have found all  k paths ? // but how will i ensure that i've found the k shortest paths and not just k paths
    // will the greedy picking work here ?
    // do i have to get all costs and sort it ?
    // won't the time complexity be V*V ?

    // visited is not required !
    // is sorting required ? -> yes coz it is not guarateed that we'll visit from the shortest path forst







    return 0;
}