/*************************
  Author: Defy logic guy
  16:28:26 - 05/04/2025
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
#define NAME "SGRAPH"

void solve()
{
    int n , m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1), radj(n + 1);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        radj[v].pb({u, w});
    }

    vector<int> d(n + 1, LLONG_MAX), rd(n + 1, LLONG_MAX);
    
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
