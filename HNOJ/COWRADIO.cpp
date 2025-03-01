/*************************
  Author: Defy logic guy
  10:26:09 - 01/03/2025
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
#define NAME "COWRADIO"

int dist(pair<int, int> a, pair<int, int> b)
{
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return dx * dx + dy * dy;
}

pair<int, int> next(pair<int, int> a, char c)
{
    if (c == 'U')
        return {a.first, a.second + 1};
    if (c == 'D')
        return {a.first, a.second - 1};
    if (c == 'R')
        return {a.first + 1, a.second};
    return {a.first - 1, a.second};
}

void solve()
{
    int n, m;
    cin >> n >> m;
    pair<int, int> jst, bst;
    cin >> jst.first >> jst.second >> bst.first >> bst.second;
    string jmove, bmove;
    cin >> jmove >> bmove;

    vector<pair<int, int>> jos(n + 1), bpos(m + 1);
    jos[0] = jst;
    for (int i = 1; i <= n; ++i)
        jos[i] = next(jos[i - 1], jmove[i - 1]);
    bpos[0] = bst;
    for (int j = 1; j <= m; ++j)
        bpos[j] = next(bpos[j - 1], bmove[j - 1]);

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e18));
    dp[0][0] = dist(jos[0], bpos[0]);

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i == 0 && j == 0)
                continue;

            int _min = 1e18;
            if (i > 0)
                _min = min(_min, dp[i - 1][j] + dist(jos[i], bpos[j]));
            if (j > 0)
                _min = min(_min, dp[i][j - 1] + dist(jos[i], bpos[j]));
            if (i > 0 && j > 0)
            {
                int one = dp[i - 1][j - 1] + dist(jos[i], bpos[j - 1]) + dist(jos[i], bpos[j]);
                int two = dp[i - 1][j - 1] + dist(jos[i - 1], bpos[j]) + dist(jos[i], bpos[j]);
                _min = min(_min, min(one, two));
            }
            dp[i][j] = _min;
        }
    }

    cout << dp[n][m] << endl;
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