/*************************
  Author: Defy logic guy
  11:51:23 - 18/07/2025
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
#define NAME "DPDIGIT_DELTA"

int dfs(const string &s, int i, int t, int even, int odd, vector<vector<vector<vector<int>>>> &dp)
{
    if (i == s.size())
        return odd == even + 1;

    if (dp[i][t][even][odd] != -1)
        return dp[i][t][even][odd];

    int l = (t ? s[i] - '0' : 9);
    int res = 0;

    for (int d = 0; d <= l; d++)
    {
        int new_tight = t && (d == l);
        if ((s.size() - i) % 2 == 0)
            res += dfs(s, i + 1, new_tight, even , odd + d, dp);
        else
            res += dfs(s, i + 1, new_tight, even+d, odd, dp);
    }

    return dp[i][t][even][odd] = res;
}

int cnt (int n)
{
    string s = to_string(n);
    int len = s.size();
    vector<vector<vector<vector<int>>>> dp(len, vector<vector<vector<int>>>(2, vector<vector<int>>(len * 9 + 1, vector<int>(len * 9 + 1, -1))));    
    return dfs(s, 0, 1, 0, 0, dp);
}

void solve()
{
    int a, b;
    cin >> a >> b;
    cout << cnt(b) - cnt(a - 1) << '\n';
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
