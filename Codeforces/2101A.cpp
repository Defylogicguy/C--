/*************************
  Author: Defy logic guy
  11:56:11 - 20/07/2025
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
#define NAME "2101A"

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int tp = 0, bt = n - 1, l = 0, r = n - 1;
    int v = 0, mx = n * n - 1;
    while (tp <= bt && l <= r)
    {
        for (int j = l; j <= r; j++)
            a[tp][j] = v++;
        tp++;
        for (int i = tp; i <= bt; i++)
            a[i][r] = v++;
        r--;
        if (tp <= bt)
        {
            for (int j = r; j >= l; j--)
                a[bt][j] = v++;
            bt--;
        }
        if (l <= r)
        {
            for (int i = bt; i >= tp; i--)
                a[i][l] = v++;
            l++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mx - a[i][j] << ' ';
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
