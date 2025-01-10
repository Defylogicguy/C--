/*************************
  Author: Defy logic guy
  21:39:35 - 07/01/2025
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
#define NAME "SL447"

void solve()
{
    int n, l;
    cin >> n>> l;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    
    vector<int> dp(n + 1, LLONG_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int _max = 0, cur = 0;
        for (int j = i; j > 0; j--)
        {
            cur += a[j].second;
            if (cur > l)
                break;
            _max = max(_max, a[j].first);
            dp[i] = min(dp[i], dp[j - 1] + _max);
        }
    }

    cout << dp[n] << endl;
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
