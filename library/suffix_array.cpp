const char C = 'a' - 1; // before first letter // change
const char maxchar = 'z'; // change

vector<int> suffarray(string s)
{ // without $ at the end
    vector<int> p, c, pn, cn, cnt;
    int n = (int)s.size();
    c.assign(n, 0);
    for (int i = 0; i < n; i++) { c[i] = s[i] - C; }
    for (int j = 0; j <= (maxchar - C); j++) {
        for (int i = 0; i < n; i++) {
            if (c[i] == j) { p.push_back(i); }
        }
    }
    int maxc = c[p.back()];
    pn.resize(n);
    for (int k = 0; (1 << k) <= 2 * n; k++) {
        for (int i = 0; i < n; i++) { pn[i] = ((p[i] - (1 << k)) % n + n) % n; }
        cnt.assign(maxc + 3, 0);
        for (int i = 0; i < n; i++) { cnt[c[i] + 1]++; }
        for (int i = 1; i <= maxc + 2; i++) { cnt[i] += cnt[i - 1]; }
        for (int i = 0; i < n; i++) { p[cnt[c[pn[i]]]++] = pn[i]; }
        cn.assign(n, 0);
        cn[p[0]] = 1;
        for (int i = 1; i < n; i++) {
            if (c[p[i]] == c[p[i - 1]]
                && c[(p[i] + (1 << k)) % n] == c[(p[i - 1] + (1 << k)) % n]) {
                cn[p[i]] = cn[p[i - 1]];
            } else {
                cn[p[i]] = cn[p[i - 1]] + 1;
            }
        }
        maxc = cn[p.back()];
        c = cn;
    }
    return p;
}

vector<int> findlcp(string s, vector<int> p)
{
    vector<int> lcp, mem;
    int n = (int)s.size();
    mem.resize(n);
    for (int i = 0; i < n; i++) { mem[p[i]] = i; }
    lcp.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (i > 0) { lcp[mem[i]] = max(lcp[mem[i - 1]] - 1, 0); }
        if (mem[i] == n - 1) { continue; }
        while (max(i, p[mem[i] + 1]) + lcp[mem[i]] < n
            && s[i + lcp[mem[i]]] == s[p[mem[i] + 1] + lcp[mem[i]]]) {
            lcp[mem[i]]++;
        }
    }
    return lcp;
}