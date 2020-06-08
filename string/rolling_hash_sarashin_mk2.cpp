#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,n) for(ll i=0;i<(n);++i)
#define REPR(i,n) for(ll i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

template<typename T>
void print(const vector<T> &x) {
    int n = x.size();
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x) {
    int n = x.size();
    rep(i,n) {
        rep(j,x[i].size()) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void print(const vector<T> &x, int n) {
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(const vector<vector<T>> &x, int n, int m) {
    rep(i,n) {
        rep(j,m) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void input_init() {
    cin.tie(0); ios::sync_with_stdio(false);
}

// below
typedef long long unsigned int ul;
typedef __int128_t lll;
class rolling_hash {
private:
    vector<lll> hash, power;
    lll base = 1e9+7;
    string s;
    const lll mod = (1ull << 61)-1;
    const lll positiviser = mod*10;
public:
    rolling_hash(const string &s);
    lll mul(lll a, lll b);
    lll get(int l, int r);
    ul change(int i, char chg);
    ~rolling_hash();
};

lll rolling_hash::mul(lll a, lll b) {
    lll t = a*b;
    t = (t>>61) + (t & mod);
    if (t >= mod) return t-mod;
    return t;
};


// 半開区間: [l, r)
lll rolling_hash::get(int l, int r) {
    lll ret = hash[r]+positiviser - mul(power[r-l],hash[l]);
    ret = (ret >> 61) + (ret&mod);
    return ret;
};

// 
ul rolling_hash::change(int idx, char chg) {
    int sz = s.length();
    char cur = s[idx];
    int diff = chg-cur;
    lll al_hash = hash[sz];
    if (diff >= 0) {
        ul d = (ul)diff;
        al_hash = al_hash+(power[sz-idx-1]*d);
    }
    else {
        ul d = (ul)abs(diff);
        al_hash = al_hash-(power[sz-idx-1]*d);
    }
    return al_hash%mod;
};

rolling_hash::rolling_hash(const string &s) {
    int n = (int)s.size();
    this->s = s;
    hash.assign(n+1,0);
    power.assign(n+1,1);
    for (int i = 0; i < n; ++i) {
        hash[i+1] = mul(hash[i],base)+s[i];
        power[i+1] = mul(power[i],base);
        if (hash[i+1] >= mod) hash[i+1] -= mod;
        if (power[i+1] >= mod) hash[i+1] -= mod;
    }
};


rolling_hash::~rolling_hash() {};
// above

int main(int argc, char const *argv[]) {
    string s,t; cin>>s>>t;
    int n = s.length(); int m = t.length();

    rolling_hash rs(s), rt(t);
    ll hst = rt.get(0,m);

    rep(i,n-m+1) {
        ll hss = rs.get(i, i+m);
        if (hss == hst) {
            cout << i << '\n';
        }
    }
    return 0;
}