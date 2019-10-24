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

template<typename T>
void print(vector<T> &x) {
    int n = x.size();
    rep(i,n) {
        cout << x[i];
        if (i!=n-1) cout<<" ";
        else cout << endl;
    }
}

template<typename T>
void print(vector<vector<T>> &x) {
    int n = x.size();
    rep(i,n) {
        rep(j,x[i].size()) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<string> s;
ll sumU[2222][2222] = {0};
ll sumR[2222][2222] = {0};
ll sumD[2222][2222] = {0};
ll sumL[2222][2222] = {0};
 
int n,m;

void sumLRUD() {
    // U
    for (int j = 0; j < m; ++j) {
        for (int i = 1; i < n; ++i) {
            if (s[i][j] == '.') {
                if (s[i-1][j] == '#') sumU[i][j] = sumU[i-1][j];
                else sumU[i][j] = sumU[i-1][j]+1;
            }
        }
    }
 
    // D
    for (int j = 0; j < m; ++j) {
        for (int i = n-2; i >= 0; --i) {
            if (s[i][j] == '.') {
                if (s[i+1][j] == '#') sumD[i][j] = sumD[i+1][j];
                else sumD[i][j] = sumD[i+1][j]+1;
            }
        }
    }
 
    // L
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (s[i][j] == '.') {
                if (s[i][j-1] == '#') sumL[i][j] = sumL[i][j-1];
                else sumL[i][j] = sumL[i][j-1]+1;
            }
        }
    }
 
    // R
    for (int i = 0; i < n; ++i) {
        for (int j = m-2; j >= 0; --j) {
            if (s[i][j] == '.') {
                if (s[i][j+1] == '#') sumR[i][j] = sumR[i][j+1];
                else sumR[i][j] = sumR[i][j+1]+1;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> n >> m;
    s.resize(n);
    rep(i,n) cin >> s[i];
    sumLRUD();
    ll ans = 0;
    rep(i,n) {
        rep(j,m) {
            ll L = sumL[i][j]; ll R = sumR[i][j];
            ll U = sumU[i][j]; ll D = sumD[i][j];
            chmax(ans,L+R+U+D);
        }
    }
    cout << ans << endl;
    return 0;
}