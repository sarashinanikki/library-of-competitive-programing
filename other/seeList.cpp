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

template <class T> class Single_vector_csv {
private:
    vector<T> single_v;
public:
    Single_vector_csv(const vector<T> &v);
    void write(int n);
};

template <class T> Single_vector_csv<T>::Single_vector_csv(const vector<T> &v) {
    copy(v.begin(), v.end(), back_inserter(single_v));
}

template <class T> void Single_vector_csv<T>::write(int n) {
    ofstream wFile;
    wFile.open("test.csv", ios::trunc);
    int m = single_v.size();
    n = min(m, n);
    wFile << "index" << ",";
    for (int i = 0; i < n; ++i) wFile << i << ",";
    wFile << endl;
    wFile << "value" << ",";
    for (int i = 0; i < n; ++i) wFile << single_v[i] << ",";
    wFile << endl;
}

template <typename T>
void single_vector_csv(const vector<T> &v, int n) {
    ofstream wFile;
    wFile.open("test.csv", ios::trunc);
    int m = v.size();
    n = min(m, n);
    wFile << "index" << ",";
    for (int i = 0; i < n; ++i) wFile << i << ",";
    wFile << endl;
    wFile << "value" << ",";
    for (int i = 0; i < n; ++i) wFile << v[i] << ",";
    wFile << endl;
}

template <typename T>
void double_vector_csv(const vector<vector<T>> &v, int n, int m) {
    ofstream wFile;
    wFile.open("test.csv", ios::trunc);
    int s = v.size();
    n = min(s, n);
    int t = v[0].size();
    cout << t << std::endl;
    m = min(t, m);
    wFile << "i/j" << ",";
    for (int j = 0; j < m; ++j) wFile << j << ",";
    wFile << endl;
    for (int i = 0; i < n; ++i) {
        wFile << i << ",";
        for (int j = 0; j < m; ++j) {
            wFile << v[i][j] << ",";
        }
        wFile << endl;
    }
}

int main(int argc, char const *argv[]) {
    /*int n, m;
    n = 10; m = 20;
    vector<vector<int>> v(n, vector<int>(m, 0));
    REP(i,n) REP(j,m) v[i][j] = rand()%500;
    double_vector_csv(v, n, m);*/
    vector<int> a(50);
    REP(i,50) a[i] = rand()%100;
    Single_vector_csv<int> svc(a);
    svc.write(50);
    return 0;
}