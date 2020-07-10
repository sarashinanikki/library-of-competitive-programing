template<typename T>
T gcd(T a, T b) {
    if (a % b == 0) return b;
    return gcd(b, a%b);
}

