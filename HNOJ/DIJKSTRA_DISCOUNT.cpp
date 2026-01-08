/*************************
  Author: Defy logic guy
  11:27:39 - 05/04/2025
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
#define NAME "DIJKSTRA_DISCOUNT"

struct node
{
    int u;
    bool c;
};

struct cmp
{
    bool operator()(const pair<int, node> &a, const pair<int, node> &b)
    {
        return a.first > b.first;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<vector<pair<node, int>>>> adj(n + 1, vector<vector<pair<node, int>>>(2));

    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][0].pb({{v, 0}, w});
        adj[u][0].pb({{v, 1}, w / 2}); 
        adj[u][1].pb({{v, 1}, w});
    }

    heap<pair<int, node>, vector<pair<int, node>>, cmp> pq;
    vector<vector<int>> d(n + 1, vector<int>(2, LLONG_MAX));
    d[1][0] = 0;
    pq.push({0, {1, 0}});

    while (pq.size())
    {
        auto tp = pq.top();
        pq.pop();
        int cur = tp.first;
        int u = tp.second.u;
        int idk = tp.second.c;
        if (cur != d[u][idk])
            continue;
        for (auto &v : adj[u][idk])
        {
            node nxt = v.first;
            int w = v.second;
            if (cur + w < d[nxt.u][nxt.c])
            {
                d[nxt.u][nxt.c] = cur + w;
                pq.push({d[nxt.u][nxt.c], nxt});
            }
        }
    }

    cout << min(d[n][0], d[n][1]) << endl;
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
