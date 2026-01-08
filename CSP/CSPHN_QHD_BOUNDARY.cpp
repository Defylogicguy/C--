/*************************
  Author: Defy logic guy
  13:18:05 - 22/02/2025
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
#define NAME "CSPHN_QHD_BOUNDARY"

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n;i ++)
        cin >> a[i].first >> a[i].second;

    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = a[0].first;
    dp[0][1] = a[0].second;

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + abs(a[i - 1].second - a[i].second), dp[i - 1][1] + abs(a[i - 1].first - a[i].second)) + a[i].first;
        dp[i][1] = max(dp[i - 1][1] + abs(a[i - 1].first - a[i].first), dp[i - 1][0] + abs(a[i - 1].second - a[i].first)) + a[i].second;
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
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

    while (tt--)
        solve();
    return 0;
}
