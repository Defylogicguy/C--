/*************************
  Author: Defy logic guy
  23:10:07 - 11/03/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "SANANDREAS"

vector<vector<int>> adj;
vector<int> ans;
vector<bool> vis;
int n, m, s, e;

bool dfs(int x, vector<int> &path)
{
    if (x == e)
    {
        ans = path;
        return true;
    }

    for (int i : adj[x])
    {
        if (!vis[i])
        {
            vis[i] = true;
            path.pb(i);
            if (dfs(i, path))
                return true;
            vcois[i] = false;
            path.pop_back();
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m >> s >> e;
    s--, e--;
    adj.resize(n);
    vis.assign(n, false);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vis[s] = true;
    vector<int> path = {s};
    if (dfs(s, path))
        for (int i : ans)
            cout << i + 1 << " ";
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