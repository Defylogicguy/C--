/*************************
  Author: Defy logic guy
  10:18:25 - 05/04/2025
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
#define NAME "DIJKSTRA_DUTIEC"

void solve()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    vector<int> d(n + 1, INT_MAX);
    vector<int> par(n + 1, -1);
    heap<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        int u = pq.top().second;
        int v = pq.top().first;
        pq.pop();
        if (d[u] < v)
            continue;
        for (auto [v, w] : adj[u])
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                par[v] = u;
                pq.push({d[v], v});
            }
    }

    cout << d[t] << endl;
    vector<int> a;
    while (t != -1)
    {
        a.pb(t);
        t = par[t];
    }
    reverse(all(a));
    for (int i : a)
        cout << i << ' ';
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
