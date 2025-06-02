/*************************
  Author: Defy logic guy
  15:43:27 - 02/06/2025
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
#define endl '\n'
#define NAME "CONTEST10_BONUS"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, LLONG_MIN));
    dp[0][0] = 0;
    for (int j = 0; j <= n; j++)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i - 1];
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            if (j > c[i - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i - 1]] + sum);
                sum = 0;
            }
        }
    }
    int ans = LLONG_MIN;
    for (int i = 0; i <= n; i++)
        ans = max(ans, dp[n][i]);
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
