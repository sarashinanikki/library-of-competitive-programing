template<typename T>
T gcd(T a, T b) {
    if (a % b == 0) return b;
    gcd(b, a%b);
}

template<typename U>
U gcd_multi(vector<U> A) {
    int n = A.size();
    if (n == 1) return A[0];
    int G = gcd(A[0], A[1]);
    if (n == 2) return G;
    for (int i = 2; i < n; ++i) G = gcd(G, A[i]);
    return G;
}

template<typename U>
U lcm(U a, U b) {
    U ans = a*b/gcd(a, b);
    return ans;
}

template<typename U>
U lcm_multi(const vector<U> &A) {
    if (n == 1) return A[0];
    U ans = lcm_multi(A[0],A[1]);
    for (int i = 2; i < n; ++i) ans = lcm_multi(ans,A[i]);
    return ans;
}