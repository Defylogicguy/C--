/*************************
  Author: Defy logic guy
  10:14:13 - 12/04/2025
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
#define NAME "PCOLOR"

void solve()
{
    int n, l, r, c;
    cin >> n >> l >> r >> c;
    int s, e;
    cin >> s >> e;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    unordered_map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++)
        mp[a[i]].pb(i);

    vector<int> dis(n + 1, LLONG_MAX);
    dis[s] = 0;
    heap<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    unordered_map<int, bool> vis;

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d != dis[u])
            continue;
        if (u == e)
            break;

        if (u > 1 && dis[u - 1] > d + l)
        {
            dis[u - 1] = d + l;
            pq.push({dis[u - 1], u - 1});
        }
        if (u < n && dis[u + 1] > d + r)
        {
            dis[u + 1] = d + r;
            pq.push({dis[u + 1], u + 1});
        }

        int col = a[u];
        if (!vis[col])
        {
            vis[col] = true;
            for (int v : mp[col])
            {
                if (v == u)
                    continue;
                if (dis[v] > d + c)
                {
                    dis[v] = d + c;
                    pq.push({dis[v], v});
                }
            }
        }
    }

    cout << (dis[e] == LLONG_MAX ? -1 : dis[e]);
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
