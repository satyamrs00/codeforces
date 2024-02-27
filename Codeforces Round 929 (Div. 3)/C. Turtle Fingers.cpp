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
        ll a, b, l;
        cin >> a >> b >> l;
        set<int> ans;
        for (int i = 0; i < (log10(l)/log10(a)) + 1; i++){
            for (int j = 0; j < (log10(l)/log10(b)) + 1; j++){
                double x = (double) l / (pow((double)a, i) * pow((double)b, j));
                ll xl = x;

                if (x == xl){
                    // cout << i << ' ' << j << '\n';
                    ans.insert(xl);
                }
            }
        }
        cout << ans.size() << '\n';
    }
    return 0;
}