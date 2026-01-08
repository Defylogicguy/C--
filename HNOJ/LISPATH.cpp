/*************************
  Author: Defy logic guy
  13:43:39 - 10/06/2025
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
#define NAME "LISPATH"

void dfs(int u, int p, vector<int> &a, vector<int> &ans, vector<int> &lis, vector<vector<int>> &adj)
{
    int x = lower_bound(all(lis), a[u]) - lis.begin();
    int o = -1;
    bool flag = false;

    if (x == lis.size())
    {
        lis.pb(a[u]);
        flag = true;
    }
    else
    {
        o = lis[x];
        lis[x] = a[u];
    }

    ans[u] = lis.size();

    for (int v : adj[u])
        if (v != p)
            dfs(v, u, a, ans, lis, adj);

    if (flag)
        lis.pop_back();
    else
        lis[x] = o;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<int> lis, ans(n + 1, 0);
    dfs(1, -1, a, ans, lis, adj);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;
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
