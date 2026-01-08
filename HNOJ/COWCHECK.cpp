/*************************
  Author: Defy logic guy
  09:49:54 - 01/03/2025
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
#define NAME "COWCHECK"

int dist(pair<int, int> a, pair<int, int> b)
{
    int one = a.first - b.first;
    int two = a.second - b.second;
    return (one * one) + (two * two);
}

void solve()
{
    int h, g;
    cin >> h >> g;
    vector<pair<int, int>> hol(h), gue(g);
    for (int i = 0; i < h; i++)
        cin >> hol[i].first >> hol[i].second;
    for (int i = 0; i < g; i++)
        cin >> gue[i].first >> gue[i].second;

    vector<vector<vector<int>>> dp(h + 1, vector<vector<int>>(g + 1, vector<int>(2, 1e18)));
    dp[1][0][0] = 0;
    for (int i = 0; i <= h; i++)
        for (int j = 0; j <= g; j++)
        {
            if (i >= 2)
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] + dist(hol[i - 2], hol[i - 1]));
            if (j >= 2)
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + dist(gue[j - 2], gue[j - 1]));
            if (i >= 1 and j >= 1)
            {
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + dist(hol[i - 1], gue[j - 1]));
                dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + dist(hol[i - 1], gue[j - 1]));
            }
        }
    cout << dp[h][g][0] << endl;
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
