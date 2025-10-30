#include<bits/stdc++.h>
using namespace std;

/* for n = 1 : 2
for n = 2 : 8

the dp equation is :
dp[i][0] = 4*dp[i-1][0] + dp[i-1][1];
dp[i][1] = 2*dp[i-1][1] + dp[i-1][0];

the 4LL trick is important for MOD ops
*/
int MOD = 1e9 + 7;
vector<vector<int>> dp(1000000,vector<int>(2));
vector<int> ans(1000000,0);

void solve(){

    dp[0][0] = 1;
    dp[0][1] = 1;

    dp[1][0] = 5;
    dp[1][1] = 3;

    ans[0] = 2;
    ans[1] = 8;

    for(int i = 2; i < 1000000; i++){
        dp[i][0] = ( (4LL * dp[i-1][0] + dp[i-1][1]) % MOD );
        dp[i][1] = ( (2LL * dp[i-1][1] + dp[i-1][0]) % MOD );
        ans[i] = (dp[i][0] + dp[i][1]) % MOD;
    }

}

int main(){

    int t;
    cin >> t;
    vector<int> tests;

    solve();
    while(t--){
        int n;
        cin >> n;
        tests.push_back(n);
    }

    for(auto test : tests){
        cout << ans[test-1] << endl;
    }

    return 0;
}