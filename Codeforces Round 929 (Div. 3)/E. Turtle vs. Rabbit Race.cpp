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
        ll n;
        cin >> n;
        vl a(n, 0);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        ll q;
        cin >> q;

        for (int i = 0; i < q; i++){
            ll l, u;
            cin >> l >> u;
            ll r = l;
            ll secs = 0;
            ll ps = INT_MIN;
            bool o = false;
            do {
                secs += a[r-1];
                if (secs == u || secs == u+1){
                    cout << r << ' ';
                    o = true;
                    continue;
                }
                int cs = (secs <= u ? u-secs : secs-u-1) * -1;
                if (ps > cs){
                    cout << r-1 << ' ';
                    o = true;
                    continue;
                }
            } while (r <= n);
            if (!o){
                cout << n << ' ';
            }
        } cout << '\n';
    }
    return 0;
}