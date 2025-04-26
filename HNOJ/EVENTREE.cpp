/*************************
  Author: Defy logic guy
  23:09:53 - 25/04/2025
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
#define NAME "EVENTREE"

void solve()
{
    int n;
    cin >> n;
    if (n & 1)
    {
        cout << -1;
        return;
    }

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    stack<int> st;
    st.push(1);
    vector<int> q, par(n + 1, 0);
    while (st.size())
    {
        int u = st.top();
        st.pop();
        q.pb(u);
        for (int v : adj[u])
        {
            if (v == par[u])
                continue;
            par[v] = u;
            st.push(v);
        }
    }

    vector<int> sz(n + 1, 1);
    int cnt = 0;
    for (int i = n - 1; i > 0; i--)
    {
        int u = q[i];
        if (sz[u] % 2 == 0)
            cnt++;
        sz[par[u]] += sz[u];
    }
    cout << cnt;
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
