/*************************
  Author: Defy logic guy
  19:08:58 - 25/07/2025
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
#define NAME "FRIENDS"

void solve()
{
    int f, r, n, m;
    cin >> f >> r >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    int sum = 0;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        a[u][v] += w;
        a[v][u] += w;
        sum += w;
    }
    int M = 1 << n;
    vector<int> dp(M, sum * r), v(M,-1);
    for (int i = 0; i < M; i++)
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
                continue;
            for (int k = 0; k < n; k++)
            {
                if ((i >> k & 1) or !a[j][k])
                    continue;
                int nw = i | (1 << j) | (1 << k);
                if (dp[nw] > dp[i] - a[j][k] * (r - f))
                {
                    dp[nw] = dp[i] - a[j][k] * (r - f);
                    v[nw] = i;
                }
            }
        }
    int t = min_element(all(dp)) - dp.begin();
    vector<int> idk;
    idk.pb(t);
    while (v[t] != -1)
        idk.pb(v[t]), t = v[t];
    reverse(all(idk));
    cout << minall(dp) << '\n';
    for (int i = 1; i < idk.size(); i++)
    {
        int x = idk[i];
        x ^= idk[i - 1];
        int j = 0;
        for (; j < M; j++)
            if (x >> j & 1)
            {
                cout << j + 1 << ' ';
                break;
            }
        j++;
        for (; j < M; j++)
            if (x >> j & 1)
            {
                cout << j + 1 << ' ';
                break;
            }
        cout << '\n';
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
