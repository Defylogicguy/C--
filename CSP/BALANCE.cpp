/*
 Author: Defy logic guy
 22:15:33 - 29/12/2024
*/
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
#define NAME "Skibidi"

void solve()
{
    int n, m;
    cin >> n >> m;

    int idk = n * (n + 1) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(2 * idk + 1, 0));

    dp[0][idk] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 2 * idk; j++)
            if (dp[i - 1][j] > 0)
            {
                dp[i][j + i] = (dp[i][j + i] + dp[i - 1][j]) % MOD;
                dp[i][j - i] = (dp[i][j - i] + dp[i - 1][j]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }

    cout << dp[n][m + idk] % MOD << endl;
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
