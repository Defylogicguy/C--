/*************************
  Author: Defy logic guy
  19:59:30 - 30/01/2026
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
        os << (it == c.begin() ? "" : " ") << *it;
    return os << "";
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
#define NAME "HOAHOC1"

struct node
{
    int u, v, w, i;
    node(int u = 0, int v = 0, int w = 0, int i = 0) : u(u), v(v), w(w), i(i) {}
};

struct DSU
{
    DSU(int n = 0) { init(n); }
    vector<int> par, sz;
    void init(int n)
    {
        par.resize(n + 1);
        iota(all(par), 0);
        sz.assign(n + 1, 1);
    }
    int find(int x) { return par[x] = (par[x] == x ? x : find(par[x])); }
    int size(int x) { return sz[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
    void uni(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        par[y] = x;
        sz[x] += sz[y];
    }
};

void solve()
{
    int n, m, s;
    cin >> n >> m >> s;
    vector<node> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
        a[i].i = i + 1;
    }
    sort(all(a), [](const node &a, const node &b)
         { return a.w > b.w; });
    DSU dsu(n);
    vector<bool> vis(m, false);
    for (int i = 0; i < m; i++)
    {
        auto [u, v, w, j] = a[i];
        if (dsu.same(u, v))
            continue;
        dsu.uni(u, v);
        vis[i] = true;
    }
    vector<node> r;
    for (int i = 0; i < m; i++)
        if (!vis[i])
            r.pb(a[i]);
    sort(all(r), [](const node &a, const node &b)
         { return a.w < b.w; });
    vector<int> ans;
    for (int i = 0; i < r.size(); i++)
        if (s >= r[i].w)
        {
            s -= r[i].w;
            ans.pb(r[i].i);
        }
        else
            break;
    sort(all(ans));
    cout << ans.size() << '\n';
    if (ans.size())
        cout << ans;
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
