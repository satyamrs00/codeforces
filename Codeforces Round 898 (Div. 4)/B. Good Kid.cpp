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
        vl v(n);
        ll mn = INT_MAX;
        ll ans = 1, z = 0;
        REP(i,0,n) {
            cin >> v[i];
            if (v[i] == 0){
                z++;
            } else {
                ans *= v[i];
            }
            mn = min(mn, v[i]);
        }
        if (z == 1){
            cout << ans << '\n';
        } else if (z > 1){
            cout << 0 << '\n';
        } else {
            cout << (ans/mn) * (mn+1) << '\n';
        }

    }
}
