/*************************
  Author: Defy logic guy
  20:13:30 - 11/03/2025
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
#define NAME "THREEMOVE"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
    }

    vector<vector<int>> newadj(n);
    for (int i = 0; i < n; i++)
    {
        set<int> s;
        for (int j : adj[i])
            for (int k : adj[j])
                for (int l : adj[k])
                    if (l != i && l != j && l != k)
                        s.insert(l);
        newadj[i] = vector<int>(all(s));
    }
    adj = newadj;

    int st, end;
    cin >> st >> end;
    if (st == end)
    {
        cout << 0 << endl;
        return;
    }
    queue<int> q;
    q.push(st - 1);
    vector<int> d(n, LLONG_MAX);
    d[st - 1] = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (v == end - 1)
            {
                cout << d[u] + 1 << endl;
                return;
            }
            if (d[v] > d[u] + 1)
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    cout << -1 << endl;
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