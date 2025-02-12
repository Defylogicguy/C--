/*************************
  Author: Defy logic guy
  08:01:30 - 11/02/2025
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
#define NAME "QUAYSOTK24"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    int _max = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
        if (mp[x] > _max)
        {
            ans = x;
            _max = mp[x];
        }
        else if (mp[x] == _max)
            ans = min(ans, x);
    }
    cout << ans << '\n';
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
