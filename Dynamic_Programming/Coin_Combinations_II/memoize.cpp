#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> coins;
vector<vector<int>> dp;
int MOD = 1e9 + 7;

int solve(int i, int sum){
    if(sum == 0){
        return 1;
    }
    if(sum < 0){
        return 0;
    }
    if(i == n) // imagine this case as no coins !
        return sum == 0 ? 1 : 0;

    if(dp[i][sum] != -1) return dp[i][sum];

    int take = 0;
    if(sum - coins[i] >= 0){
        take= (take + solve(i,sum-coins[i]))%MOD;
    }
    int notTake = 0;
    notTake= (notTake + solve(i+1,sum))%MOD;

    return dp[i][sum] = (take + notTake )%MOD;
}


int main(){
    cin >> n >> m;
    coins = vector<int>();

    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        coins.push_back(x);
    }

    dp = vector<vector<int>>(n+1, vector<int>(m+1,-1));
    int ans = solve(0,m);
    
    cout << ans << endl;

    return 0;
}