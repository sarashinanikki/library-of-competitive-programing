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

typedef struct Edge {
    ll to, cost;
} Edge;

typedef struct Info {
    ll dist, from;
} Info;

vector<vector<Edge>> g;

void dijkstra(vector<Info> &dp, int s) {
    priority_queue<P> pq;
    dp[s].dist = 0;
    // P(dist, v)
    pq.push({0,s});

    while (!pq.empty()) {
        P p = pq.top(); pq.pop();
        int v = p.second;
        for (auto &&e: g[v]) {
            if (dp[e.to].dist > dp[v].dist+e.cost) {
                dp[e.to].dist = dp[v].dist+e.cost;
                dp[e.to].from = v;
                pq.push({dp[e.to].dist, e.to});
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    
    return 0;
}