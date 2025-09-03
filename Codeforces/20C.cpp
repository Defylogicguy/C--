/*************************
  Author: Defy logic guy
  15:37:13 - 03/09/2025
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
#define NAME "20C"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    heap<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> d(n + 1, LLONG_MAX), p(n + 1, -1);
    d[1] = 0;
    pq.push({0, 1});
    while (pq.size())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto v : adj[u])
            if (d[u] + v.second < d[v.first])
            {
                d[v.first] = d[u] + v.second;
                p[v.first] = u;
                pq.push({d[v.first], v.first});
            }
    }
    if (d[n] == LLONG_MAX)
    {
        cout << -1;
        return;
    }
    vector<int> path;
    for (int u = n; u != -1; u = p[u])
        path.pb(u);
    reverse(all(path));
    for (auto v : path)
        cout << v << " ";
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
