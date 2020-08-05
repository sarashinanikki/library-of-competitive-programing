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

// 1_indexed
class BIT {
private:
    int n;
    vector<ll> a;
public:
    BIT(int _n);
    void add(int idx, ll v);
    ll sum(int i);
    ll sum(int i, int j);
    ~BIT();
};

BIT::BIT(int _n) {
    n = _n;
    a.assign(n, 0ll);
}

void BIT::add(int idx, ll x) {
    while (idx <= n) {
        a[idx] += x;
        idx += (idx & -idx);
    }
}

ll BIT::sum(int i) {
    ll ret = 0;
    while (i > 0) {
        ret += a[i];
        i -= (i & -i);
    }
    return ret;
}

ll BIT::sum(int i, int j) {
    ll l = sum(i-1);
    ll r = sum(j);
    return r-l;
}

BIT::~BIT() {
}


int main(int argc, char const *argv[]) {
    
    return 0;
}