/*************************
  Author: Defy logic guy
  08:47:49 - 12/04/2025
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
#define NAME "DIJKSTRA_KFREE"

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    vector<vector<int>> d(n + 1, vector<int>(k + 1, LLONG_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    d[1][0] = 0;
    pq.push({0, 1, 0});

    while (pq.size())
    {
        auto [l, u, ud] = pq.top();
        pq.pop();

        if (l > d[u][ud])
            continue;

        for (auto [v, w] : adj[u])
        {
            if (d[v][ud] > l + w)
            {
                d[v][ud] = l + w;
                pq.push({d[v][ud], v, ud});
            }
            if (ud < k && d[v][ud + 1] > l)
            {
                d[v][ud + 1] = l;
                pq.push({d[v][ud + 1], v, ud + 1});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int ans = LLONG_MAX;
        for (int j = 0; j <= k; j++)
            ans = min(ans, d[i][j]);
        cout << ans << " ";
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
