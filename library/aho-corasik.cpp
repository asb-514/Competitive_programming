struct aho {
    vector<vector<int>> g, gr;
    vector<string> str;
    int root;
    int sz;
    vector<ll> ending;
    vector<int> link;
    char firstlet;
    int numlet = 0;

    aho()
        : g()
        , gr()
        , str()
        , root(0)
        , sz(0)
        , ending()
        , link()
    {
    }

    aho(vector<string> q, char firlet = 'a')
    { // change
        firstlet = firlet;
        sz = q.size();
        str = q;
        g.clear();
        gr.clear();
        ending.clear();
        link.clear();
        root = 0;
        ending.assign(1, 0);
        numlet = 0;
        for (int i = 0; i < q.size(); i++) {
            for (int j = 0; j < q[i].size(); j++) {
                numlet = q[i][j] - firstlet;
            }
        }
        numlet++;
        g.push_back(vector<int>(numlet, -1));
        for (int i = 0; i < q.size(); i++) {
            int v = root;
            for (int j = 0; j < q[i].size(); j++) {
                if (g[v][q[i][j] - firstlet] == -1) {
                    g[v][q[i][j] - firstlet] = g.size();
                    g.push_back(vector<int>(numlet, -1));
                    ending.push_back(0);
                }
                v = g[v][q[i][j] - firstlet];
            }
            ending[v]++;
        }
        link.assign(g.size(), -1);
        link[root] = root;
        queue<int> que;
        que.push(root);
        while (que.size()) {
            int v = que.front();
            que.pop();
            for (int i = 0; i < numlet; i++) {
                if (g[v][i] == -1) {
                    if (v == root) {
                        g[v][i] = v;
                    } else {
                        g[v][i] = g[link[v]][i];
                    }
                } else {
                    que.push(g[v][i]);
                    if (v == root) {
                        link[g[v][i]] = v;
                    } else {
                        link[g[v][i]] = g[link[v]][i];
                    }
                }
            }
            gr.resize(g.size());
            for (int i = 0; i < g.size(); i++) {
                if (i != root) { gr[link[i]].push_back(i); }
            }
            dfslink(root);
        }
    }

    void dfslink(int v)
    {
        for (int u : gr[v]) {
            ending[u] += ending[v];
            dfslink(u);
        }
    }

    ll find(string s)
    { // change
        ll ans = 0;
        int v = root;
        for (int i = 0; i < s.size(); i++) {
            v = g[v][s[i] - firstlet];
            ans += ending[v];
        }
        return ans;
    }
};