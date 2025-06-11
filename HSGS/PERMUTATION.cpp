/*************************
  Author: Defy logic guy
  10:21:53 - 11/06/2025
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
#define NAME "PERMUTATION"

void dfs(int u, int idx, const vector<vector<int>> &adj, vector<int> &g)
{
    g[u] = idx;
    for (auto v : adj[u])
        if (!g[v])
            dfs(v, idx, adj, g);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        int u = i + 1;
        if ((u == 1 and v == 2) or (u == 2 and v == 1) or (u == v))
            continue;
        adj[u].pb(v);
    }
    adj[1].pb(2);
    adj[2].pb(1);

    vector<int> g(n + 1, 0);
    int idx = 1;
    for (int i = 1; i <= n; i++)
        if (!g[i])
            dfs(i, idx++, adj, g);
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << (g[u] == g[v] ? "Yes" : "No") << endl;
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
