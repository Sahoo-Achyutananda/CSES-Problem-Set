#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> str1, str2;
vector<vector<int>> dp;

void generateDP(){
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= m ;j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max({dp[i-1][j], dp[i][j-1]});
            }
        }
    }   

    // for(int i = 0; i<= n; i++){
    //     for(int j = 0; j<=m;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[n][m] << endl;
}

void generateLCS(){
    int i = n;
    int j = m;

    vector<int> result;

    while(i > 0 && j > 0){
        // there can be only 3 cases
        // 1. the value of a cell = left-diagonal value + 1
        // 2. the value of a cell = left value -> we move left
        // 3. the value of a cell = top value - we move top
        if(dp[i-1][j-1] + 1 == dp[i][j] && str1[i-1] == str2[j-1]){
            result.push_back(str1[i-1]);
            i--;
            j--;
        }else{
            if(dp[i-1][j] >= dp[i][j-1]){
                // result.push_back(str1[i-1]);
                i--;
                continue;
            }
            
            if(dp[i][j-1] >= dp[i-1][j]){
                // result.push_back(str2[j-1]);
                j--;
                continue;
            }
        }
    }
    reverse(result.begin(), result.end());

    for(auto r : result){
        cout << r << " ";
    }
    cout << endl;
}

int main(){

    cin >> n >> m;
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        str1.push_back(x);
    }

    for(int i = 0; i< m; i++){
        int y;
        cin >> y;
        str2.push_back(y);
    }

    dp = vector<vector<int>>(n+1,vector<int>(m+1,0));

    generateDP();
    generateLCS();

    return 0;
}