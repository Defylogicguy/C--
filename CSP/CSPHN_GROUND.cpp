/*************************
  Author: Defy logic guy
  16:22:52 - 19/04/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "CSPHN_GROUND"
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    vector<vector<int>> one(n, vector<int>(m - k + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - k + 1; j++)
        {
            int res = *max_element(a[i].begin() + j, a[i].begin() + j + k);
            one[i][j] = res;
        }

    vector<vector<int>> two(n - k + 1, vector<int>(m - k + 1));
    for (int j = 0; j < m - k + 1; j++)
        for (int i = 0; i < n - k + 1; i++)
        {
            int res = -1;
            for (int z = i; z < i + k; z++)
                res = max(res, one[z][j]);
            two[i][j] = res;
        }

    vector<vector<int>> tri(n, vector<int>(m - k + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m - k + 1; j++)
        {
            int res = *min_element(a[i].begin() + j, a[i].begin() + j + k);
            tri[i][j] = res;
        }

    vector<vector<int>> fur(n - k + 1, vector<int>(m - k + 1));
    for (int j = 0; j < m - k + 1; j++)
        for (int i = 0; i < n - k + 1; i++)
        {
            int res = LLONG_MAX;
            for (int z = i; z < i + k; z++)
                res = min(res, tri[z][j]);
            fur[i][j] = res;
        }

    int ans = LLONG_MAX;
    for (int i = 0; i < n - k + 1; i++)
        for (int j = 0; j < m - k + 1; j++)
            ans = min(ans, two[i][j] - fur[i][j]);

    cout << ans;
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
