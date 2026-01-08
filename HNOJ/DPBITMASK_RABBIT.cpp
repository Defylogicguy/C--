/*************************
 Author: Defy logic guy
14:49:40 - 25/07/2025
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
#define NAME "DPBITMASK_RABBIT"

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int M = (1 << n);
    vector<int> dp(M, 0), c(M, 0);
    for (int i = 1; i < M; i++)
    {
        int lsb = __builtin_ctzll(i);
        int p = i ^ (1 << lsb);
        c[i] = c[p];
        for (int j = 0; j < n; j++)
            if ((p >> j) & 1ll)
                c[i] += a[lsb][j];
    }
    for (int i = 1; i < M; i++)
    {
        int ans = LLONG_MIN;
        int lsb = __builtin_ctzll(i);
        int tmp = i;
        for (; tmp; tmp = (tmp - 1) & i)
        {
            if (!((tmp >> lsb) & 1ll))
                continue;
            ans = max(ans, c[tmp] + dp[i ^ tmp]);
        }
        dp[i] = ans;
    }
    cout << dp[M - 1];
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
