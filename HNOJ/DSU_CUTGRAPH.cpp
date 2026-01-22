/*************************
  Author: Defy logic guy
  19:08:05 - 16/01/2026
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
#define NAME "DSU_CUTGRAPH"

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
        if (sz[x] < sz[y])
            swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    DSU dsu(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        // dsu.uni(u, v);
    }
    vector<tuple<string, int, int>> qry(k);
    for (int i = 0; i < k; i++)
    {
        string a;
        int b, c;
        cin >> a >> b >> c;
        qry[i] = tie(a, b, c);
    }
    vector<string> ans;
    for (int i = k - 1; i >= 0; i--)
        if (get<0>(qry[i]) == "cut")
            dsu.uni(get<1>(qry[i]), get<2>(qry[i]));
        else
        {
            if (dsu.same(get<1>(qry[i]), get<2>(qry[i])))
                ans.pb("YES\n");
            else
                ans.pb("NO\n");
        }
    reverse(all(ans));
    for (string s : ans)
        cout << s;
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
