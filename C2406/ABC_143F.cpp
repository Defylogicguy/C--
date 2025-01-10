/*************************
  Author: Defy logic guy
  19:18:13 - 05/01/2025
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
#define NAME "ABC_143F"

void solve()
{
    int n;
    cin >> n;

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    vector<int> a;
    for (auto it : mp)
        a.pb(it.second);

    sort(rall(a));
    vector<int> pf(a.size() + 1, 0);
    partial_sum(all(a), pf.begin() + 1);

    cout << n << endl;
    for (int k = 2; k <= n; k++)
    {
        int l = 0, r = a.size(), ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (mid * k <= pf[mid])
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        cout << ans << endl;
    }
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
