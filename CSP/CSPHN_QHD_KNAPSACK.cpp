/*************************
  Author: Defy logic guy
  10:23:48 - 23/08/2025
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
#define NAME "CSPHN_QHD_KNAPSACK"

void solve()
{
    int n;
    int W;
    cin >> n >> W;
    struct Item
    {
        int w, v;
        int idx;
    };
    vector<Item> items(n);
    int sum_v = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].w >> items[i].v;
        items[i].idx = i + 1;
        sum_v += items[i].v;
    }

    if (n <= 36)
    {
        int h = n / 2;
        int t = n - h;
        vector<tuple<int, int, int>> gA, gB;
        for (int m = 0; m < (1 << h); m++)
        {
            int tw = 0, tv = 0;
            for (int i = 0; i < h; i++)
            {
                if (m & (1 << i))
                {
                    tw += items[i].w;
                    tv += items[i].v;
                }
            }
            if (tw <= W)
                gA.pb({tw, tv, m});
        }
        for (int m = 0; m < (1 << t); m++)
        {
            int tw = 0, tv = 0;
            for (int i = 0; i < t; i++)
            {
                if (m & (1 << i))
                {
                    tw += items[h + i].w;
                    tv += items[h + i].v;
                }
            }
            if (tw <= W)
                gB.pb({tw, tv, m});
        }
        sort(all(gB), [](auto a, auto b)
             { return get<0>(a) < get<0>(b); });
        vector<tuple<int, int, int>> cB;
        for (auto &entry : gB)
        {
            int w, v;
            int mask;
            tie(w, v, mask) = entry;
            if (!cB.empty() && get<1>(cB.back()) >= v)
                continue;
            cB.pb(entry);
        }
        int bV = 0, bW = 0;
        int bA = 0, bB = 0;
        for (auto &entry : gA)
        {
            int wA, vA, maskA;
            tie(wA, vA, maskA) = entry;
            int r = W - wA;
            int l = 0, h = (int)cB.size() - 1, p = -1;
            while (l <= h)
            {
                int m = (l + h) / 2;
                if (get<0>(cB[m]) <= r)
                {
                    p = m;
                    l = m + 1;
                }
                else
                    h = m - 1;
            }
            if (p != -1)
            {
                int wB, vB, maskB;
                tie(wB, vB, maskB) = cB[p];
                if (vA + vB > bV)
                {
                    bV = vA + vB;
                    bW = wA + wB;
                    bA = maskA;
                    bB = maskB;
                }
            }
            else if (vA > bV)
            {
                bV = vA;
                bW = wA;
                bA = maskA;
                bB = 0;
            }
        }
        vector<int> s;
        for (int i = 0; i < h; i++)
        {
            if (bA & (1LL << i))
                s.pb(items[i].idx);
        }
        for (int i = 0; i < t; i++)
        {
            if (bB & (1LL << i))
                s.pb(items[h + i].idx);
        }
        cout << bV << "\n"
             << s.size() << "\n";
        for (int x : s)
            cout << x << " ";
        cout << "\n";
        return;
    }

    if (W <= 1000)
    {
        vector<vector<int>> t(n + 1, vector<int>(W + 1, 0));
        vector<vector<int>> p(n + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int w = 0; w <= W; w++)
            {
                t[i][w] = t[i - 1][w];
                p[i][w] = 0;
                if (w >= items[i - 1].w && t[i - 1][w - items[i - 1].w] + items[i - 1].v > t[i][w])
                {
                    t[i][w] = t[i - 1][w - items[i - 1].w] + items[i - 1].v;
                    p[i][w] = 1;
                }
            }
        }
        int v = t[n][W];
        vector<int> c;
        for (int i = n, w = W; i >= 1; i--)
        {
            if (p[i][w])
            {
                c.pb(items[i - 1].idx);
                w -= items[i - 1].w;
            }
        }
        reverse(all(c));
        cout << v << "\n"
             << c.size() << "\n";
        for (int x : c)
            cout << x << " ";
        cout << "\n";
        return;
    }

    const int INF = 1e18;
    int maxV = (int)sum_v;
    vector<vector<int>> d(n + 1, vector<int>(maxV + 1, INF));
    vector<vector<int>> r(n + 1, vector<int>(maxV + 1, 0));
    d[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int v = 0; v <= maxV; v++)
        {
            d[i][v] = d[i - 1][v];
            r[i][v] = 0;
            if (v >= items[i - 1].v)
            {
                int cand = d[i - 1][v - items[i - 1].v] + items[i - 1].w;
                if (cand < d[i][v])
                {
                    d[i][v] = cand;
                    r[i][v] = 1;
                }
            }
        }
    }
    int bV = 0;
    for (int v = 0; v <= maxV; v++)
    {
        if (d[n][v] <= W)
            bV = v;
    }
    vector<int> ch;
    for (int i = n, v = bV; i >= 1; i--)
    {
        if (r[i][v])
        {
            ch.pb(items[i - 1].idx);
            v -= items[i - 1].v;
        }
    }
    reverse(all(ch));
    cout << bV << "\n"
         << ch.size() << "\n";
    for (int x : ch)
        cout << x << " ";
    cout << "\n";
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
