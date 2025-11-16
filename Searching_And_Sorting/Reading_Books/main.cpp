#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<unsigned long long> time;
    for(int i = 0; i< n; i++){
        unsigned long long k;
        cin >> k;
        time.push_back(k);
    }

    unsigned long long maxi = *max_element(time.begin(), time.end());
    unsigned long long sum = accumulate(time.begin(), time.end(), 0ULL);

    unsigned long long ans = max(2*maxi,sum);

    cout << ans << endl;

    return 0;
}