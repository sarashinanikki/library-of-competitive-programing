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
typedef pair<ll, char> P;

// 2値の圧縮のみ対応

vector<pair<ll, char>> RLE(const string &s) {
	ll cnt = 0;
	ll n = s.length();
	vector<pair<ll, char>> res;
	for (ll i = 0; i < s.size(); i++) {
		cnt++;
		if (i == (ll)s.size()-1) {
			res.push_back(make_pair(cnt,s[i]));
			break;
		}
		if (s[i] != s[i+1]) {
			res.push_back(make_pair(cnt,s[i]));
			cnt = 0;
		}
	}
	return res;
}

int main(int argc, char const *argv[]) {
    string s; cin>>s;
    s.push_back('=');
    vector<P> a = RLE(s);
    cout<<endl;
    return 0;
}