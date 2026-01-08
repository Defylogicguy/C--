/*************************
  Author: Defy logic guy
  22:24:49 - 16/05/2025
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
#define NAME "BEUNUM"

void solve()
{
    int k;
    cin >> k;

    auto cnt1 = [](int x, int n)
    {
        return n / x;
    };

    auto cnt2 = [](int x, int y, int n)
    {
        return n / (x * y);
    };

    auto cnt3 = [](int x, int y, int z, int n)
    {
        return n / (x * y * z);
    };

    auto cnt = [&](int n)
    {
        return cnt1(3, n) + cnt1(5, n) + cnt1(7, n) - cnt2(3, 5, n) - cnt2(3, 7, n) - cnt2(5, 7, n) + cnt3(3, 5, 7, n);
    };

    int l = 1, r = 1e18, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (cnt(mid) >= k)
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
    // cin >> tt;

    while (tt--)
        solve();
    return 0;
}
