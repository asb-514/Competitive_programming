const int MAXN = ;

vector<int> g[MAXN], used, p, d;

int cnt;

int dfs(int v, int pr)
{
    cnt++;
    d[v] = 1;
    for (int u : g[v]) {
        if (!used[u] && u != pr) { d[v] += dfs(u, v); }
    }
    return d[v];
}

int centroid(int v)
{
    cnt = 0;
    dfs(v, -1);
    int pr = -1;
    while (true) {
        int z = -1;
        for (int u : g[v]) {
            if (!used[u] && u != pr && d[u] * 2 >= cnt) { z = u; }
        }
        if (z == -1) { break; }
        pr = v;
        v = z;
    }
    return v;
}

void go(int v, int pr)
{
    v = centroid(v);
    p[v] = pr;
    used[v] = 1;

    for (int u : g[v]) {
        if (!used[u]) { go(u, v); }
    }
}