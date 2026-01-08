/*************************
  Author: Defy logic guy
  14:25:07 - 29/08/2025
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
#define NAME "KMATRIX"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].pb(v - 1);
        deg[v - 1]++;
    }
    queue<int > q;
    for (int i = 0; i < n; i++)
        if (!deg[i])
            q.push(i);
    vector<int> dp(n, 0);
    int cnt = 0;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        cnt++;
        for (int v : adj[t])
        {
            dp[v] = max(dp[v], dp[t] + 1);
            deg[v]--;
            if (!deg[v])
                q.push(v);
        }
    }
    if (cnt < n)
    {
        cout << -1;
        return;
    }
    cout << maxall(dp) + 1;
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
