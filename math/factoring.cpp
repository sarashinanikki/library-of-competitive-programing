// --------------以下ライブラリ---------------------------------//

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


class Factoring {
private:
    vector<int> primes;
    map<int, int> factors;
public:
    Factoring();
    ~Factoring();
    void factoring(ll n);
};

Factoring::Factoring() {
    ll n = sqrt(1e12);
    vector<bool> primeFlags(n+10, true);
    primeFlags[0] = primeFlags[1] = false;
    vector<int> sqrtprimes;
    for (int i = 2; i*i <= n; i++) {
        bool mod0 = false;
        for (int j = 2; j*j <= i; j++) {
            if (i%j == 0) mod0 = true;
        }
        if (!mod0) sqrtprimes.push_back(i);
    }
    for (auto &&e: sqrtprimes) {
        for (int i = 2; i <= n; i++) {
            if (i%e == 0) primeFlags[i] = false;
        }
    }
    for (auto &&e: sqrtprimes) primeFlags[e] = true;
    for (int i = 1; i <= n; i++) if (primeFlags[i]) primes.push_back(i);
    return;
}
 
void Factoring::factoring(ll n) {
    for (auto &&e: primes) {
        if (e > n) break;
        while(n%e == 0){
            factors[e]++;
            n /= e;
        }
    }
    factors[n]++;
    factors.erase(1);
}

Factoring::~Factoring() {}