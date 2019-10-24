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

typedef struct edge{
    int from;
    int to;
    ll cost;
} edge;
typedef struct DP{
    ll cost;
    int from;
} DP;

int n, m;

vector<edge> G;

bool bellman_ford(int s, int t) { // sは開始頂点, tは目的頂点
    DP dp[n+10];
    REP(i,n) {
        dp[i].cost = LINF;
        dp[i].from = INF;
    }
    dp[s].cost = 0; // 開始点の距離は0
    REP(i,2*n) {
        for(auto e: G) {
            if (dp[e.from].cost != LINF && dp[e.to].cost > dp[e.from].cost+e.cost) {
                dp[e.to].cost = dp[e.from].cost + e.cost;
                dp[e.to].from = e.from;
                if(i>=n && e.to==t-1) return true;
            }
        }
    }
  return false;
}

int main(int argc, char const *argv[]) {
    
    return 0;
}