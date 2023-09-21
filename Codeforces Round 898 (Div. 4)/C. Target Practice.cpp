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
        vector<string> g(10);
        ll ans = 0;
        REP(i,0,10){
            cin >> g[i];
            REP(j,0,10){
                if (g[i][j] == 'X'){
                    if (i < 5){
                        if (j >= i && j <= 10-i-1){
                            ans += i + 1;
                        }
                    } else if (i >= 5){
                        if (j >= 10-i-1 && j <= i){
                            ans += 10-i-1 + 1;
                        }
                    }
                    if (j < 5){
                        if (j < i && j < 10-i-1){
                            ans += j + 1;
                        }
                    } else if (j >= 5){
                        if (j > i && j > 10-i-1){
                            ans += 10-j-1 + 1;
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}
