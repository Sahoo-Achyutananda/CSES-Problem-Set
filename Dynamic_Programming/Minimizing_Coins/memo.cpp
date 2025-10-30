#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> coins;
vector<vector<int>> dp;

int solve(int i, int sum){
    if(sum == 0) return 0;
    if(i == n)
        return 1e9; 
    
    if(dp[i][sum] != -1) return dp[i][sum];
    int take = 1e9, notTake = 1e9;
    if(sum - coins[i] >= 0)
        take = 1 + solve(i,sum-coins[i]);
    notTake = solve(i+1,sum);

    return dp[i][sum] = min(take,notTake);
}

int main(){

    cin >> n >> m;
    for(int i = 0; i< n; i++){
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    dp = vector<vector<int>>(n+1,vector<int>(m+1,-1));
    int ans = solve(0,m);
    cout << (ans >= 1e9 ? -1: ans) << endl;

    return 0;
}