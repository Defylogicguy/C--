/*************************
  Author: Defy logic guy
  19:28:21 - 27/02/2026
*************************/
#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, const string &s)
{
    os.write(s.data(), s.size());
    return os;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> typename enable_if<!is_same<T, string>::value, decltype(c.begin(), c.end(), os)>::type
{
    for (auto it = c.begin(); it != c.end(); it++)
        os << (it == c.begin() ? "{" : ", ") << *it;
    return os << "}";
}
#define dbg(x) cerr << #x << " = " << (x) << '\n';
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "PATH_QUERIES"

struct Fenwreck
{
    vector<int> a;
    int n;
    Fenwreck(int _n = 0) : n(_n) { a.resize(n + 1); }
    void upd(int x, int v)
    {
        while (x < n)
        {
            a[x] += v;
            x += (x & -x);
        }
    }
    int get(int x)
    {
        int res = 0;
        while (x)
        {
            res += a[x];
            x -= (x & -x);
        }
        return res;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int t = 0;
    vector<int> tin(n + 1, -1), tout(n + 1, -1);
    function<void(int, int)> dfs = [&](int u, int p)
    {
        tin[u] = ++t;
        for (int v : adj[u])
            if (v != p)
                dfs(v, u);
        tout[u] = t;
    };
    dfs(1, 0);
    Fenwreck f(n + 1);
    for (int i = 1; i <= n; i++)
    {
        f.upd(tin[i], a[i]);
        if (tout[i] + 1 <= n)
            f.upd(tout[i] + 1, -a[i]);
    }
    while (q--)
    {
        int t, s;
        cin >> t >> s;
        if (t == 1)
        {
            int x;
            cin >> x;
            f.upd(tin[s], x - a[s]);
            if (tout[s] + 1 <= n)
                f.upd(tout[s] + 1, a[s] - x);
            a[s] = x;
        }
        else
            cout << f.get(tin[s]) << '\n';
    }
}

signed main()
{
    if (fopen(NAME ".INP", "r"))
    {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
