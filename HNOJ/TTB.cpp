/*************************
  Author: Defy logic guy
  12:03:49 - 09/08/2025
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
#define NAME "TTB"

struct BIT
{
    int n, m;
    vector<vector<int>> t;
    BIT(int n = 505, int m = 505) : n(n), m(m)
    {
        t.assign(n + 5, vector<int>(m + 5, 0));
    }
    void add(int x, int y, int val)
    {
        for (int i = x; i <= n; i += i & -i)
            for (int j = y; j <= m; j += j & -j)
                t[i][j] += val;
    }
    int sum(int x, int y)
    {
        int res = 0;
        for (int i = x; i > 0; i -= i & -i)
            for (int j = y; j > 0; j -= j & -j)
                res += t[i][j];
        return res;
    }
};

BIT f1, f2, f3, f4;

void upd(int x, int y, int val)
{
    f1.add(x, y, val);
    f2.add(x, y, val * (x - 1));
    f3.add(x, y, val * (y - 1));
    f4.add(x, y, val * (x - 1) * (y - 1));
}

void addd(int x, int y, int u, int v, int val)
{
    upd(x, y, val);
    upd(x, v + 1, -val);
    upd(u + 1, y, -val);
    upd(u + 1, v + 1, val);
}

int pf(int x, int y)
{
    int s1 = f1.sum(x, y);
    int s2 = f2.sum(x, y);
    int s3 = f3.sum(x, y);
    int s4 = f4.sum(x, y);
    return s1 * x * y - s2 * y - s3 * x + s4;
}

int sum(int x, int y, int u, int v) { return pf(u, v) - pf(x - 1, v) - pf(u, y - 1) + pf(x - 1, y - 1); }

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    f1 = BIT(n + 2, m + 2);
    f2 = BIT(n + 2, m + 2);
    f3 = BIT(n + 2, m + 2);
    f4 = BIT(n + 2, m + 2);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int a;
            cin >> a;
            if (a != 0)
                addd(i, j, i, j, a);
        }
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        int x, y, u, val;
        cin >> x >> y >> u >> val;
        if (t == 1)
        {
            int w;
            cin >> w;
            addd(x, y, u, val, w);
        }
        else
            cout << sum(x, y, u, val) << '\n';
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
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();
    return 0;
}
