/*************************
  Author: Defy logic guy
  10:12:51 - 19/04/2025
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
#define NAME "RUNW"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    stack<pair<int, int>> st;
    vector<int> dist(n + 1, -1);
    st.push({1, 0});
    dist[1] = 0;
    while (!st.empty())
    {
        int u = st.top().first;
        int d = st.top().second;
        st.pop();
        for (int v : adj[u])
            if (dist[v] == -1)
            {
                dist[v] = d + 1;
                st.push({v, dist[v]});
            }
    }
    sort(rall(dist));
    int ans = 0;
    for (int i = 0; i < k; i++)
        ans += dist[i];
    cout << ans << endl;
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
