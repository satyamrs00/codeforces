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
        ll n,a,b; cin >> n >> a >> b;
        vector<vector<ll>> g(n+1, vector<ll> (0));
        REP(i,0,n) {
            ll x,y; cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if (a == b) {
            cout << "NO\n"; continue;
        }
        vl v (n+1,0);
        stack<tuple<ll, bool, ll>> s; // bool - if b is in the path, ll - prev
        s.push({a,false, -1});
        bool f = true;
        while(!s.empty()){
            ll x, p; bool bo; tie(x,bo, p) = s.top(); s.pop();
            v[x] = 1;
            for (auto k : g[x]){
                if (k == p) continue;
                if (v[k] == 1) {
                    if (bo){
                        f = false;
                        cout << "YES\n"; 
                    }
                    s=stack<tuple<ll,bool,ll>>();
                    break;
                }
                if (v[k] == 0){
                    s.push({k,bo || (k == b), x});
                }
            }
        }
        if (f) cout << "NO\n";
    }
}
