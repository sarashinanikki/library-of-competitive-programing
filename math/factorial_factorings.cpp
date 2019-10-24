// --------------以下ライブラリ------------------//
//O(N)

#include <iostream>
#include <utility>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
#include <math.h>
#include <numeric>
#include <sstream>
typedef long long ll;
using namespace std;

vector<int> primes;
map<int, int> factors;

void erathosthenes(int n) {
    bool primeFlags[n+1];//boolでふるいを用意する。素数であればtrueであるとする
    for (int i = 0; i <= n; i++) primeFlags[i] = true;//ふるいをリセット
    primeFlags[0] = primeFlags[1] = false;//0と1は素数ではないのでふるい落とす(=falseにする)
    vector<int> sqrtprimes;//ルートnまでの素数を入れておくための配列
    for (int i = 2; i*i <= n; i++) {
        bool mod0 = false;
        for (int j = 2; j*j <= i; j++) {
            if (i%j == 0) mod0 = true;
        }
        if (!mod0) sqrtprimes.push_back(i);
    }
    for (int i = 0; i < sqrtprimes.size(); i++) {
        for (int j = 2; j <= n; j++) {
            if (j%sqrtprimes[i] == 0) primeFlags[j] = false;
        }
    }
    for (int i = 0; i < sqrtprimes.size(); i++) primeFlags[sqrtprimes[i]] = true;
    for (int i = 1; i <= n; i++) if (primeFlags[i]) primes.push_back(i);
    return;
}

void factoring(int n) {
    for (int i = 0; i < primes.size(); ++i) {
        while(n%primes[i] == 0){
            factors[primes[i]]++;
            n /= primes[i];
        }
    }
}

void factorial(int n) {
    erathosthenes(n);
    for (int i = 2; i <= n; ++i) {
        factoring(i);
    }
}

//---------以上ライブラリ--------//----------以下debug用main関数----------//


int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    factorial(n);
    cout << "Primes =" << " ";
    for (auto x : primes) cout << x << " ";
    cout << "" << std::endl;
    string factorString = "factoring = ";
    for (auto x : factors) factorString +=  to_string(x.first) + "^" + to_string(x.second) + " * ";
    for (int i = 0; i < 3; i++) factorString.pop_back();
    cout << factorString << std::endl;
    return 0;
}
