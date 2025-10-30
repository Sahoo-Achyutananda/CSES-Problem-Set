#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> coins;
vector<vector<int>> dp;

void solve(){
    for(int i = 1;i <= n; i++){
        for(int sum = 1; sum <= m ;sum++){
            if(sum - coins[i-1] >= 0)
                dp[i][sum] = min({1+dp[i][sum-coins[i-1]], dp[i-1][sum]});
            else
                dp[i][sum] = dp[i-1][sum];
        }
    }
}

int main(){

    cin >> n >> m;
    for(int i = 0; i< n; i++){
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    dp = vector<vector<int>>(n+1,vector<int>(m+1,1e9));
    for(int i = 0; i<=n; i++) dp[i][0] = 0;
    solve();

    // for(int i = 0; i<= n; i++){
    //     for(int j = 0; j<= m; j++){
    //         cout  << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << (dp[n][m] >= 1e9 ? -1: dp[n][m]) << endl;

    return 0;
}