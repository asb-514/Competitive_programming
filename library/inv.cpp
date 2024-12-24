
ll inv(ll a, ll m)
{
    if (a == 1) { return 1; }
    return (1LL - inv(m % a, a) * m) / a + m;
}