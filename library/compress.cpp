template <typename T> struct Compress {
    vector<T> xs;
    bool Built;

    Compress() = default;

    Compress(const vector<T>& vs) { add(vs); }

    Compress(const initializer_list<vector<T>>& vs)
    {
        for (auto& p : vs) add(p);
        Built = false;
    }

    void add(const vector<T>& vs)
    {
        copy(begin(vs), end(vs), back_inserter(xs));
        Built = false;
    }

    void add(const T& x)
    {
        xs.emplace_back(x);
        Built = false;
    }

    void build()
    {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
        Built = true;
    }

    vector<int> find(const vector<T>& vs) const
    {
        if (!Built) dbg("Not Built");
        vector<int> ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T& x) {
            return lower_bound(begin(xs), end(xs), x) - begin(xs);
        });
        return ret;
    }

    int find(const T& x) const
    {
        if (!Built) dbg("Not Built");
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    const T& operator[](int k) const { return xs[k]; }
};