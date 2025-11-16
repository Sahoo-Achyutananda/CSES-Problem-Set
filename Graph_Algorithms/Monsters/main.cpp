#include<bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    vector<string> mp;
    for(int i = 0; i< n; i++){
        string str;
        cin >> str;
        mp.push_back(str);
    }

    vector<vector<int>> monster_time(n,vector<int>(m,INT_MAX));
    

    queue<pair<int,pair<int,int>>> q;
    for(int i = 0 ;i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] == 'M'){
                q.push({0,{i,j}});
                monster_time[i][j] = 0;
            }
        }
    }

    vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<char> dir = {'D','R','U','L'};

    while(!q.empty()){
        auto [t,p] = q.front();
        auto [x,y] = p;
        q.pop();

        for(auto d : dirs){
            int nx = d[0] + x;
            int ny = d[1] + y;

            if(nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
            if(mp[nx][ny] == '#') continue;
            if(t+1 >= monster_time[nx][ny]) continue; // this is important else loop mei atkega

            monster_time[nx][ny] = t + 1;
            q.push({t+1,{nx,ny}});
        }
    }

    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    vector<vector<int>> visited(n,vector<int>(m,0));
    vector<vector<int>> parent(n,vector<int>(m,-1));
    while(!q.empty()) q.pop();
    pair<int,int> start;
    for(int i = 0 ;i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] == 'A'){
                q.push({0,{i,j}});
                start = {i,j};
                visited[i][j] = 1;
            }
        }
    }

    pair<int,int> exit ={-1,-1};
    bool escaped = false;
    while(!q.empty()){
        auto [t,p] = q.front();
        auto [x,y] = p;
        q.pop();

        if(x == 0 || y == 0 || x == n-1 || y == m - 1){
            exit = {x,y};
            escaped = true;
            break;
        }

        for(int d = 0; d < 4; d++){
            int nx = dirs[d][0] + x;
            int ny = dirs[d][1] + y;

            if(nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
            if(mp[nx][ny] == '#') continue;
            if(visited[nx][ny]) continue;
            if(t + 1 >= monster_time[nx][ny]) continue;

            dist[nx][ny] = t + 1;
            visited[nx][ny] = 1;
            parent[nx][ny] = d;
            q.push({t+1,{nx,ny}});
        }
    }

    if(escaped){
        cout << "YES" << '\n';
        string path = "";
        pair<int,int> curr = exit;
        while(curr != start){
            int d = parent[curr.first][curr.second];
            char di = dir[d];
            path.push_back(di);
            curr = {curr.first - dirs[d][0], curr.second - dirs[d][1]};
        }
        reverse(path.begin(),path.end());
        cout << path.length() << '\n';
        cout << path << '\n';

    }else{
        cout << "NO" << '\n';
    }



    return 0;
}