#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> coins;
vector<int> dp;
int MOD = 1e9 + 7;

int solve(int sum){
    if(sum == 0) return 1;
    if(sum < 0) return 0;
    if(dp[sum] != -1) return dp[sum];

    int ans = 0;
    for(auto coin : coins){
        ans = (ans + solve(sum-coin))%MOD;
    }

    return dp[sum] = ans;
}

int main(){

    cin >> n >> m;
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        coins.push_back(x);
    }
    dp = vector<int>(m+1,-1);
    int ans = solve(m);
    cout << ans << endl;

    return 0;
}