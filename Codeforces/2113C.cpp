/*************************
  Author: Defy logic guy
  11:41:17 - 20/07/2025
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
#define NAME "2113C"

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> pf(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            ans += (a[i][j] == 'g');
            pf[i + 1][j + 1] = pf[i + 1][j] + pf[i][j + 1] - pf[i][j] + (a[i][j] == 'g');
        }
    int mn = LLONG_MAX;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == '.')
            {
                int one = max(0ll, i - k + 1);
                int two = max(0ll, j - k + 1);
                int tri = min(n - 1, i + k - 1);
                int fur = min(m - 1, j + k - 1);
                int ans = 0;
                if (one > tri or two > fur)
                    mn = min(mn, 0ll);
                else
                    mn = min(mn, pf[tri + 1][fur + 1] - pf[one][fur + 1] - pf[tri + 1][two] + pf[one][two]);
            }
    cout << ans - mn << endl;
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
