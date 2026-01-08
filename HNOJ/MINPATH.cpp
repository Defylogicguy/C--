/*************************
  Author: Defy logic guy
  11:12:47 - 08/03/2025
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
#define NAME "MINPATH"

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        a[u].pb(v);
        a[v].pb(u);
    }

    vector<int> d(n + 1, LLONG_MAX);

    vector<int> query(k);
    for (int i = 0; i < k; i++)
    {
        cin >> query[i];
        query[i]--;
    }

    int b;
    cin >> b;
    b--;
    queue<int> q;
    q.push(b);
    d[b] = 0;
    while (q.size())
    {
        int cur = q.front();
        q.pop();

        for (int i : a[cur])
        {
            if (d[i] > d[cur] + 1)
            {   
                d[i] = d[cur] + 1;
                q.push(i);
            }
        }
    }

    for (int i : query)
        cout << (d[i] == LLONG_MAX ? -1 : d[i]) << ' ';
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
