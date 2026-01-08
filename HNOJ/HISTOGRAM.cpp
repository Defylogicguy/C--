/*************************
 Author: Defy logic guy
20:24:34 - 23/07/2025
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
#define NAME "HISTOGRAM"

void solve(int n)
{
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int M = (1 << n);
    vector<vector<pair<int, int>>> dp(M, vector<pair<int, int>>(n, make_pair(LLONG_MIN, 0)));

    for (int i = 0; i < n; i++)
        dp[1 << i][i] = {a[i], 1};

    for (int i = 0; i < M; i++)
        for (int j = 0; j < n; j++)
        {
            if (!((i >> j) & 1))
                continue;

            for (int k = 0; k < n; k++)
            {
                if ((i >> k) & 1)
                    continue;
                if (dp[i | (1 << k)][k].first < dp[i][j].first + abs(a[k] - a[j]))
                    dp[i | (1 << k)][k] = {dp[i][j].first + abs(a[k] - a[j]), dp[i][j].second};
                else if (dp[i | (1 << k)][k].first == dp[i][j].first + abs(a[k] - a[j]))
                    dp[i | (1 << k)][k].second += dp[i][j].second;
            }
        }

    int mx = LLONG_MIN, cnt = 0;
    for (int i = 0; i < n; ++i)
        if ((dp[M - 1][i].first + a[i]) > mx)
        {
            mx = dp[M - 1][i].first + a[i];
            cnt = dp[M - 1][i].second;
        }
        else if ((dp[M - 1][i].first + a[i]) == mx)
            cnt += dp[M - 1][i].second;

    mx += n * 2;
    cout << mx << ' ' << cnt << '\n';
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

    while (cin >> tt)
    {
        if (!tt)
            break;
        solve(tt);
    }
    return 0;
}
