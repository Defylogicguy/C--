/*************************
  Author: Defy logic guy
  14:41:23 - 08/03/2025
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
#define NAME "COVERED"

int dist(pair<int, int> a, pair<int, int> b) { return abs(a.first - b.first) * abs(a.first - b.first) + abs(a.second - b.second) * abs(a.second - b.second); }
void solve()
{
    vector<pair<int, int>> a, b;
    int c, d, e, f;
    cin >> c >> d >> e >> f;
    a.pb({c, d}), a.pb({e, f}), a.pb({c, f}), a.pb({e, d});
    cin >> c >> d >> e >> f;
    b.pb({c, d}), b.pb({e, f}), b.pb({c, f}), b.pb({e, d});

    int ans = LLONG_MAX;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            ans = min(ans, dist(a[i], b[j]));
    int one = (a[1].first < b[0].first ? b[0].first - a[1].first : (b[1].first < a[0].first ? b[1].first - a[0].first : 0));
    int two = (a[1].second < b[0].second ? b[0].second - a[1].second : (b[1].second < a[0].second ? b[1].second - a[0].second : 0));
    ans = min(ans, one * one + two * two);
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
