/*************************
  Author: Defy logic guy
  08:47:08 - 14/06/2025
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
#define NAME "THT2023_HN_SK_C_PNUMBER"

const int maxn = 180;
bool p[maxn];
void sieve()
{
    fill(p, p + maxn, true);
    p[0] = p[1] = false;
    for (int i = 2; i * i < maxn; i++)
        if (p[i])
            for (int j = i * i; j < maxn; j += i)
                p[j] = false;
}

int f(int mid)
{
    string s = to_string(mid);
    int n = s.size();
    static int dp[21][maxn][2][2];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < maxn; j++)
            for (int u = 0; u < 2; u++)
                for (int v = 0; v < 2; v++)
                    dp[i][j][u][v] = 0;
    dp[0][0][1][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < maxn; j++)
            for (int u = 0; u < 2; u++)
                for (int v = 0; v < 2; v++)
                {
                    int val = dp[i][j][u][v];
                    if (!val)
                        continue;
                    int lim = (u ? s[i] - '0' : 9);
                    for (int d = 0; d <= lim; d++)
                    {
                        int nj = j + d;
                        if (nj >= maxn)
                            continue;
                        int nu = (u && (d == lim));
                        int nv = (v || (d != 0));
                        dp[i + 1][nj][nu][nv] += val;
                    }
                }
    int ans = 0;
    for (int i = 0; i < maxn; i++)
        if (p[i])
            ans += dp[n][i][0][1] + dp[n][i][1][1];
    return ans;
}

void solve()
{
    int k;
    cin >> k;
    int l = 1;
    int r = 1e18;
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (f(mid) >= k)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
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

    sieve();

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solve();
    }
    return 0;
}
