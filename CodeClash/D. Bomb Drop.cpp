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
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> v (n,0); REP(i,0,n){ cin >> v[i];}
        if (v.size() == 1) {
            cout << v[0] << '\n'; continue;
        } else if (v.size() == 2){
            cout << max(v[0],v[1]) << '\n'; continue;
        }
        vector<ll> dp (n, 1);
        dp[0] = v[0]; dp[1] = v[1];
        ll ans = INT_MIN;
        for (int i = 2; i < n; i++){
            for (int j = i-2; j >= 0; j--){
                dp[i] = max(dp[i], v[i] + dp[j]);
            }
            ans = max(ans,dp[i]);
        }
        ans = max(ans,dp[0]);
        ans = max(ans,dp[1]);
        
        cout << ans << '\n';
    }
}

// ac