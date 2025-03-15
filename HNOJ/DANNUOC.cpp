/*************************
  Author: Defy logic guy
  23:22:48 - 10/03/2025
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
#define NAME "DANNUOC"

vector<vector<int>> adj;
void solve()
{
    int n, c;
    cin >> n >> c;
    adj.resize(n);

    for (int i = 0; i < c; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--, z--;
        adj[x].pb(y);
        adj[x].pb(z);
    }

    vector<int> d(n, LLONG_MAX);
    d[0] = 1;
    queue<int> q;
    q.push(0);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            d[v] = min(d[v], d[u] + 1);
            q.push(v);
        }
    }
    for (int i : d)
        cout << i << '\n';
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
