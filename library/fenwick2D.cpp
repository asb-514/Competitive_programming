struct Fenwick2D {
    vector<vector<ll>> tree;
    int n, m;

    Fenwick2D(int n, int m)
        : n(n)
        , m(m)
    {
        tree.assign(n, vector<ll>(m, 0));
    }

    void point_add(int posx, int posy, ll val)
    {
        for (int x = posx; x < n; x |= (x + 1)) {
            for (int y = posy; y < m; y |= (y + 1)) { tree[x][y] += val; }
        }
    }

    ll find_sum(int rx, int ry)
    { // [0, rx] x [0, ry]
        ll ans = 0;
        for (int x = rx; x >= 0; x = (x & (x + 1)) - 1) {
            for (int y = ry; y >= 0; y = (y & (y + 1)) - 1) {
                ans += tree[x][y];
            }
        }
        return ans;
    }

    ll find_sum(int lx, int rx, int ly, int ry)
    { // [lx, rx) x [ly, ry)
        return find_sum(rx - 1, ry - 1) - find_sum(rx - 1, ly - 1)
            - find_sum(lx - 1, ry - 1) + find_sum(lx - 1, ly - 1);
    }
};