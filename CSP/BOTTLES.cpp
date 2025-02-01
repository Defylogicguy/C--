/*************************
  Author: Defy logic guy
  21:12:25 - 23/01/2025
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
#define NAME "BOTTLES"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> dp(n + 2, LLONG_MAX);
    dp[0] = 0;

    deque<int> dq;
    dq.pb(0);
    for (int i = 1; i <= n + 1; i++)
    {
        while (dq.size() and dq.front() < i - k)
            dq.pop_front();
        dp[i] = dp[dq.front()] + (i < n + 1 ? a[i - 1] : 0);
        while (dq.size() and dp[dq.back()] >= dp[i])
            dq.pop_back();
        dq.pb(i);
    }

    cout << accumulate(all(a), 0ll) - dp[n + 1] << endl;
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
