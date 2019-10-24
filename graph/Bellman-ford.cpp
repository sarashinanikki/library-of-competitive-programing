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

struct Edge {
   ll from, to, cost;
   Edge(){}
   Edge(ll from, ll to, ll cost):from(from),to(to),cost(cost){}
};

vector<Edge> g;

// 始点から到達出来るかどうかは問わず、閉路を検出するタイプ

bool bellman_ford_strict(int s, int V, vector<ll> &dp) {
    bool neg_loop = false;
    for (int i = 0; i < V; ++i) {
        bool update = false;
        for (auto &&e:g) {
            if (dp[e.to]>dp[e.from]+e.cost) {
                dp[e.to]=dp[e.from]+e.cost;
                update=true;
            }
        }
        if (!update) break;
        if (i==V-1) {
            neg_loop=true;
            break;
        }
    }
    return neg_loop;
}


// 始点から行ける閉路があり、無限に稼いで目的地にたどり着けるタイプ
// 始点から負の閉路に到達できて、かつ終点が負の閉路に含まれているパターン
// 稼いだあとにゴールできる
// 下のfind_neg_loopとセットで使う

void bellman_ford(int s, int t, int V, vector<ll> &dp) {
    dp[s]=0;
    bool neg_loop = false;
    int i = 0;
    while (true) {
        bool update = false;
        bool goal_updated = false;
        for (auto &&e:g) {
            if (dp[e.from]!=LINF && dp[e.to]>dp[e.from]+e.cost) {
                dp[e.to]=dp[e.from]+e.cost;
                update=true;
                if (e.to == t) goal_updated = true;
            }
        }
        if (!update) break;
        if (i>=V-1 && goal_updated) {
            neg_loop=true;
            break;
        }
        if (i>=2*V) break;
        ++i;
    }
}

// 負の閉路を発見する
// 既に上のアルゴリズムを回した後の配列を使いまわし、更新のある頂点を-LINFに更新していく
// -LINFなので、多倍長を使うようなコストの辺でなければ、これで全ての頂点が一周ループで緩和できる

bool find_neg_loop(int s, int t, int V, vector<ll> &dp) {
    bool update = false;
    for (int i=0; i<=V; ++i) {
        for (auto &&e: g) {
            if (dp[e.to]!=LINF && dp[e.to] > dp[e.from]+e.cost) {
                dp[e.to] = -LINF;
            }
        }
    }
    if (dp[t]==-LINF) return true;
    else return false;
}

// 始点からとにかく到達できる閉路を検出するタイプ
// 閉路に行った後ゴールできるかは問わない

bool bellman_ford_start_only(int s, int V, vector<ll> &dp) {
    dp[s]=0;
    bool neg_loop = false;
    for (int i = 0; i < V; ++i) {
        bool update = false;
        for (auto &&e:g) {
            if (dp[e.from]!=LINF && dp[e.to]>dp[e.from]+e.cost) {
                dp[e.to]=dp[e.from]+e.cost;
                update=true;
            }
        }
        if (!update) break;
        if (i==V-1) {
            neg_loop=true;
            break;
        }
    }
    return neg_loop;
}

// 最もシンプルな閉路検出出来ず無限ループするだけのベルマンフォード
void bellman_ford_simple(int s, int V, vector<ll> &dp) {
    while(true) {
        bool update = false;
        for (auto& e: g) {
            if (dp[e.from] != INF && dp[e.to] > dp[e.from] + e.cost) {
                dp[e.to] = dp[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) break;
    }
    
}

