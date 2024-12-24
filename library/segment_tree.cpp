struct SegmentTree {
    // TO CHANGE

    struct Node { // set default values

        ll va;
        Node() { va = 0; }
        template <typename T> void apply(int l, int r, T val)
        { // update value and save push
            va = val;
        }
    };

    Node merge(const Node& left, const Node& right)
    {
        Node ans;
        ans.va = max(left.va, right.va);
        return ans;
    }

    // DEFAULT PART

    vector<Node> tree;
    int n;

    template <typename T> void build(int v, int l, int r, const vector<T>& arr)
    {
        if (l + 1 == r) {
            tree[v].apply(l, r, arr[l]);
            return;
        }
        int mid = (r + l) >> 1;
        int vl = v + 1, vr = v + ((mid - l) << 1);
        build(vl, l, mid, arr);
        build(vr, mid, r, arr);
        tree[v] = merge(tree[vl], tree[vr]);
    }

    void build(int v, int l, int r)
    {
        if (l + 1 == r) { return; }
        int mid = (r + l) >> 1;
        int vl = v + 1, vr = v + ((mid - l) << 1);
        build(vl, l, mid);
        build(vr, mid, r);
        tree[v] = merge(tree[vl], tree[vr]);
    }

    Node find(int v, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr) { return tree[v]; }
        int mid = (r + l) >> 1;
        int vl = v + 1, vr = v + ((mid - l) << 1);
        if (qr <= mid) {
            return find(vl, l, mid, ql, qr);
        } else if (ql >= mid) {
            return find(vr, mid, r, ql, qr);
        } else {
            return merge(find(vl, l, mid, ql, qr), find(vr, mid, r, ql, qr));
        }
    }

    template <typename T>
    void update(int v, int l, int r, int ql, int qr, const T& newval)
    {
        if (ql <= l && r <= qr) {
            tree[v].apply(l, r, newval);
            return;
        }
        int mid = (r + l) >> 1;
        int vl = v + 1, vr = v + ((mid - l) << 1);
        if (ql < mid) { update(vl, l, mid, ql, qr, newval); }
        if (qr > mid) { update(vr, mid, r, ql, qr, newval); }
        tree[v] = merge(tree[vl], tree[vr]);
    }

    int find_first(int v, int l, int r, int ql, int qr,
        const function<bool(const Node&)>& predicate)
    {
        if (!predicate(tree[v])) { return -1; }
        if (l + 1 == r) { return l; }
        int mid = (r + l) >> 1;
        int vl = v + 1, vr = v + ((mid - l) << 1);
        if (ql < mid) {
            int lans = find_first(vl, l, mid, ql, qr, predicate);
            if (lans != -1) { return lans; }
        }
        if (qr > mid) {
            int rans = find_first(vr, mid, r, ql, qr, predicate);
            if (rans != -1) { return rans; }
        }
        return -1;
    }
    int find_last(int v, int l, int r, int ql, int qr,
        const function<bool(const Node&)>& predicate)
    {
        if (!predicate(tree[v])) { return -1; }
        if (l + 1 == r) { return l; }
        int mid = (r + l) >> 1;
        int vl = v + 1, vr = v + ((mid - l) << 1);
        if (qr > mid) {
            int rans = find_last(vr, mid, r, ql, qr, predicate);
            if (rans != -1) { return rans; }
        }
        if (ql < mid) {
            int lans = find_last(vl, l, mid, ql, qr, predicate);
            if (lans != -1) { return lans; }
        }
        return -1;
    }

    // INTERFACE

    SegmentTree(int n)
        : n(n)
    { // build from size with default values
        tree.resize(2 * n - 1);
        build(0, 0, n);
    }

    template <typename T> SegmentTree(const vector<T>& arr)
    { // build from vector
        n = sz(arr);
        tree.resize(2 * n - 1);
        build(0, 0, n, arr);
    }

    Node find(int ql, int qr)
    { // find value on [ql, qr)
        return find(0, 0, n, ql, qr);
    }

    Node find(int qi)
    { // find value of position qi
        return find(0, 0, n, qi, qi + 1);
    }

    template <typename T> void update(int ql, int qr, const T& newval)
    { // update [ql, qr) with newval
        update(0, 0, n, ql, qr, newval);
    }

    template <typename T> void update(int qi, const T& newval)
    { // update position qi with newval
        update(0, 0, n, qi, qi + 1, newval);
    }

    int find_first(int ql, int qr, const function<bool(const Node&)>& predicate)
    { // find first index on [ql, qr) that satisfies predicate or -1 if none
        return find_first(0, 0, n, ql, qr, predicate);
    }

    int find_first(int ql, const function<bool(const Node&)>& predicate)
    { // find first index >= ql that satisfies predicate or -1 if none
        return find_first(0, 0, n, ql, n, predicate);
    }

    int find_first(const function<bool(const Node&)>& predicate)
    { // find first index that satisfies predicate or -1 if none
        return find_first(0, 0, n, 0, n, predicate);
    }
    int find_last(int ql, int qr, const function<bool(const Node&)>& predicate)
    { // find first index on [ql, qr) that satisfies predicate or -1 if none
        return find_last(0, 0, n, ql, qr, predicate);
    }

    int find_last(int ql, const function<bool(const Node&)>& predicate)
    { // find first index >= ql that satisfies predicate or -1 if none
        return find_last(0, 0, n, ql, n, predicate);
    }

    int find_last(const function<bool(const Node&)>& predicate)
    { // find first index that satisfies predicate or -1 if none
        return find_last(0, 0, n, 0, n, predicate);
    }
};