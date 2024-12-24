#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pll> vll;
typedef string str;

#define sz(a) ((int)((a).size()))
#define R(i, j, k) for (ll i = (j); i <= (k); ++i)
#define N(i, n) for (ll i = (0); i < (n); ++i)
#define L(i, j, k) for (ll i = (j); i >= (k); --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(a, x) for (auto& a : x)
#define make_unique(v) sort(all(v)), v.erase(unique(all(v)), v.end())
#define F first
#define S second
#define pb push_back
#define nl '\n'
#define inf (ll)1e18
#define ya cout << "Yes\n"
#define na cout << "No\n"
#define imp cout << "Impossible\n"

#ifdef ONPC
#include <bits/debug.h>
#else
#define dbg(...)
#define dbgarr(...)
#endif

template <class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template <class T> using maxpq = priority_queue<T>;
template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

namespace FastIO {
const int mxn = 1 << 16;
char buf[mxn], *S = NULL, *T = NULL;
inline char Getchar()
{
    return (S == T ? T = (S = buf) + fread(buf, 1, mxn, stdin) : 0,
        S == T ? EOF : *S++);
}
template <typename T> void read(T& x)
{
    x = 0;
    char c = 0;
    int f = 0;
    for (c = Getchar(); c != EOF && (c < '0' || c > '9'); c = Getchar())
        if (c == '-') f = 1;
    while (c >= '0' && c <= '9') x = x * 10 + (c & 15), c = Getchar();
    if (f) x = -x;
}
void read(string& s)
{
    char c = Getchar();
    do {
        s += c;
        c = Getchar();
    } while (c != '\n' && c != ' ' && c != EOF);
}
template <typename T> void read(vector<T>& a)
{
    for (auto& x : a) read(x);
}
template <typename T, typename... _T> void read(T& x, _T&... y)
{
    read(x), read(y...);
}
template <class T> inline void write(T x)
{
    if (x < 0) x = -x, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
template <class T> inline void write(T x, char ch) { write(x), putchar(ch); }
}

template <typename T> ostream& operator<<(ostream& out, vector<T>& a)
{
    for (auto& x : a) out << x << ' ';
    return out;
};

int solve() { 
\t$0
\treturn 0;
}

int32_t main()
{
    // sieve(2e5+10);
    ios::sync_with_stdio(0), cin.tie(0);
    if (solve()) { };
#ifdef ONPC
    cerr << "__________________________\n";
#endif
#ifdef ONPC
    cerr << "\nfinished in " << (ld)clock() / CLOCKS_PER_SEC << " sec\n";
#endif
}
