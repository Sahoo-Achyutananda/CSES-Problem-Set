// generated via GPT

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    // Filter out coins greater than m (not needed)
    coins.erase(remove_if(coins.begin(), coins.end(),
                          [&](int c){ return c > m; }),
                coins.end());

    vector<int> dp(m + 1, 0);
    dp[0] = 1;

    for (int sum = 1; sum <= m; sum++) {
        long long ways = 0; // local accumulator
        for (int c : coins) {
            if (sum >= c) {
                ways += dp[sum - c];
                if (ways >= MOD) ways -= MOD; // faster than %
            }
        }
        dp[sum] = (int)ways;
    }

    cout << dp[m] << '\n';
    return 0;
}
