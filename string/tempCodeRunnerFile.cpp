#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
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

// below

typedef long long unsigned int ul;
class Rolling_hash {
private:
    vector<ul> hash, power;
    ul base = MOD;
    const ul mod = (1ul << 61)-1;
    const ul mask30 = (1ul << 30)-1;
    const ul mask31 = (1ul << 31)-1;
    const ul POSITIVISER = mod*3;
public:
    Rolling_hash(const string &s);
    ul mul(ul a, ul b);
    ul calc_mod(ul x);
    ul get(int l, int r);
    ~Rolling_hash();
};

ul Rolling_hash::mul(ul a, ul b) {
    ul au = a>>31;
    ul bu = b>>31;
    ul ad = a&mask31;
    ul bd = b&mask31;
    ul mid = au*bd+ad*bu;
    ul midu = mid>>30;
    ul midd = mid&mask30;
    ul ret = (au*bu*2 + midu + (midd<<31) + ad*bd);
};

ul Rolling_hash::calc_mod(ul x) {
    x = (x&mod) + (x>>61);
    if (x>=mod) x-=mod;
    return x;
};


Rolling_hash::Rolling_hash(const string &s) {
    int n = (int)s.size();
    hash.assign(n+1,0);
    power.assign(n+1,1);
    for (int i = 0; i < n; ++i) {
        hash[i+1] = calc_mod(mul(hash[i],base)+s[i]);
        power[i+1] = calc_mod(mul(power[i],base));
    }
};

// 半開区間: [l, r)
ul Rolling_hash::get(int l, int r) {
    ul ret = calc_mod(hash[r]+POSITIVISER - mul(power[r-l],hash[l]));
    return ret;
}

Rolling_hash::~Rolling_hash() {};

// above

int main() {
    string s,t;
    cin>>s>>t;
    Rolling_hash a(s),b(t);
    int n = s.length(); int m = t.length();
    ul t_hash = b.get(0,m);
    rep(i,n-m+1) {
        ul s_hash = a.get(i,i+m);
        if (s_hash==t_hash) cout << i << endl;
    }
}