/*************************
  Author: Defy logic guy
  09:54:07 - 16/02/2025
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
#define NAME "IDK"

void sub1(int n, int W, const vector<int> &w, const vector<int> &v, const vector<int> &a, const vector<int> &b)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= W; j++)
        {
            dp[i][j] = dp[i - 1][j];
            for (int u = 0; u <= j / w[i]; u++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - u * w[i]] + u * v[i] - a[i] * u * u + b[i] * (u > 0));
        }

    cout << dp[n][W] << endl;
}

void sub2(int n, int W, const vector<int> &w, const vector<int> &v, const vector<int> &a, const vector<int> &b)
{
    vector<int> dp(W + 1, 0);
    for (int i = 1; i <= n; i++)
        for (int j = w[i]; j <= W; j++)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[W] << endl;
}

void solve()
{
    int n, W;
    cin >> n >> W;

    bool flag = true;
    vector<int> w(n + 1), v(n + 1), a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i] >> b[i] >> a[i];
        if (a[i] != 0 or b[i] != 0)
            flag = false;
    }

    if (flag)
        sub2(n, W, w, v, a, b);
    else if (n <= 100 and W <= 100)
        sub1(n, W, w, v, a, b);
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
