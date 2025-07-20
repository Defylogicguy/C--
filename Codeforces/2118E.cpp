/*************************
  Author: Defy logic guy
  11:43:42 - 20/07/2025
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
#define NAME "2118E"

void solve()
{
    int n, m;
    cin >> n >> m;
    int cx = (n + 1) / 2;
    int cy = (m + 1) / 2;
    vector<vector<int>> a;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int di = abs(i - cx);
            int dj = abs(j - cy);
            int d1 = max(di, dj);
            int d2 = di + dj;
            a.push_back({d1, d2, i, j});
        }
    sort(a.begin(), a.end());
    for (auto &i : a)
        cout << i[2] << " " << i[3] << "\n";
    cout << '\n';
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
