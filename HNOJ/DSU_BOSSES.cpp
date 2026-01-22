/*************************
  Author: Defy logic guy
  20:04:33 - 16/01/2026
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
#define NAME "DSU_BOSSES"

struct DSU
{
    DSU(int n = 0) { init(n); }
    vector<int> par, sz, d;
    void init(int n)
    {
        par.resize(n + 1);
        iota(all(par), 0);
        sz.assign(n + 1, 1);
        d.assign(n + 1, 0);
    }
    int find(int x)
    {
        if (par[x] == x)
            return x;
        int p = find(par[x]);
        d[x] += d[par[x]];
        return par[x] = p;
    }
    int size(int x) { return sz[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
    void uni(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        par[x] = y;
        sz[y] += sz[x];
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while (m--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int a, b;
            cin >> a >> b;
            dsu.par[a] = b;
            dsu.d[a] = 1;
        }
        else
        {
            int c;
            cin >> c;
            dsu.find(c);
            cout << dsu.d[c] << '\n';
        }
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
