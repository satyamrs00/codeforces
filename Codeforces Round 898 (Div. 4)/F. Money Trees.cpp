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
        ll n,k; cin >> n >> k;
        vl a(n), h(n);
        REP(i,0,n) cin >> a[i];
        REP(i,0,n) cin >> h[i];
        ll i = 0, j = -1, ans = 0, cur = 0;
        while(i < n && j+1 < n){
            double x;
            if (j >= 0) x = (double) h[j] / h[j+1];
            else x = 0;
            if (x == floor(x)){
                if (cur + a[j+1] <= k){
                    cur += a[++j];
                } else {
                    cur -= a[i]; i++; 
                }
            } else {
                i = j+1; j++; cur = a[i];
            }
            ans = max(ans, j-i+1);
        }
        cout << ans << '\n';
    }
}
