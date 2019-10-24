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

int V,E;

struct Edge {
    ll to, cost;
    Edge(){}
    Edge(ll to, ll cost):to(to),cost(cost){}
};

vector<vector<Edge>> G;
vector<bool> used;

ll prim() {
    used.resize(V,false);
    priority_queue<P, vector<P>, greater<P>> pq;
    ll ret = 0;

    pq.push({0,0});// pair(cost,to)

    while (!pq.empty()) {
        P x = pq.top(); pq.pop();
        ll cost = x.first; ll v = x.second;
        
        if (used[v]) continue;
        used[v] = true;
        ret+=cost;
        for (auto &&e: G[v]) {
            if (!used[e.to]) pq.emplace(e.cost,e.to);
        }
    }
    return ret;
}

int main(int argc, char const *argv[]) {
    
    return 0;
}