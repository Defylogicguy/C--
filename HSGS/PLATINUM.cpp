/*************************
  Author: Defy logic guy
  13:45:36 - 13/06/2025
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
#define NAME "PLATINUM"

struct dsu
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
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; i++)
        cin >> a[i] >> b[i];
    int q;
    cin >> q;
    vector<int> bs(q), be(q), x(q), y(q), z(q);
    for (int i = 0; i < q; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
        bs[i] = 0, be[i] = m - 1;
    }

    vector<int> idx;
    for (int i = 0; i < q; i++)
        idx.pb(i);
    dsu ds;
    for (int i = 0; i < 20; i++)
    {
        sort(all(idx), [be, bs](const int &a, const int &b)
             { return (bs[a] + be[a]) / 2 < (bs[b] + be[b]) / 2; });
        ds.init(n);
        int p = 0;
        for (auto &i : idx)
        {
            while (p <= (bs[i] + be[i]) / 2)
            {
                ds.uni(a[p], b[p]);
                p++;
            }
            if (bs[i] == be[i])
                continue;
            int idk = ds.size(x[i]) + ds.size(y[i]);
            if (ds.find(x[i]) == ds.find(y[i]))
                idk /= 2;
            if (idk < z[i])
                bs[i] = (bs[i] + be[i]) / 2 + 1;
            else
                be[i] = (bs[i] + be[i]) / 2;
        }
    }
    for (int i = 0; i < q; i++)
        cout << bs[i] + 1 << endl;
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
