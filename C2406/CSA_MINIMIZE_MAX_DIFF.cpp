/*************************
  Author: Defy logic guy
  22:48:23 - 01/02/2025
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
#define NAME "CSA_MINIMIZE_MAX_DIFF"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; i++)
        d[i] = a[i + 1] - a[i];
    int sz = n - k - 1;
    deque<int> dq;
    int ans = INT_MAX;

    for (int i = 0; i < sz; i++)
    {
        while (dq.size() and d[dq.back()] <= d[i])
            dq.pop_back();
        dq.pb(i);
    }

    for (int i = sz; i < n - 1; i++)
    {
        ans = min(ans, d[dq.front()]);
        if (dq.size() and dq.front() <= i - sz)
            dq.pop_front();
        while (dq.size() and d[dq.back()] <= d[i])
            dq.pop_back();
        dq.pb(i);
    }
    ans = min(ans, d[dq.front()]);
    cout << ans << '\n';
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
