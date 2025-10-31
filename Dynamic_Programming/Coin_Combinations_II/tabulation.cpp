#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> coins;
vector<vector<int>> dp;
int MOD = 1e9 + 7;

int solve(){
    // tabulation -
    for(int i = 1; i <= n; i++){
        for(int sum = 0; sum <= m; sum++){
            if(sum - coins[i-1] >= 0)
                dp[i][sum] = (dp[i][sum - coins[i-1]] + dp[i-1][sum])%MOD;
            else
                dp[i][sum] = dp[i-1][sum];
        }
    }
    return dp[n][m];
}


int main(){
    cin >> n >> m;
    coins = vector<int>();

    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        coins.push_back(x);
    }

    dp = vector<vector<int>>(n+1, vector<int>(m+1,0));
    // base cases -
    // 1. for sum = 0, the answers should be 1 -> no coins
    for(int i = 0; i<= n; i++)
        dp[i][0] = 1;
    // 2. for coins = {}, the answers should be 0
    // for(int i = 0; i<= m; i++)
    //     dp[0][i] = 0;
    // dp[0][0] = 1;

    int ans = solve();
    
    cout << ans << endl;

    return 0;
}