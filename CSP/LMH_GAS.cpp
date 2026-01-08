/*************************
  Author: Defy logic guy
  15:08:53 - 05/07/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "LMH_GAS"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    deque<pair<int, int>> dq;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        while (dq.size() and dq.back().second >= x)
        {
            k += dq.back().first;
            dq.pop_back();
        }
        dq.pb({k, x});
        ans += dq.front().second;
        if (!--dq.front().first)
            dq.pop_front();
        k = 1;
    }
    cout << ans;
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
