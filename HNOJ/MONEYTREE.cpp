/*************************
  Author: Defy logic guy
  20:47:41 - 24/05/2025
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
#define NAME "MONEYTREE"

vector<pair<int, int>> rg;
vector<vector<int>> tree, dp;

void dfs(int u, int p)
{
    dp[u][0] = dp[u][1] = 0;

    for (int v : tree[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
        dp[u][0] += max(abs(rg[u].first - rg[v].first) + dp[v][0], abs(rg[u].first - rg[v].second) + dp[v][1]);
        dp[u][1] += max(abs(rg[u].second - rg[v].first) + dp[v][0], abs(rg[u].second - rg[v].second) + dp[v][1]);
    }
}

void solve()
{
    int n;
    cin >> n;
    rg.resize(n + 1), tree.resize(n + 1), dp.assign(n + 1, vector<int>(2, 0));
    for (int i = 1; i <= n; i++)
        cin >> rg[i].first >> rg[i].second;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << endl;
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
