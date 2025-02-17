/*************************
  Author: Defy logic guy
  15:25:43 - 15/02/2025
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
#define NAME "CSPHN_PEACH"

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;

    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
    {
        int t, k;
        cin >> t >> k;
        if (a <= t and t <= b)
            p.pb({t, k});
    }

    sort(all(p));
    int ans = 0, cur = 0;
    heap<int> pq;
    for (int i = a; i < b; i++)
    {
        while (cur < p.size() and p[cur].first == i)
        {
            pq.push(p[cur].second);
            cur++;
        }

        if (pq.size())
        {
            ans += pq.top();
            pq.pop();
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
