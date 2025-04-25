/*************************
  Author: Defy logic guy
  09:30:04 - 19/04/2025
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
#define NAME "TRI"

void solve()
{
    int n, m;
    cin >> n >> m;
    if (m != n - 1)
    {
        cout << "No";
        return;
    }
    
    vector<vector<int>> adj(n + 1);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<bool> vis(n + 1, false);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            cout << "No";
            return;
        }
    cout << "Yes";
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
