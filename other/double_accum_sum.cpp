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
int n,m;

void accum_sum(vector<vector<int>> &s, const vector<vector<char>> &c, char x) {
	rep(i,n) {
		rep(j,m) {
			if (c[i][j]==x) s[i+1][j+1]+=s[i+1][j]+1;
			else s[i+1][j+1]+=s[i+1][j];
		}
	}

	rep(j,m) rep(i,n) s[i+1][j+1]+=s[i][j+1];
	return;
}

int main(int argc, char const *argv[]) {
    
    return 0;
}