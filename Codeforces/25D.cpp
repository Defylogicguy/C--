/*************************
  Author: Defy logic guy
  22:21:10 - 04/09/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "25D"

struct Dsu
{
    vector<int> par, sz;
    void init(int n)
    {
        par.resize(n + 1);
        iota(all(par), 0);
        sz.assign(n + 1, 1);
    }
    int find(int x) { return par[x] = (par[x] == x ? x : find(par[x])); }
    int size(int x) { return sz[find(x)]; }
    bool uni(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y)
            return false;
        par[y] = x;
        sz[x] += sz[y];
        return true;
    }
};

void solve()
{
    int n;
    cin >> n;
    Dsu dsu;
    dsu.init(n);
    vector<pair<int, int>> a;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        if (!dsu.uni(u, v))
            a.emplace_back(u, v);
    }
    for (int i = 1; i <= n; i++)
        dsu.find(i);
    vector<int> c;
    for (int i = 1; i <= n; i++)
        if (dsu.find(i) == i)
            c.pb(i);
    cout << c.size() - 1 << '\n';
    for (int i = 0; i < c.size() - 1; i++)
        cout << a[i].first << ' ' << a[i].second << ' ' << c[i] << ' ' << c[i + 1] << '\n';
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
