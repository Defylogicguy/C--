/*************************
  Author: Defy logic guy
  20:37:20 - 22/02/2025
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
#define NAME "CS1619"

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.pb({x, 1});
        a.pb({y, -1});
    }

    sort(all(a));
    int cur = 0, _max = 0;
    for (auto &[x, y] : a)
    {
        cur += y;
        _max = max(_max, cur);
    }

    cout << _max << endl;
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
