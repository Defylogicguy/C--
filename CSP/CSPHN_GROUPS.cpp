/*************************
  Author: Defy logic guy
  15:31:53 - 01/03/2025
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
#define NAME "CSPHN_GROUPS"

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i].first >> a[i].second;
        a[i] = {min(a[i].first, a[i].second), max(a[i].first, a[i].second)};
    }

    if (k == 0)
    {
        cout << 0 << endl;
        return;
    }

    sort(all(a), [](pair<int, int> a, pair<int, int> b)
         { return a.second == b.second ? a.first < b.first : a.second < b.second; });

    int cur = 0, ans = 1;
    for (int i = 0; i < k; i++)
    {
        if (cur < a[i].first)
        {
            cur = a[i].second;
            ans++;
        }
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