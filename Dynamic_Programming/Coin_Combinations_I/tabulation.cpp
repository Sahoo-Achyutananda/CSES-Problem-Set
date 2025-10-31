#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> coins;
vector<int> dp;
int MOD = 1e9 + 7;

int solve(){
    for(int sum = 1; sum <= m; sum++){
        for(auto coin : coins){
            if(sum - coin >= 0){
                dp[sum] =( dp[sum] + dp[sum - coin])%MOD;
            }
        }
    }

    return dp[m];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        coins.push_back(x);
    }
    dp = vector<int>(m+1,0);
    dp[0] = 1;
    int ans = solve();
    cout << ans << endl;

    return 0;
}