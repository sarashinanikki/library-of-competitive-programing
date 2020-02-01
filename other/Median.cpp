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

// 削除はできない
class Median {
private:
    priority_queue<ll> former;
    priority_queue<ll,vector<ll>,greater<ll>> latter;
public:
    ll former_sum = 0, latter_sum = 0;
    Median();
    void add(ll x);
    ll get();
    P sizes();
    ~Median();
};

Median::Median() {
}

// pair(former, latter)
P Median::sizes() {
    P ret = P((ll)former.size(), (ll)latter.size());
    return ret;
}

// add a number into data structure
void Median::add(ll x) {
    // どちらに入る？
    if (former.empty()) {
        former.push(x);
        former_sum += x;
    }
    else {
        ll former_top = former.top();
        if (former_top < x) {
            latter.push(x);
            latter_sum += x;
        }
        else {
            former.push(x);
            former_sum += x;
        }
    }

    // 数を合わせる
    // when latter has one more element
    if ((int)latter.size() == (int)former.size()+1) {
        ll tmp = latter.top(); latter.pop();
        latter_sum -= tmp;
        former.push(tmp);
        former_sum += tmp;
    }
    // when former has two more elements
    else if ((int)(former.size()) == (int)latter.size()+2) {
        ll tmp = former.top(); former.pop();
        former_sum -= tmp;
        latter.push(tmp);
        latter_sum += tmp;
    }
    else if ((int)former.size() == (int)latter.size() || (int)former.size() == (int)latter.size()+1) {}
    else {
        assert(false);
        cout << "I don't consider this situation" << '\n';
        cout << "the size of former is " << former.size() << '\n';
        cout << "and the size of latter is " << latter.size() << '\n';
    }
}

// get the median
ll Median::get() {
    return former.top();
}

Median::~Median() {
}


int main(int argc, char const *argv[]) {
    
    return 0;
}