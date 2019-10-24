#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define dump(x)  cout << 'x' << ' = ' << (x) << ` `;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P;

class RMQ {
private:
    vector<ll> val;
    int N;
public:
    RMQ(int n, ll init);
    void update(int i, int x);
    ll find(int r, int l, int fn, int fr, int fl);
    ~RMQ();
};

RMQ::RMQ(int n, ll init) {
    N = n;
    val.resize(2*N-1, init);
}

void RMQ::update(int i, int x) {
    i += N-1;
    val[i] = x;
    while (i > 0) {
        i = (i-1)/2;
        val[i] = min(val[i*2+1], val[i*2+2]);
    }
}

ll RMQ::find(int a, int b, int k, int l, int r) {
    // [a, b)のクエリ
    // ノードk(区間[a, b)担当)が答える
    if (b <= l || r <= a) return LINF; // 区間がかぶらなければLINF
    if (a <= l && r <= b) return val[k]; // 区間が完全にかぶっていればval[k]
    else {
        // 一部だけかぶる場合は左右の子に委託する
        ll c1 = find(a, b, 2*k+1, l, (l+r)/2);
        ll c2 = find(a, b, 2*k+2, (l+r)/2, r);
        return min(c1, c2);
    }
}

RMQ::~RMQ() {
}

// --------------cut above!!------------------ //

int main(int argc, char const *argv[]) {
    int n, q;
    cin >> n >> q;
    int N = 1;
    while (N < n) {
        N*=2;
    }
    RMQ seg(N, (1ll<<31)-1);
    
    REP(i,q) {
        int c;
        cin >> c;
        if (c == 0) {
            int ind, x;
            cin >> ind >> x;
            seg.update(ind, x);
        }
        else {
            int s,t;
            cin >> s >> t;
            ll ans = seg.find(s,t+1,0,0,N);
            cout << ans << endl;
        }
    }
    return 0;
}