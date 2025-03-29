/*************************
  Author: Defy logic guy
  10:34:09 - 20/03/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "TRAIQUANSU"

void solve()
{
    int n, m, b, r;
    cin >> n >> m >> b >> r;
    queue<int> q;
    vector<int> d(n, -1);
    for (int i = 0; i < b; i++)
    {
        int x;
        cin >> x;
        q.push(--x);
        d[x] = 0;
    }

    vector<int> st(r);
    for (int i = 0; i < r; i++)
    {
        cin >> st[i];
        st[i]--;
    }

    vector<vector<int>> adj(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[--u].pb(--v);
        adj[v].pb(u);
    }

    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (d[v] == -1)
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
    }

    for (int i = 0; i < r; i++)
        cout << d[st[i]] << ' ';
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
