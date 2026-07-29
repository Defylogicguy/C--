/*************************
  Author: Defy logic guy
  19:35:58 - 28/07/2026
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "mootube"

struct edge
{
    int u, v, w;
    edge(int u = 0, int v = 0, int w = 0) : u(u), v(v), w(w) {}
    bool operator<(const edge &o) const { return w > o.w; }
};

struct query
{
    int k, v, i;
    query(int k = 0, int v = 0, int i = 0) : k(k), v(v), i(i) {}
    bool operator<(const query &o) const { return k > o.k; }
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
        x = find(x), y = find(y);
        if (x == y)
            return;
        par[y] = x;
        sz[x] += sz[y];
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<edge> a(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> a[i].u >> a[i].v >> a[i].w;
    sort(all(a));
    vector<query> v(q);
    for (int i = 0; i < q; i++)
        cin >> v[i].k >> v[i].v, v[i].i = i;
    sort(all(v));
    DSU dsu(n);
    int cur = 0;
    vector<int> ans(q);
    for (int i = 0; i < q; i++)
    {
        while (cur < n - 1 and a[cur].w >= v[i].k)
        {
            dsu.uni(a[cur].u, a[cur].v);
            cur++;
        }
        ans[v[i].i] = dsu.size(v[i].v) - 1;
    }
    for (int i : ans)
        cout << i << '\n';
}

signed main()
{
    freopen(NAME ".in", "r", stdin);
    freopen(NAME ".out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
