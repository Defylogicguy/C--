/*************************
  Author: Defy logic guy
  22:43:55 - 17/08/2025
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
#define NAME "275A"

void solve()
{
    int n = 3;
    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int ans[n][n] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i > 0)
                ans[i - 1][j] += a[i][j];
            if (j > 0)
                ans[i][j - 1] += a[i][j];
            if (i < n - 1)
                ans[i + 1][j] += a[i][j];
            if (j < n - 1)
                ans[i][j + 1] += a[i][j];
            ans[i][j] += a[i][j];
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cout << !(ans[i][j] & 1);
            if (j == n - 1)
                cout << '\n';
        }
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
