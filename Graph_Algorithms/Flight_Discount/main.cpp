#include<bits/stdc++.h>
using namespace std;

// we need to maintain a DP -> as we can take the discount on any flight path
// we use a take not take logic on every flight route once
// return the min of all
// i'll use dijistra's algo ?

unsigned long long n,m;
vector<vector<unsigned long long>> flights;
vector<vector<pair<unsigned long long,unsigned long long>>> adj;
vector<vector<unsigned long long>> dist;
vector<vector<unsigned long long>> visited;

unsigned long long solve(){
    // this queue will also track states - 
    priority_queue<tuple<unsigned long long,unsigned long long,unsigned long long>, vector<tuple<unsigned long long,unsigned long long,unsigned long long>>, greater<>> pq;
    pq.push({0,0,0});
    // pq.push({0,0,1});
    dist[0][0] = 0;
    // dist[0][1] = 0;
    // visited[0] = 1;

    while(!pq.empty()){
        auto [d,u, state] = pq.top();
        pq.pop();

        if(visited[u][state]) continue;
        visited[u][state] = 1;

        for(auto [v,wt] : adj[u]){
            if (state == 0){
                // no discount used yet
                if(dist[v][0] > dist[u][0] + wt){
                    dist[v][0] = dist[u][0] + wt;
                    pq.push({dist[v][0], v, 0});
                }
                // use discount on this edge
                if(dist[v][1] > dist[u][0] + wt/2){
                    dist[v][1] = dist[u][0] + wt/2;
                    pq.push({dist[v][1], v, 1});
                }
            }else{
                if(dist[v][1] > dist[u][1] + wt){
                    dist[v][1] = dist[u][1] + wt;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }

    return min({dist[n-1][0], dist[n-1][1]});
}

int main(){
    cin >> n >> m;
    for(unsigned long long i = 0; i < m ;i++){
        unsigned long long x, y, z;
        cin >> x >> y >> z;
        flights.push_back({x,y,z});
    }
    dist = vector<vector<unsigned long long>>(n,vector<unsigned long long>(2, ULLONG_MAX));
    adj = vector<vector<pair<unsigned long long,unsigned long long>>>(n,vector<pair<unsigned long long,unsigned long long>>());
    visited = vector<vector<unsigned long long>>(n,vector<unsigned long long>(2,0));

    for(unsigned long long i = 0; i < m; i++){
        adj[flights[i][0] - 1].push_back({flights[i][1]-1, flights[i][2]});
    }

    unsigned long long sol = solve();
    cout << sol << endl;

    return 0;
}