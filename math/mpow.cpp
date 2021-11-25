#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;

// x^n(mod M)
ll mpow(ll x, ll n) {
    ll ans = 1ll;
    while(n != 0) {
        if (n&1) ans = ((ans%MOD)*(x%MOD))%MOD;
        x = ((x%MOD)*(x%MOD))%MOD;
        n = n >> 1;
    }
    return ans;
}