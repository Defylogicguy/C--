/*************************
  Author: Defy logic guy
  21:16:44 - 10/03/2025
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
#define NAME "BIOCOLORING"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    vector<int> color(n, -1);
    color[0] = 0;
    queue<int> q;
    q.push(0);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int v : graph[u])
        {
            if (color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (color[v] == color[u])
            {
                cout << "NOT BICOLORABLE.\n";
                return;
            }
        }
    }
    cout << "BICOLORABLE.\n";
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
    cin >> tt;

    cin.ignore();
    while (tt--)
        solve();
    return 0;
}
