#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> sl;
typedef map<string, ll> msl;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
typedef pair<string, ll> psl;
typedef pair<ll, ll> pll;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(NULL)
#define PB push_back
#define F first 
#define S second
#define I iterator
#define REP(i,a,b) for (ll i = a; i < b; i++)
#define REPR(i,a,b) for (ll i = a; i > b; i--)
#define REPJ(i,a,b,j) for (ll i = a; i < b; i+=j)
#define REPIT(it,o) for (auto it = o.begin(); it != o.end(); it++)
#define REPITR(it,o) for (auto it = o.rbegin(); it != o.rend(); it++)
#define ALL(a) a.begin(),a.end()
#define ALLR(a) a.rbegin(),a.rend()

int main() {
    fastio();
    ll t = 1;
    while(t--){
        ll n,m; cin >> n >> m;
        vector<vector<ll>> grid(n,vector<ll> (m,0));
        REP(i,0,n){
            REP(j,0,m){
                cin >> grid[i][j];
            }
        }
        vector<vector<ll>>dp (n,vector<ll> (m,0));
        vector<vector<vector<pair<ll,ll>>>> dpp (n, vector<vector<pair<ll,ll>>> (m, vector<pair<ll,ll>> (0)));

        dp[0][0] = grid[0][0];
        dpp[0][0] = {{0,0}};

        ll mi = -1, mv = INT_MIN;

        // for (int i = 0, j = 0; i < n-1 && j < m; i++){
        //     if (i+1 < n){
        //         dp[i+1][j] = grid[i+1][j] + dp[i][j];
        //         dpp[i+1][j] = dpp[i][j];
        //         dpp[i+1][j].push_back({i+1,j});
        //         if (j+1 < m){
        //             dp[i+1][j+1] = grid[i+1][j+1] + dp[i][j];
        //             dpp[i+1][j+1] = dpp[i][j];
        //             dpp[i+1][j+1].push_back({i+1,j+1});
        //         }
        //     }
        //     if (i == n-2){
        //         if (dp[i+1][j] > mv){
        //             mv = dp[i+1][j]; mi = j;
        //         }
        //         if (j+1 < m && dp[i+1][j+1] > mv){
        //             mv = dp[i+1][j+1]; mi = j+1;
        //         }
        //     }
        //     j++;
        // }
        for (int i = 1; i < n; i++){
            for (int j = 0; j <= i && j < m; j++){
                if (j-1 >= 0){
                    if (dp[i-1][j-1] + grid[i][j] > dp[i][j]){
                        dp[i][j] = dp[i-1][j-1] + grid[i][j];
                        dpp[i][j] = dpp[i-1][j-1];
                        dpp[i][j].push_back({i,j});
                    }
                }
                if (j < i){
                    if (dp[i-1][j] + grid[i][j] > dp[i][j]){
                        dp[i][j] = dp[i-1][j] + grid[i][j];
                        dpp[i][j] = dpp[i-1][j];
                        dpp[i][j].push_back({i,j});
                    }
                }

                if (j+1 < m && j < i-1){
                    if (dp[i-1][j+1] + grid[i][j] > dp[i][j]){
                        dp[i][j] = dp[i-1][j+1] + grid[i][j];
                        dpp[i][j] = dpp[i-1][j+1];
                        dpp[i][j].push_back({i,j});
                    }
                }
                if (i == n-1){
                    if (dp[i][j] > mv){
                        mv = dp[i][j]; mi = j;
                    }
                }
            }
        }
        ll ans = mv;
        // cout << mv << ' ' << mi << ' ';
        for (auto x : dpp[n-1][mi]){
            grid[x.first][x.second] = 0;
        }




        REP(i,0,n){
            REP(j,0,m){
                dp[i][j] = 0;
                dpp[i][j] = vector<pair<ll,ll>> (0);
            }
        }
        mi = -1; mv = INT_MIN;
        dp[0][m-1] = grid[0][m-1];

        // cout << 's';

        // for (int i = 0, j = m-1; i < n-1 && j >= 0; i++){
        //     if (i+1 < n){
        //         dp[i+1][j] = grid[i+1][j] + dp[i][j];
        //         if (j-1 >= 0){
        //             dp[i+1][j-1] = grid[i+1][j-1] + dp[i][j];
        //         }
        //     }
        //     if (i == n-2){
        //         if (dp[i+1][j] > mv){
        //             mv = dp[i+1][j]; mi = j;
        //         }
        //         if (j-1 >= 0 && dp[i+1][j-1] > mv){
        //             mv = dp[i+1][j-1]; mi = j-1;
        //         }
        //     }
        //     // cout << i << ' ';
        //     j--;
        // }
        // REP(i,0,n){
        //     REP(j,0,m){
        //         cout << dp[i][j] << ' ';
        //     } cout << '\n';
        // } cout << '\n';
        // cout << 'k';
        for (int i = 1; i < n; i++){
            for (int j = m-i-1; j < m; j++){
                if (j < 0) continue;
                if (j-1 >= 0 && dp[i-1][j-1] + grid[i][j] > dp[i][j] && j > m-i-1-1){
                    dp[i][j] = dp[i-1][j-1] + grid[i][j];
                }
                if (dp[i-1][j] + grid[i][j] > dp[i][j] && j > m-i-1){
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
                if (j+1 < m && dp[i-1][j+1] + grid[i][j] > dp[i][j]){
                    dp[i][j] = dp[i-1][j+1] + grid[i][j];
                }
                if (i == n-1){
                    if (dp[i][j] > mv){
                        mv = dp[i][j]; mi = j;
                    }
                }
                // cout << j << ' ';
            }
            // cout << "\n" << i << ' ';
        }
        ans += mv;
        // REP(i,0,n){
        //     REP(j,0,m){
        //         cout << grid[i][j] << ' ';
        //     } cout << '\n';
        // }
        // cout << '\n';
        // REP(i,0,n){
        //     REP(j,0,m){
        //         cout << dp[i][j] << ' ';
        //     } cout << '\n';
        // }

        cout << ans << '\n';
        
    }
}

// ac