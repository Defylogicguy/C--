/*************************
  Author: Defy logic guy
  22:02:28 - 11/04/2025
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
#define NAME "DIJKSTRA_LIBERTY"

struct node
{
    int u, v, w, h;
};

int n, m, s, t;
vector<node> edges;

auto build(int th)
{
    vector<vector<pair<int, int>>> adj(n + 1);
    for (auto &e : edges)
        if (e.h >= th)
            adj[e.u].pb({e.v, e.w}), adj[e.v].pb({e.u, e.w});
    return adj;
}

pair<vector<int>, vector<int>> dijkstra(const vector<vector<pair<int, int>>> &adj)
{
    vector<int> d(n + 1, LLONG_MAX), par(n + 1, -1);
    heap<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[s] = 0;
    pq.push({0, s});

    while (pq.size())
    {
        auto [dist, u] = pq.top();
        pq.pop();
        if (dist > d[u])
            continue;

        for (auto &[v, w] : adj[u])
            if (d[u] + w < d[v])
                pq.push({d[v] = d[u] + w, v}), par[v] = u;
    }
    return {d, par};
}

void solve()
{
    cin >> n >> m >> s >> t;
    edges.resize(m);
    int maxn = 0;

    for (auto &e : edges)
    {
        cin >> e.u >> e.v >> e.w >> e.h;
        maxn = max(maxn, e.h);
    }

    int l = 1, r = maxn, ans = -1;
    vector<int> part;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        auto [d, p] = dijkstra(build(mid));
        if (d[t] != LLONG_MAX)
            ans = mid, part = p, l = mid + 1;
        else
            r = mid - 1;
    }

    vector<int> path = {t};
    while (part[path.back()] != -1)
        path.pb(part[path.back()]);
    reverse(all(path));
    cout << ans << endl;
    for (int i : path)
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
