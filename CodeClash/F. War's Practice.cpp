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

bool isPrime(ll n){
    if (n < 4) return true;
    for (int x = n/2+1; x > 1; x--){
        if (n%x == 0) return false;
    }
    return true;
}

int main() {
    fastio();
    ll t = 1;
    while(t--){
        ll n,m,s; cin >> n >> m >> s;
        vector<vector<ll>> grid(n,vector<ll> (m,0));
        REP(i,0,n){
            REP(j,0,m){
                cin >> grid[i][j];
            }
        }
        vector<vector<ll>> as (s, vector<ll> (4,0));
        REP(i,0,s){
            REP(j,0,4){
                cin >> as[i][j];
            }
        }

        for (int c = 0; c < s; c++){
            int score = 0;
            for (int i = as[c][0]-1; i <= as[c][2]-1; i++){
                for (int j = as[c][1]-1; j <= as[c][3]-1; j++){
                    if (isPrime(i+j+2)) score += grid[i][j] * (i+j+2);
                    else score += grid[i][j];
                }
            }
            cout << score << '\n';
        }
    }
}

// ac