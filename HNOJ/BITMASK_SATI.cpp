/*************************
  Author: Defy logic guy
  19:52:52 - 25/07/2025
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
#define NAME "BITMASK_SATI"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> cnt(n, vector<int>(10));
    vector<bool> b(n);
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        if (!x)
            cnt[i][0] = 1;
        while (x)
        {
            cnt[i][x % 10]++;
            x /= 10;
        }
        for (int j = 0; j < 10; j++)
            if (cnt[i][j] > 2)
            {
                b[i] = true;
                break;
            }
    }
    auto f = [&](int a, vector<int> v) -> int
    {
        int ans = 0;
        int x = 1;
        for (int i = 0; i < 10; i++)
        {
            if (((a / x) % 3 + v[i]) > 2)
                return -1;
            ans += ((a / x) % 3 + v[i]) * x;
            x *= 3;
        }
        return ans;
    };
    vector<int> dp(60000, LLONG_MIN);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i])
            continue;
        for (int j = 60000; j >= 0; j--)
        {
            if (dp[j] == LLONG_MIN)
                continue;
            int tmp = f(j, cnt[i]);
            if (tmp >= 0)
                dp[tmp] = max(dp[tmp], dp[j] + a[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < 60000; i++)
        ans = max(ans, dp[i]);
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
