/*************************
  Author: Defy logic guy
  19:51:31 - 30/09/2025
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
    for (auto it = c.begin(); it != c.end(); ++it)
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
#define NAME "DINODAISY_NUMGAME"

struct DSU
{
    DSU(int n = 0) { init(n); }
    vector<int> par, sz;
    void init(int n)
    {
        par.resize(n + 1);
        iota(all(par), 0);
        sz.assign(n + 1, 0);
    }
    int find(int x) { return par[x] = (par[x] == x ? x : find(par[x])); }
    int size(int x) { return sz[find(x)]; }
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<pair<int, int>> val;
    for (int i = 1; i <= n; i++)
        val.emplace_back(a[i], i);
    sort(all(val));
    vector<pair<int, int>> qry(q);
    for (int i = 0; i < q; i++)
    {
        cin >> qry[i].first;
        qry[i].second = i;
    }
    sort(all(qry), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first < b.first; });
    DSU dsu(n);
    vector<int> ans(q, 0), idk(n + 1, 0);
    int cur = 0, mx = 0;
    for (auto &[u, v] : qry)
    {
        while (cur < n and val[cur].first <= u)
        {
            int t = val[cur].second;
            dsu.sz[t] = 1;
            idk[t] = 1;
            if (t >= 2 and idk[t - 1])
                dsu.uni(t, t - 1);
            if (t + 1 <= n and idk[t + 1])
                dsu.uni(t, t + 1);
            mx = max(mx, dsu.size(t));
            cur++;
        }
        ans[v] = mx;
    }
    for (int i : ans)
        cout << i << '\n';
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
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
