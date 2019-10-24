#include <bits/stdc++.h>
const long long INF = 1e9;
const long long MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(long long i=(a);i<(b);++i)
#define REP(i,n) for(long long i=0;i<(n);++i)
#define REPR(i,n) for(long long i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;

// ここからライブラリ //

class union_find {
private:
    vector<ll> par;
    vector<ll> ran;
    vector<ll> m_size;
public:
    union_find(int n);
    int find(int x);
    void unite(int x, int y);
    bool same(int x, int y);
    ll size(int x);
};

union_find::union_find(int n){
    par.resize(n);
    iota(par.begin(), par.end(), 0);
    ran.resize(n, 0);
    m_size.resize(n, 1);
};

int union_find::find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
};

void union_find::unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (ran[x] < ran[y]) swap(x,y);
    par[y] = x;
    m_size[x] += m_size[y];
    if (ran[x]==ran[y]) ran[x]++;
};

ll union_find::size(int x) {
    return m_size[find(x)];
}

bool union_find::same(int x, int y) {
    return (find(x) == find(y));
};

// ここまでライブラリ //

int main() {
    int n,q;
    cin >> n >> q;
    union_find uf(n);
    REP(i,q) {
        int c,x,y;
        cin >> c >> x >> y;
        if (c) cout << uf.same(x,y) << endl;
        else uf.unite(x,y);
    }
}