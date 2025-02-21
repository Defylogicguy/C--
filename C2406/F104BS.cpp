/*************************
  Author: Defy logic guy
  21:28:55 - 18/02/2025
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
#define NAME "F104BS"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int _min = min(n, m);
    for (int i = _min; i >= 1; i--)
        for (int j = 0; j <= n - i; j++)
            for (int k = 0; k <= m - i; k++)
            {
                bool flag = true;
                for (int u = k; u < k + i; u++)
                    if (a[j][u] != 1 || a[j + i - 1][u] != 1)
                    {
                        flag = false;
                        break;
                    }
                if (!flag)
                    continue;
                for (int u = j; u < j + i; u++)
                    if (a[u][k] != 1 || a[u][k + i - 1] != 1)
                    {
                        flag = false;
                        break;
                    }
                if (flag)
                {
                    cout << i * i;
                    return;
                }
            }
    cout << 0;
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
