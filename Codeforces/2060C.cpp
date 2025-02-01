/*************************
  Author: Defy logic guy
  21:10:57 - 19/01/2025
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
#define NAME "2060C"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int > a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]]++;
    vector<int> dont;
    for (int i = 1; i <= k; i++)
        if (mp[i] == 0)
            dont.pb(i);
    for (int i : dont)
        mp[k - i] /= 2;
    int ans = 0;
    for (int i = 1; i <= k; i++)
        ans += min(mp[i], mp[k - i]);
    cout << ans / 2 << endl;
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
