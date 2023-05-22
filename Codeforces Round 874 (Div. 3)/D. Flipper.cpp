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
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
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
        vl v;
        ll r = 1;
        ll val_at_r = 0;
        REP(i,0,n){
            ll tmp; cin >> tmp;
            if (i > 0 && tmp > val_at_r){
                val_at_r = tmp;
                if (i == n-1){
                    r=i+1;
                } else {
                    r = i;
                }
            }
            v.PB(tmp);
        }
        vl max_perm (n,0);
        REPR(l,r,0){
            vl perm (n,0);
            ll id = 0;
            REP(a,r,n){
                perm[id] = v[a];
                id++;
            }
            REPR(b,r-1,l-2){
                perm[id] = v[b];
                id++;
            }
            REP(c,0,l-1){
                perm[id] = v[c];
                id++;
            }
            REP(i,0,n){
                if (perm[i] > max_perm[i]) {
                    max_perm = perm;
                    break;
                } else if (perm[i] < max_perm[i]){
                    break;
                }
            }
        }
        REPIT(it,max_perm){
            cout << *it << " ";
        } cout << "\n";
    }
}

// ac