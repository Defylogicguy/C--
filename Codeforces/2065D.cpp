/*************************
  Author: Defy logic guy
  21:34:07 - 09/02/2025
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
#define NAME "2065D"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    sort(all(a), [](const vector<int> &a, const vector<int> &b)
         { return accumulate(all(a), 0ll) > accumulate(all(b), 0ll); });
    int ans = 0, prev = 0;
    bool st = true;
    for (const auto &row : a)
        for (int val : row)
        {
            if (st)
            {
                st = false;
                ans += val;
                prev = val;
            }
            else
            {
                ans += prev + val;
                prev += val;
            }
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
