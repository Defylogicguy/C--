/*************************
  Author: Defy logic guy
  21:44:04 - 10/03/2025
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
#define NAME "ROPEWAY2"

vector<vector<int>> adj;
vector<bool> check;

void dfs(int x)
{
    check[x] = true;
    for (int i : adj[x])
        if (!check[i])
            dfs(i);
}

void solve()
{
    int n, m, t;
    cin >> n >> m >> t;
    adj.resize(max(n, t));
    check.resize(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[v].pb(u);
    }

    dfs(t - 1);
    for (int i = 0; i < n; i++)
        if (!check[i])
        {
            dfs(i);
            check[i] = false;
        }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += !check[i];
    cout << cnt;
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
