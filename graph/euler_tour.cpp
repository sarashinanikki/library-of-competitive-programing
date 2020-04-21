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

class euler_tour {
public:
    int n;
    vector<int> vs;
    vector<int> reach;
    vector<int> depth;
    vector<vector<int>> g;
    euler_tour(int n, const vector<vector<int>> &g);
    void dfs(int x, int p, int& id, int d);
    ~euler_tour();
};

euler_tour::euler_tour(int _n, const vector<vector<int>>& _g) {
    n = _n;
    g = _g;
    reach.assign(n,-1);
    int id = 0;
    dfs(0,-1,id,0);
}

void euler_tour::dfs(int x, int p, int &id, int d) {
    if (reach[x] == -1) reach[x] = id;
    depth.push_back(d);
    vs.push_back(x);
    id++;
    for (auto &&e: g[x]) {
        if (e == p) continue;
        dfs(e, x, id, d+1);
        depth.push_back(d);
        vs.push_back(x);
        id++;
    }
    return;
}


int main(int argc, char const *argv[]) {
    
    return 0;
}