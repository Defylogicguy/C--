/*************************
  Author: Defy logic guy
  13:36:57 - 03/06/2025
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
#define NAME "CAMPFIRE"

int f(int m, int d, string s)
{
    int dp[s.size() + 1][m + 1][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0][1] = 1;
    for (int i = 0; i < s.size(); i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < 2; k++)
                for (int x = 0; x <= (k ? (s[i] - '0') : 9); x++)
                {
                    if ((i & 1) and x != d)
                        continue;
                    if (!(i & 1) and x == d)
                        continue;
                    if (i == 0 and x == 0)
                        continue;
                    dp[i + 1][((j * 10 + x) % m)][(k & (x == (s[i] - '0')))] += dp[i][j][k];
                    dp[i + 1][((j * 10 + x) % m)][(k & (x == (s[i] - '0')))] %= MOD;
                }
    return (dp[s.size()][0][0] + dp[s.size()][0][1]) % MOD;
}

bool check(string s, int d, int m)
{
    int idk = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if ((i & 1) and (s[i] - '0') != d)
            return false;
        if (!(i & 1) and (s[i] - '0') == d)
            return false;
        idk = (idk * 10 + (s[i] - '0')) % m;
    }
    return idk == 0;
}

void solve()
{
    int m, d;
    string a, b;
    cin >> m >> d >> a >> b;
    cout << (f(m, d, b) - f(m, d, a) + check(a, d, m) + MOD) % MOD << endl;
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
