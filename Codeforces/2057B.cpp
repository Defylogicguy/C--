/*************************
  Author: Defy logic guy
  21:32:14 - 04/01/2025
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
#define NAME "2057B"

void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    int _max = INT_MAX, cur = 0;
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    int ans = mp.size();
    vector<pair<int, int>> v(all(mp));
    sort(all(v), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });
    for (auto it : v)
    {
        int x = it.second;
        if (k >= x)
        {
            ans--;
            k -= x;
        }
    }
    cout << max(ans, 1ll) << endl;
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
