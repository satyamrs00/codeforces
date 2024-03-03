#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> v(2);
        for (int i = 0; i < 2; i++) {
            cin >> v[i];
        }
        vector<pair<string, int>> dp (n);
        dp[0] = make_pair(v[0][0], 1);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                } else {
                    if (i-1 >= 0 && j-1 >= 0){
                        if (dp[j].first > dp[j-1].first){
                            dp[j] = {dp[j-1].first + v[i][j], dp[j-1].second};
                        } else if (dp[j].first < dp[j-1].first){
                            dp[j] = {dp[j].first + v[i][j], dp[j].second};
                        } else {
                            dp[j] = {dp[j].first + v[i][j], dp[j].second + dp[j-1].second};
                        }
                    } else if (i-1 >= 0) {
                        dp[j] = {dp[j].first + v[i][j], dp[j].second};
                    } else if (j-1 >= 0) {
                        dp[j] = {dp[j-1].first + v[i][j], dp[j-1].second};
                    }
                }
            }
        }
        cout << dp.back().first << '\n' << dp.back().second << '\n';
    }
    return 0;
}