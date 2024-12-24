struct DSU {
    vector<int> pr;
    vector<int> size;
    int n;

    DSU(int n)
        : n(n)
    {
        pr.resize(n);
        size.resize(n);
        iota(pr.begin(), pr.end(), 0);
        for_each(size.begin(), size.end(), [](int& x) { x = 1; });
    }

    inline int findpr(int v)
    {
        return (v == pr[v] ? v : (pr[v] = findpr(pr[v])));
    }

    inline bool check(int a, int b) { return findpr(a) == findpr(b); }

    inline bool unite(int v, int u)
    {
        v = findpr(v);
        u = findpr(u);
        if (u == v) {
            return false;
        } else {
            if (size[v] > size[u]) swap(u, v);
            size[u] += size[v];
            pr[v] = u;
            return true;
        }
    }
};