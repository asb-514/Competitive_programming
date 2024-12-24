template <typename T> struct SparseTable {
    vector<vector<T>> sparse;
    function<T(const T&, const T&)> accum_func;

    SparseTable(
        const vector<T>& arr, const function<T(const T&, const T&)>& func)
        : accum_func(func)
    {
        int n = arr.size();
        int logn = 32 - __builtin_clz(n);
        sparse.resize(logn, vector<T>(n));
        sparse[0] = arr;
        for (int lg = 1; lg < logn; lg++) {
            for (int i = 0; i + (1 << lg) <= n; i++) {
                sparse[lg][i] = accum_func(
                    sparse[lg - 1][i], sparse[lg - 1][i + (1 << (lg - 1))]);
            }
        }
    }

    T find(int l, int r)
    { // [l, r)
        int cur_log = 31 - __builtin_clz(r - l);
        return accum_func(
            sparse[cur_log][l], sparse[cur_log][r - (1 << cur_log)]);
    }
};
// SparseTable<int> st(a, [](ll c, ll d) { return max(c, d); });