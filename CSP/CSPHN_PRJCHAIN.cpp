/*************************
 Author: Defy logic guy
14:55:33 - 28/06/2025
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
#define NAME "CSPHN_PRJCHAIN"

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first;
    for (int i = 0; i < n; i++)
        cin >> a[i].second;
    sort(all(a), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if (a.first - a.second < 0 and b.first - b.second >=0)
            return true;
        else if (a.first - a.second >=0 and b.first - b.second < 0)
            return false;
        else if (a.first - a.second >= 0 and b.first - b.second >= 0)
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        else
            return a.first == b.first ? a.second > b.second : a.first < b.first; });
    int l = 1, r = 1e18, ans = 0;
    auto f = [&](int mid)
    {
        for (int i = 0; i < n; i++)
        {
            if (mid < a[i].first)
                return false;
            mid += a[i].second;
            mid -= a[i].first;
        }
        return true;
    };
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (f(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
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
