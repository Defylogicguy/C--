/*************************
  Author: Defy logic guy
  14:57:03 - 09/08/2025
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
#define NAME "CSPHN_LZPATH"

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<vector<int>> cnt2(n, vector<int>(n, 0)), cnt5(n, vector<int>(n, 0)), dp2(n, vector<int>(n, LLONG_MAX)), dp5(n, vector<int>(n, LLONG_MAX));
    int zeri = -1, zerj = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 0)
                zeri = i, zerj = j;
            else
            {
                int cnt = 0;
                while (a[i][j] % 2 == 0)
                    a[i][j] /= 2, cnt++;
                cnt2[i][j] = cnt;
                cnt = 0;
                while (a[i][j] % 5 == 0)
                    a[i][j] /= 5, cnt++;
                cnt5[i][j] = cnt;
            }
    dp2[0][0] = (a[0][0] == 0 ? 1 : cnt2[0][0]);
    dp5[0][0] = (a[0][0] == 0 ? 1 : cnt5[0][0]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i > 0)
            {
                dp2[i][j] = min(dp2[i][j], dp2[i - 1][j] + (a[i][j] == 0 ? 1 : cnt2[i][j]));
                dp5[i][j] = min(dp5[i][j], dp5[i - 1][j] + (a[i][j] == 0 ? 1 : cnt5[i][j]));
            }
            if (j > 0)
            {
                dp2[i][j] = min(dp2[i][j], dp2[i][j - 1] + (a[i][j] == 0 ? 1 : cnt2[i][j]));
                dp5[i][j] = min(dp5[i][j], dp5[i][j - 1] + (a[i][j] == 0 ? 1 : cnt5[i][j]));
            }
        }
    int ans = min(dp2[n - 1][n - 1], dp5[n - 1][n - 1]);
    if (ans > 1 && zeri != -1)
        ans = 1;
    cout << ans << "\n";
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
