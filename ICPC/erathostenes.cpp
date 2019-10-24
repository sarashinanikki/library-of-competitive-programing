#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<int> primes;

void erathosthenes(int n) {
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
    for (int i = 0; i < sqrtprimes.size(); i++) {
        for (int j = 2; j <= n; j++) {
            if (j%sqrtprimes[i] == 0) primeFlags[j] = false;
        }
    }
    for (auto &&e: sqrtprimes) primeFlags[e] = true;
    for (int i = 1; i <= n; i++) {
        if (primeFlags[i]) primes.push_back(i);
    }
    return;
}

int main() {
    int n; cin >> n;
    erathosthenes(n);
}