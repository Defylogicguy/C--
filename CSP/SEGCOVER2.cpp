/*************************
  Author: Defy logic guy
  20:17:44 - 12/01/2025
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
#define NAME "SEGCOVER2"

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    sort(all(a), [](pair<int, int> a, pair<int, int> b)
         { return a.second == b.second ? a.first < b.first : a.second < b.second; });
    int cur = -(1e9 + 7), cnt = 0;
    for (int i = 0; i < n; i++)
        if (cur <= a[i].first)
        {
            cnt++;
            cur = a[i].second;
        }
    cout << n - cnt << endl;
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
