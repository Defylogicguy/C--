/*************************
  Author: Defy logic guy
  22:59:18 - 28/08/2025
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
#define NAME "2136D"

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    int mn = LLONG_MAX, mx = LLONG_MIN;
    for (auto [x, y] : a)
        mx = max(mx, x + y), mn = min(mn,y - x);
    auto f = [&](char c, int s)
    {
        cout << "? " << c << ' ' << s << endl;
        int res;
        cin >> res;
        return res;
    };
    int st = 1e9;
    f('U', st);
    f('U', st);
    f('R', st);
    int one = f('R', st);
    f('D', st);
    f('D', st);
    f('D', st);
    int two = f('D', st);
    int t = one + mx - 4 * st;
    int h = two - mn - 4 * st;
    cout << "! " << ((t + h) >> 1) << ' ' << ((t - h) >> 1) << endl;
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
