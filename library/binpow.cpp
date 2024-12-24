template <typename T> T binpow(T a, T b)
{
    T ans = 1;
    while (b) {
        if (b & 1) { ans = 1LL * ans * a % MOD; }
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ans;
}