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

// 削除はできない
template<class T>
class Kth_num {
private:
    priority_queue<T> former;
    int k;
public:
    ll former_sum = 0, latter_sum = 0;
    Kth_num(int k, vector<T>);
    void add(T x);
    T get();
    int size();
    ~Kth_num();
};

template<class T>
Kth_num<T>::Kth_num(int _k, vector<T> sequence) {
    k = _k;
    rep(i,k) former.push(sequence[i]);
}

// pair(former, latter)
template<class T>
int Kth_num<T>::size() {
    return former.size();
}

// add a number into data structure
template<class T>
void Kth_num<T>::add(T x) {
    // どちらに入る？
    if (former.empty()) {
        former.push(x);
        // former_sum += x;
    }
    else {
        T former_top = former.top();
        if (x < former_top) {
            former.pop();
            former.push(x);
            // latter_sum += x;
        }
    }
}

// get the median
template<class T>
T Kth_num<T>::get() {
    return former.top();
}

template<class T>
Kth_num<T>::~Kth_num() {
}

int main(int argc, char const *argv[]) {
    
    return 0;
}