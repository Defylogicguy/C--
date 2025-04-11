/*************************
  Author: Defy logic guy
  16:28:26 - 05/04/2025
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
#define NAME "SGRAPH"

struct node
{
    int idx, v, w;
};

struct cmp
{
    bool operator()(const node &a, const node &b)
    {
        return a.w > b.w;
    }
};

void dijkstra(int st, vector<vector<pair<int, int>>> &adj, vector<int> &d)
{
    d[st] = 0;
    heap<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});

    while (pq.size())
    {
        int k = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d[u] < k)
            continue;

        for (auto [v, w] : adj[u])
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1), radj(n + 1);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        radj[v].pb({u, w});
    }

    vector<int> d(n + 1, LLONG_MAX);
    dijkstra(1, adj, d);

    vector<int> rd(n + 1, LLONG_MAX);
    dijkstra(1, radj, rd);

    for (int i = 2; i <= n; i++)
        cout << (d[i] == LLONG_MAX or rd[i] == LLONG_MAX ? -1 : d[i] + rd[i]) << endl;
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