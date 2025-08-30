/*************************
  Author: Defy logic guy
  23:00:16 - 03/09/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "ITABLE"

void solve()
{
    int n, t;
    cin >> n >> t;
    vector<vector<int>> r(n + 1, vector<int>(n + 2, 0)), c(n + 1, vector<int>(n + 2, 0));
    while (t--)
    {
        int k, rc, x, y;
        cin >> k >> rc >> x >> y;
        tie(x, y) = make_pair(min(x, y), max(x, y));
        int mid = x + y >> 1;
        if (k == 1)
        {
            for (int i = x; i <= mid; i++)
                r[rc][i] += i - x + 1;
            for (int i = mid + 1; i <= y; i++)
                r[rc][i] += y - i + 1;
        }
        else
        {
            for (int i = x; i <= mid; i++)
                c[rc][i] += i - x + 1;
            for (int i = mid + 1; i <= y; i++)
                c[rc][i] += y - i + 1;
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << r[x][y] + c[y][x] << '\n';
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
