/*************************
  Author: Defy logic guy
  21:01:25 - 10/02/2025
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
#define NAME "CSPHN_MKNAPSACK"

void solve()
{
    int n, m;
    cin >> n >> m;
    heap<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        pq.push({v, u});
    }

    multiset<int> q;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        q.insert(x);
    }

    int ans = 0;
    while (!pq.empty())
    {
        pair<int, int> idk = pq.top();
        pq.pop();
        auto it = q.lower_bound(idk.second);
        if (it != q.end())
        {
            ans += idk.first;
            q.erase(it);
        }
    }

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
