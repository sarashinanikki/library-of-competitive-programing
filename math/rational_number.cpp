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

class rational_number {
private:
    ll c,p;
    ll gcd(ll a, ll b);
    ll lcm(ll a, ll b);
    rational_number format(rational_number x);

public:
    rational_number(){}
    rational_number(ll c, ll p);

    rational_number &operator*=(const rational_number x) {
        c *= x.c; p *= x.p;
        *this = format(*this);
        if (c > 0 && p < 0) {
            c *= -1;
            p *= -1;
        }
    }

    rational_number &operator*=(const ll x) {
        c *= x;
        *this = format(*this);
        if (c > 0 && p < 0) {
            c *= -1;
            p *= -1;
        }
    }
    ~rational_number();
};

rational_number::rational_number(ll c, ll p) {
    if (p==0) {
        cout << "0除算" << '\n';
    }
    this->c = c; this->p = p;
    if (c >= 0 && p < 0) {
        p*=-1;
        c*=-1;
    }
    *this = format(*this);
}

ll rational_number::gcd(ll a, ll b) {
    if (a % b == 0) return b;
    gcd(b, a % b);
}

ll rational_number::lcm(ll a, ll b) {
    ll ans = a * b / gcd(a, b);
    return ans;
}

rational_number rational_number::format(rational_number x) {
    ll GCD = gcd(x.c, x.p);
    x.c /= GCD; x.p /= GCD;
    return x;
}

rational_number::~rational_number() {
}


int main(int argc, char const *argv[]) {
    
    return 0;
}