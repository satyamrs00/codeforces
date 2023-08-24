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
        ll n,m; cin >> n >> m;
        vector<vector<char>> v(n,vector<char> (m));
        REP(i,0,n){
            REP(j,0,m){
                cin >> v[i][j];
            }
        }
        bool ans = false;
        char c = 'v';
        REP(i,0,m){
            REP(j,0,n){
                if (v[j][i] == c){
                    if (c == 'a'){
                        ans = true;
                        i = m; j = n;
                        break;
                    } else {
                        if (c == 'v') c = 'i';
                        else if (c == 'i') c = 'k';
                        else if (c == 'k') c = 'a';
                        break;
                    }
                }
            }
        }
        if (ans){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

// ac