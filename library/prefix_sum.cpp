struct PrefixSum {
    vector<ll> pref;
    PrefixSum(vector<ll>& a)
    {
        pref.resize(sz(a) + 1);
        pref[0] = 0;
        for (int i = 0; i < sz(a); i++) { pref[i + 1] = pref[i] + a[i]; }
    }

    ll find_sum(int l, int r) // [l, r)
    {
        return pref[r] - pref[l];
    }
};