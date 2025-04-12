/*************************
  Author: Defy logic guy
  09:38:27 - 12/04/2025
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
#define NAME "DIJKSTRA_RESEACH"
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
    }

    vector<int> d(n + 1, LLONG_MAX);
    d[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
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
                pq.push({d[v], v});
            }
    }

    int cnt = 0, minn = LLONG_MAX, maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == d[n])
            cnt++;
        minn = min(minn, d[i]);
        maxx = max(maxx, d[i]);
    }

    cout << d[n] << " " << cnt % MOD << " " << minn << " " << maxx << endl;

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
