/*************************
  Author: Defy logic guy
  10:22:49 - 19/08/2025
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
#define NAME "cowsignal"

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<vector<char>> ans(k * n, vector<char>(k * m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int x = 0; x < k; x++)
                for (int y = 0; y < k; y++)
                    ans[i * k + x][j * k + y] = a[i][j];
    for (int i = 0; i < k * n; i++)
        for (int j = 0; j < k * m; j++)
        {
            cout << ans[i][j];
            if (j == k * m - 1)
                cout << '\n';
        }
}

signed main()
{
    if (fopen(NAME ".in", "r"))
    {
        freopen(NAME ".in", "r", stdin);
        freopen(NAME ".out", "w", stdout);
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
