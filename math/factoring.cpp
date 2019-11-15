// --------------以下ライブラリ---------------------------------//

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

void input_init() {
    cin.tie(0); ios::sync_with_stdio(false);
}
template <typename T>
class Erathostenes {
public:
    vector<T> primes;
    Erathostenes(T n);
    ~Erathostenes();
};

template<typename T>
Erathostenes<T>::Erathostenes(T n) {
    vector<bool> prime_flags(n+10, true);
    prime_flags[0] = prime_flags[1] = false;
    for (int i = 2; i*i <= n; ++i) {
        if (prime_flags[i]) {
            primes.push_back(i);
            for (int j = i; j <= n; j+=i) {
                prime_flags[j] = false;
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (prime_flags[i]) primes.push_back(i);
    }
}

template <typename T>
Erathostenes<T>::~Erathostenes() {}

template <typename T>
class Factoring: public Erathostenes<T> {
public:
    map<T, int> factors;
    Factoring(T n) : Erathostenes<T>(n) {}
    ~Factoring();
    void factoring(T n);
};

template <typename T>
void Factoring<T>::factoring(T n) {
    for (auto &&e: this->primes) {
        if (e > n) break;
        while(n%e == 0){
            factors[e]++;
            n /= e;
        }
    }
    factors[n]++;
    factors.erase(1);
}

template<typename T>
Factoring<T>::~Factoring() {}