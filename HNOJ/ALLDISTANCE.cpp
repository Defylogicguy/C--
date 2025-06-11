/*************************
  Author: Defy logic guy
  10:10:03 - 04/06/2025
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
#define endl '\n'
#define NAME "ALLDISTANCE"

vector<int> g, f, dp;

void dfs1(int u, int p, const vector<vector<int>> &a)
{
    g[u] = 1;
    for (int v : a[u])
    {
        if (v == p)
            continue;
        dfs1(v, u, a);
        g[u] += g[v];
        f[u] += f[v] + g[v];
    }
}

void df2(int u, int p, const vector<vector<int>> &a)
{
    for (int v : a[u])
    {
        if (v == p)
            continue;
        dp[v] = dp[u] + g[1] - 2 * g[v];
        df2(v, u, a);
    }
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    g.resize(n + 1), f.resize(n + 1), dp.resize(n + 1);
    dfs1(1, -1, adj);
    dp[1] = f[1];
    df2(1, -1, adj);
    for (int i = 1; i <= n; i++)
        cout << dp[i] << ' ';
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
