/*************************
  Author: Defy logic guy
  22:13:23 - 11/03/2025
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
#define NAME "COSTGRAPH"

vector<vector<int>> adj;
vector<int> val;
int n;

bool f(int mid)
{
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;

    while (q.size())
    {
        int u = q.front();
        q.pop();

        if (u == n - 1)
            return true;

        for (int v : adj[u])
            if (!vis[v] && abs(val[u] - val[v]) <= mid)
            {
                vis[v] = true;
                q.push(v);
            }
    }
    return false;
}

void solve()
{
    int m;
    cin >> n >> m;

    val.resize(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];

    adj.resize(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }

    int l = 0, r = 1e18;
    int ans = 0;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (f(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << ans << endl;
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