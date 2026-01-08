/*************************
  Author: Defy logic guy
  09:32:06 - 12/04/2025
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
#define NAME "MONEYROADS"

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<tuple<int, int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, l, t;
        cin >> u >> v >> l >> t;
        adj[u].pb({v, l, t});
    }

    vector<vector<int>> d(n + 1, vector<int>(k + 1, LLONG_MAX));
    heap<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, 0, 1}); // l, t, u
    while (pq.size())
    {
        auto [l, t, u] = pq.top();
        pq.pop();
        if (l > d[u][t])
            continue;
        for (auto [v, vl, vt] : adj[u])
        {
            if (t + vt > k)
                continue;
            if (l + vl < d[v][t + vt])
            {
                d[v][t + vt] = l + vl;
                pq.push({d[v][t + vt], t + vt, v});
            }
        }
    }

    int ans = LLONG_MAX;
    for (int i = 0; i <= k; i++)
        ans = min(ans, d[n][i]);
    cout << (ans == LLONG_MAX ? -1 : ans);
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
