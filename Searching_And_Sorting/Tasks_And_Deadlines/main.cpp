#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<long long, long long>> tasks;
    for(int i = 0; i< n; i++){
        int a,b;
        cin >> a >> b;
        tasks.push_back({a,b});
    }

    sort(tasks.begin(), tasks.end());

    long long reward = 0;
    long long ftime = 0;
    for(int i = 0; i< n; i++){
        auto [du,d] = tasks[i];
        ftime = ftime + du;
        reward = reward + (d - ftime);
    }

    cout << reward << endl;

    return 0;
}