#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int main() {
    vector<int> coins {1, 3, 6, 10, 15};
    int t; cin >> t;
    vector<int> ts(t);
    int mx = 0;
    for(int i = 0; i < t; i++){
        cin >> ts[i];
    }
    vector<int> tsc(ts);
    sort(ts.begin(), ts.end());

    vector<int> dp(16, INT_MAX);
    map<int, int> m;
    
    dp[0] = 0;
    for (int i = 1; i <= ts[t-1]; i++){

        for (auto x : coins){
            if (i - x >= 0){
                if (i > 15){
                    dp[15] = min(dp[i-x - (i-15)]+1, dp[15]);
                } else {
                    dp[i] = min(dp[i-x]+1, dp[i]);
                }
            }
        }
        if (binary_search(ts.begin(), ts.end(), i)){
            if (i >= 15)
                m[i] = dp[15];
            else {
                m[i] = dp[i];
            }
        }

        if (i < 15) continue;

        int t = dp[0];
        for (int i = 0; i < 15; i++){
            dp[i] = dp[i+1];
        }
        dp[15] = INT_MAX;
    } 
    for (auto x : tsc){
        cout << m[x] << '\n';
    }
    return 0;
}