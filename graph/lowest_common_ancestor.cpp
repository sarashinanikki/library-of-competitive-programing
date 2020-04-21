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

euler_tour::~euler_tour() {
}

template <class T>
class SegTree {
    int n; // number of leaves
    vector<T> data; // vector which has datas
    T def; // init number & 単位元
    function<T(T,T)> operation; // 区間クエリで使う処理
    function<T(T,T)> update; // 点更新で使う処理

    T _query(int a, int b, int k, int l, int r) {
        // [a, b)のクエリ
        // ノードk(区間[l, r)担当)が答える
        if (b <= l || r <= a) return def; // 区間がかぶらなければdef
        if (a <= l && r <= b) return data[k]; // 区間が完全にかぶっていればdata[k]
        else {
            // 一部だけかぶる場合は左右の子に委託する
            T c1 = _query(a, b, 2*k+1, l, (l+r)/2);
            T c2 = _query(a, b, 2*k+2, (l+r)/2, r);
            return operation(c1, c2);
        }
    }

    public:

        SegTree(size_t _n, T _def, function<T(T,T)> _operation, function<T(T,T)> _update) :
            def(_def), operation(_operation), update(_update){
                n = 1;
                while (n < _n) {n *= 2;}
                data = vector<T>(2*n-1, def);
        }

        T query(int a, int b) {return _query(a,b,0,0,n);}

        void change(int i, T x) {
            i += n-1;
            data[i] = update(data[i],x);
            while (i>0) {
                i = (i-1)/2;
                data[i] = operation(data[i*2+1], data[i*2+2]);
            }
        }

        T operator[](int i) {return data[i+n-1];}
};

class lowest_common_ancestor {
private:
    int n;
    SegTree<P> rmq;
    euler_tour et;
public:
    lowest_common_ancestor(const euler_tour &et, SegTree<P> rmq);
    int get_lca(int x, int y);
    ~lowest_common_ancestor();
};

lowest_common_ancestor::lowest_common_ancestor(const euler_tour &_et, SegTree<P> _rmq): et(_et),rmq(_rmq){
    n = et.depth.size();
    rep(i,n) {
        rmq.change(i, P(et.depth[i], et.vs[i]));
    }
}

int lowest_common_ancestor::get_lca(int x, int y) {
    int l = et.reach[x]; int r = et.reach[y];
    if (l > r) swap(l,r);
    P res = rmq.query(l,r+1);
    return res.second;
}

lowest_common_ancestor::~lowest_common_ancestor() {
}



int main(int argc, char const *argv[]) {
    int n; cin>>n;
    vector<vector<int>> g(n);
    rep(i,n) {
        int k; cin>>k;
        rep(j,k) {
            int t; cin>>t;
            g[i].push_back(t);
            g[t].push_back(i);
        }
    }

    euler_tour et(n, g);
    SegTree<P> rmq(et.depth.size(), P(LINF,LINF), [](P x, P y) {return min(x,y);}, [](P a, P x) {return x;});
    lowest_common_ancestor lca(et,rmq);


    int q; cin>>q;

    while (q--) {
        int u,v; cin>>u>>v;
        cout << lca.get_lca(u,v) << '\n';
    }
    /*
    cout << "----------------" << '\n';
    vector<int> h(n);
    rep(i,n) h[i] = i;
    print(h);
    print(et.reach);
    print(et.vs);
    print(et.depth);
    */
    return 0;
}