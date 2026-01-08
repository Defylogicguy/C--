/*************************
  Author: Defy logic guy
  11:13:52 - 12/04/2025
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
#define NAME "BEUTYROADS"

const int maxn = 2e5 + 5;

struct edge
{
    int u, v, l, b;
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<edge>> adj(n + 1);
    vector<vector<int>> d(n + 1, vector<int>(11, LLONG_MAX)), b(n + 1, vector<int>(11, 0));
    adj.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        edge e;
        cin >> e.u >> e.v >> e.l >> e.b;
        adj[e.u].pb(e);
        adj[e.v].pb({e.v, e.u, e.l, e.b});
    }
    heap<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    d[1][0] = 0;

    while (pq.size())
    {
        int u = pq.top().second;
        int v = pq.top().first;
        pq.pop();
        if (d[u][0] < v)
            continue;
        for (auto e : adj[u])
        {
            if (d[u][0] + e.l < d[e.v][0])
            {
                d[e.v][0] = d[u][0] + e.l;
                b[e.v][0] = b[u][0] + e.b;
                pq.push({d[e.v][0], e.v});
            }
            if (d[u][0] + e.l == d[e.v][0])
                b[e.v][0] = max(b[e.v][0], b[u][0] + e.b);
        }
    }

    int one = d[n][0], two = 0;
    for (int i = 0; i <= 10; i++)
        if (d[n][i] != LLONG_MAX)
            two = max(two, b[n][i]);

    if (one == LLONG_MAX)
        cout << -1;
    else
        cout << one << " " << two;
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
