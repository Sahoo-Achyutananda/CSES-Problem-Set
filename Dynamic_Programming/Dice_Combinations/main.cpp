#include<bits/stdc++.h>
using namespace std;

// beware of out of bound errors - seg faults

int MOD = 1e9 + 7;
int n;

vector<long long> dp;

long long solve(int sum){
    if(sum < 0){
        return 0;
    }
    if(sum == 0){
        return 1;
    }

    if(dp[sum] != -1) return dp[sum];
    long long ans = 0;
    for(int i = 1; i<= 6; i++){
        ans= (ans + solve(sum-i))%MOD;
    }

    return dp[sum] = ans;
}

int main(){

    cin >> n;
    dp = vector<long long>(n+1,-1);
    int ans = solve(n);
    cout << ans << endl;
    return 0;
}