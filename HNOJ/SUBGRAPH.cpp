/*************************
  Author: Defy logic guy
  08:41:14 - 02/06/2025
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
#define NAME "SUBGRAPH"

vector<int> dp;
int ans = 0, n;

int dfs(int u, int p, vector<vector<int>> &adj)
{
    dp[u] = 1;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        int sz = dfs(v, u, adj);
        ans = (ans + sz * (n - sz)) % MOD;
        dp[u] += sz;
    }
    return dp[u];
}

void solve()
{
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dp.assign(n + 1, 0);
    ans = 0;
    dfs(1, -1, adj);
    cout << (ans + n) % MOD << endl;
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
