/*************************
  Author: Defy logic guy
  21:11:53 - 04/05/2025
*************************/
#include <bits/stdc++.h>
#include <mpfr.h>
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
#define NAME "F45F"

void solve()
{
    int n;
    cin >> n;
    int l = 0, r = 5 * n;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int tmp = mid, cnt = 0;
        while (tmp >= 5)
        {
            cnt += tmp / 5;
            tmp /= 5;
        }
        if (cnt >= n)
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
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
