struct Fenwick {
    vector<ll> tree;
    int n;

    Fenwick(int n)
        : n(n)
    {
        tree.assign(n, 0);
    }

    void point_add(int pos, ll val)
    {
        for (; pos < n; pos |= (pos + 1)) { tree[pos] += val; }
    }

    ll find_sum(int r)
    { // [0, r]
        ll ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) { ans += tree[r]; }
        return ans;
    }

    ll find_sum(int l, int r)
    { // [l, r)
        return find_sum(r - 1) - find_sum(l - 1);
    }
};