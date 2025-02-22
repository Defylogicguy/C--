/*************************
  Author: Defy logic guy
  15:35:18 - 22/02/2025
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
#define NAME "MOVE"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n);
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '1')
                v[i].pb(j);
        }

    int ans = LLONG_MAX;
    for (int i = 0; i < m; i++)
    {
        int res = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j].empty())
            {
                cout << -1 << endl;
                return;
            }

            auto it = lower_bound(all(v[j]), i);
            int tmp = LLONG_MAX;
            if (it != v[j].end())
                tmp = min(tmp, abs(*it - i));
            if (it != v[j].begin())
            {
                it--;
                tmp = min(tmp, abs(i - *it));
            }

            tmp = min(tmp, abs(v[j][v[j].size() - 1] - m - i));
            tmp = min(tmp, abs(v[j][0] + m - i));
            res += tmp;
        }
        ans = min(ans, res);
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

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();
    return 0;
}
