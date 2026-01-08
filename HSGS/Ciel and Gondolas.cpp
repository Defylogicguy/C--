/*************************
 Author: Defy logic guy
09:18:19 - 27/06/2025
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
#define NAME "Ciel and Gondolas"

const int maxn = 4005, maxk = 805, INF = 5e9;
int n, k, pf[maxn][maxn], dp[maxn], pd[maxn];

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char c;
            cin >> c;
            pf[i][j] = (c - '0') + pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1];
        }
    pd[n + 1] = n;
    for (int i = 2; i <= k; i++)
        for (int j = n; j > 0; j--)
        {
            dp[j] = -INF;
            for (int l = pd[j]; l <= pd[j + 1] and l < j; l++)
            {
                int c = dp[l] - pf[l][l] + pf[l][j];
                if (c > dp[j])
                {
                    dp[j] = c;
                    pd[j] = l;
                }
            }
        }
    cout << (pf[n][n] / 2 - dp[n]);
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
