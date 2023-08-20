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
        ll n,w; cin >> n >> w;
        double ans = 0;

        vector<ll> ws (n,0); REP(i,0,n){ cin >> ws[i];}
        vector<ll> ps (n,0); REP(i,0,n){ cin >> ps[i];}

        set<pair<double, int>> s;
        REP(i,0,n){
            s.insert({((double) ps[i]/ws[i]) * -1, ws[i]});
            // cout << ((double) ps[i]/ws[i]) * -1 << ' ' << ws[i] << '\n';
        }
        auto it = s.begin();
        while(w > 0 && it != s.end()){
            if (it->second <= w){
                w -= it->second;
                ans += (it->second * it->first * -1);
                // cout << it->first * -1 << ' ' << it->second  << ' ';
                it++;
            } else {
                ans += w * it->first * -1;
                // cout << w * it->first * -1 << ' ';
                w = 0;
            }
        }
        cout << ans << '\n';
    }
}

// ac