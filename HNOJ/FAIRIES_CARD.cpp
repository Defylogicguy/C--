/*************************
  Author: Defy logic guy
  22:35:44 - 16/06/2025
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
#define NAME "FAIRIES_CARD"

int nen(char c)
{
    if (c == 'C' || c == 'c')
        return 0;
    if (c == 'H' || c == 'h')
        return 1;
    if (c == 'I' || c == 'i')
        return 2;
    if (c == 'M' || c == 'm')
        return 3;
    return -1;
}

int dp[400][400][16][16];
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    for (int _ = 1; _ <= n; _++)
        for (int i = 0; i + _ - 1 < n; i++)
        {
            int j = i + _ - 1;
            for (int m1 = 0; m1 < 16; m1++)
                for (int m2 = 0; m2 < 16; m2++)
                {
                    int mx = LLONG_MIN;
                    char c = s[i];
                    if (c == '#')
                        mx = max(mx, (i + 1 <= j ? -dp[i + 1][j][m2][m1] : 0));
                    else if (c >= '1' && c <= '9')
                        mx = max(mx, c - '0' - ((i + 1 <= j) ? dp[i + 1][j][m2][m1] : 0));
                    else if (c >= 'A' && c <= 'Z')
                        mx = max(mx, (i + 1 <= j ? -dp[i + 1][j][m2][m1 | (1 << nen(c))] : 0));
                    else if (m1 & (1 << nen(c)))
                        mx = max(mx, (i + 1 <= j) ? -dp[i + 1][j][m2][m1] : 0);
                    if (i < j)
                    {
                        c = s[j];
                        if (c == '#')
                            mx = max(mx, (i <= j - 1 ? -dp[i][j - 1][m2][m1] : 0));
                        else if (c >= '1' && c <= '9')
                            mx = max(mx, c - '0' - (i <= j - 1 ? dp[i][j - 1][m2][m1] : 0));
                        else if (c >= 'A' && c <= 'Z')
                            mx = max(mx, -(i <= j - 1 ? dp[i][j - 1][m2][m1 | (1 << nen(c))] : 0));
                        else if (m1 & (1 << nen(c)))
                            mx = max(mx, (i <= j - 1 ? -dp[i][j - 1][m2][m1] : 0));
                    }
                    dp[i][j][m1][m2] = (mx == LLONG_MIN ? 0 : mx);
                }
        }
    int ans = n ? dp[0][n - 1][0][0] : 0;
    cout << (ans < 0 ? "SunnyMilk\n" : ans > 0 ? "LunaChild\n"
                                               : "StarSapphire\n")
         << ans;
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
