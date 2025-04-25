/*************************
  Author: Defy logic guy
  09:45:47 - 19/04/2025
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
#define NAME "BASICTREE_SUBORDINATES"

vector<vector<int>> adj;
vector<int> d;

int dfs(int u)
{
    int cnt = 0;
    for (int v : adj[u])
        cnt += 1 + dfs(v);
    d[u] = cnt;
    return cnt;
}

void solve()
{
    int n;
    cin >> n;
    d.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 2; i <= n; i++)
    {
        int u;
        cin >> u;
        adj[u].pb(i); 
    }

    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << d[i] << ' ';
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
