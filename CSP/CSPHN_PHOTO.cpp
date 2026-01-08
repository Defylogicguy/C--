/*************************
  Author: Defy logic guy
  14:55:31 - 28/06/2025
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
#define NAME "CSPHN_PHOTO"

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(5, vector<int>(n));
    vector<vector<int>> pos(5, vector<int>(n));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            pos[i][a[i][j] - 1] = j;
        }
    vector<int> res(n);
    iota(all(res), 0);
    sort(all(res), [&](const int &x, const int &y)
         { int cnt = 0; 
        for (int i = 0 ; i < 5; i++)
            if (pos[i][x] < pos[i][y])
                cnt++; 
        return cnt >= 3; });
    for (int i = 0; i < n; i++)
        cout << res[i] + 1 << ' ';
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
