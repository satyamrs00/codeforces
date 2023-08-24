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
        vector<int> v(n);
        REP(i,0,n) cin >> v[i];
        if (v[0] != n) {
            cout << "NO\n"; continue;
        }
        vector<int> vv(n, 0);
        for (int i = 0; i < n; i++){
            vv[v[i]-1]++;
        }
        bool flag = false;
        // REP(i,0,n) cout << v[i] << ' ';
        // cout << '\n';
        // REP(i,0,n) cout << vv[i] << ' ';
        // cout << '\n';
        if (vv[n-1] != v[n-1]) {
            cout << "NO\n"; continue;
        }
        REP(i,1,n) {
            vv[n-i-1] = vv[n-i-1+1] + vv[n-i-1];
            if (v[n-i-1] != vv[n-i-1]){
                flag = true;
                cout << "NO\n"; break;
            }
        }
        if (!flag) cout << "YES\n";
    }
}

// ac