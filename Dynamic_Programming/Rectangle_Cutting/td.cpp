#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(int a, int b){
    if(a == b) return 0;
    if(dp[a][b] != -1) return dp[a][b];

    int ans = INT_MAX;
    for(int k = 1; k < a; k++){
        ans = min({ans, 1 + solve(a-k,b) + solve(k,b)});
    }

    for(int k = 1; k < b; k++){
        ans = min({ans, 1 + solve(a,b-k) + solve(a,k)});
    }

    return dp[a][b] = ans;
}

int main(){
    int a, b;
    cin >> a >> b;

    dp = vector<vector<int>>(a+1, vector<int>(b+1, -1));
    int ans = solve(a,b);
    cout << ans << endl;

    return 0;
}