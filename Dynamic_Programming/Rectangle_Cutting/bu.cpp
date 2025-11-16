#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int main(){
    int a, b;
    cin >> a >> b;

    dp = vector<vector<int>>(a+1, vector<int>(b+1, INT_MAX));
    
    for(int i = 1; i<= a; i++){
        for(int j = 1; j <= b; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            for(int k = 1; k < i; k++){
                dp[i][j] = min({dp[i][j], 1 + dp[i-k][j] + dp[k][j]});
            }

            for(int k = 1; k < j; k++){
                dp[i][j] = min({dp[i][j], 1 + dp[i][j-k] + dp[i][k]});
            }
        }
    }

    cout << dp[a][b] << endl;

    return 0;
}