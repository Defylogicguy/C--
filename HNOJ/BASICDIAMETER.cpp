/*************************
  Author: Defy logic guy
  11:01:46 - 19/04/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "BASICDIAMETER"

vector<vector<int>> adj;
vector<int> d;

void dfs(int u, int p)
{
    d[u] = d[p] + 1;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (d[v] == -1)
            dfs(v, u);
    }
}

void solve()
{
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    d.assign(n + 1, -1);
    dfs(1, 0);
    int mx = 0, node = 0;
    for (int i = 1; i <= n; i++)
        if (d[i] > mx)
            mx = d[i], node = i;
    d.assign(d.size(), -1);
    dfs(node, 0);
    mx = 0;
    for (int i = 1; i <= n; i++)
        mx = max(mx, d[i]);
    cout << mx << endl;
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
