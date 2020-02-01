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

 
template<typename T>
T gcd(T a, T b) {
    if (a % b == 0) return b;
    gcd(b, a%b);
}


int main(int argc, char const *argv[]) {
    int n,s,t; cin>>n>>s>>t;
    vector<int> x(n),y(n);
    set<P> st;
    int X = 0; int Y = 0; int Z = 0;
    rep(i,n) {
        cin>>x[i]>>y[i];
        x[i] -= s; y[i] -= t;
        if (x[i]==0 && y[i]==0) Z=1;
        else if (x[i] == 0 && y[i] != 0) X=1;
        else if (x[i]!=0 && y[i]==0) Y=1;
        else {
            int g = gcd(x[i],y[i]);
            x[i]/=g; y[i]/=g;
            st.emplace(x[i],y[i]);
        }
    }

    int ans = st.size()+X+Y;
    if (ans==0 && Z) cout << 1 << endl;
    else cout << ans << endl;
    return 0;
}