/*************************
  Author: Defy logic guy
  10:26:20 - 18/07/2025
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
#define NAME "DPDIGIT_DIVK"

int k;
int cnt(const string &s)
{
    int n = s.size();

    vector<vector<int>> dp[2];
    for (int i = 0; i < 2; i++)
        dp[i] = vector<vector<int>>(k, vector<int>(k, 0));

    vector<vector<int>> t(k, vector<int>(k, 0));
    t[0][0] = 1;

    for (int i = 0; i < n; i++)
    {
        int cur = i % 2;
        int nxt = cur ^ 1;

        for (int j = 0; j < k; j++)
            fill(all(dp[nxt][j]), 0);

        vector<vector<int>> nw(k, vector<int>(k, 0));

        for (int j = 0; j < k; j++)
            for (int u = 0; u < k; u++)
                for (int d = 0; d <= 9; d++)
                    dp[nxt][(j * 10 + d) % k][(u + d) % k] += dp[cur][j][u];

        int l = s[i] - '0';
        for (int j = 0; j < k; j++)
            for (int u = 0; u < k; u++)
                for (int d = 0; d <= l; d++)
                    if (d < l)
                        dp[(i + 1) % 2][(j * 10 + d) % k][(u + d) % k] += t[j][u];
                    else
                        nw[(j * 10 + d) % k][(u + d) % k] += t[j][u];

        t = nw;
    }

    return dp[n % 2][0][0] + t[0][0] - 1; 
}

void solve()
{
    int a, b;
    cin >> a >> b >> k;
    string sa = to_string(a - 1), sb = to_string(b);
    cout << cnt(sb) - cnt(sa) << '\n';
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
