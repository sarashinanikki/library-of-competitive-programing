template<typename T>
T gcd(T a, T b) {
    if (a % b == 0) return b;
    gcd(b, a%b);
}

