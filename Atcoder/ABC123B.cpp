/*************************
  Author: Defy logic guy
  16:06:49 - 22/06/2025
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
#define NAME "ABC123B"

void solve()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    map<int, vector<int>> mp;
    for (int i : {a, b, c, d, e})
        if (i % 10 == 0)
            mp[0].pb(i);
        else
            mp[1].pb(i);
    int ans = 0;
    for (int i : mp[0])
        ans += i;
    sort(all(mp[1]), [](int x, int y)
         { return x % 10 > y % 10; });
    for (int i = 0; i < mp[1].size(); i++)
        ans += mp[1][i] + (i == mp[1].size() - 1 ? 0 : 10 - mp[1][i] % 10);
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
