/*************************
  Author: Defy logic guy
  10:30:10 - 17/05/2025
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
#define endl '\n'
#define NAME "LONELYNUMBER"

void solve()
{
    int v, k;
    cin >> v >> k;

    auto lonely = [](int v)
    {
        return v - v / 2 - v / 3 - v / 5 - v / 7 + v / 6 + v / 10 + v / 14 + v / 15 + v / 21 + v / 35 - v / 30 - v / 42 - v / 70 - v / 105 + v / 210;
    };
    cout << lonely(v) << ' ';

    int l = 1, r = 9e18, ans = -1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (lonely(m) < k)
            l = m + 1;
        else
            ans = m, r = m - 1;
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
