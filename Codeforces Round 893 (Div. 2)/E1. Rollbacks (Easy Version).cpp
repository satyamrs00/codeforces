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
    ll q; cin >> q;
    vector<map<string,ll>> versions;
    vector<string> v;
    while(q--){
        string s;
        getline(cin, s);
        if (s[0] == '+'){
            string val = s.substr(2, s.size()-2);
            v.push_back(val);
            if (versions.size()){
                map<string,ll> mx = versions[versions.size()-1];
                if (mx.count(val)) mx[val]++;
                else mx[val] = 1;
                versions.push_back(mx);
            } else {
                map<string,ll> mx;
                mx[val] = 1;
                versions.push_back(mx);
            }
        } else if (s[0] == '-'){
            string val = s.substr(2, s.size()-2);
            map<string,ll> m = versions[versions.size()-1];
            for (int i = 0; i < stoi(val); i++){
                if (m.count(v[v.size()-1]) == 1) m.erase(v[v.size()-1]);
                else m[v[v.size()-1]]--;
                v.pop_back();
            }
            versions.push_back(m);
        } else if (s[0] == '?'){
            cout << versions[versions.size()-1].size() << '\n';
        } else if (s[0] == '!'){
            versions.pop_back();
        }
    }
    return 0;
}

// ac