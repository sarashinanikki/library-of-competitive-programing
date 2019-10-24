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

class combM {
private:
    vector<ll> fac;  //n!(mod M)
    vector<ll> ifac; //k!^{M-2} (mod M)
public:
    ll mpow(ll x, ll n);
    combM();
    ll com(ll a, ll b);
};

// x^n(mod M)
ll combM::mpow(ll x, ll n) {
    ll ans = 1ll;
    while(n != 0){
        if (n&1) ans = ans*x%MOD;
        x = x*x%MOD;
        n = n >> 1;
    }
    return ans;
}

// aCb をmod計算
ll combM::com(ll a, ll b) {
    if (a == 0 && b == 0) return 1;
    if (a < b || a < 0) return 0;
    ll tmp = ifac[a-b]*ifac[b]%MOD;
    return tmp*fac[a]%MOD;
}

combM::combM() {
    fac.resize(300001);
    ifac.resize(300001);
    fac[0] = 1;
    ifac[0] = 1;
    for (ll i = 0; i < 300000; ++i) {
        fac[i+1] = fac[i]*(i+1)%MOD;
        ifac[i+1] = ifac[i]*mpow(i+1, MOD-2)%MOD;
    }
}

int main(int argc, char const *argv[]) {
    ll n, k;
    cin >> n >> k;
    combM C;
    ll ans = 0;
    ans = C.com(n, k);
    cout << ans << endl;
    return 0;
}
