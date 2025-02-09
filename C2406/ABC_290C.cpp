/*************************
  Author: Defy logic guy
  20:13:30 - 08/02/2025
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
#define NAME "ABC_290C"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]]++;
    vector<int> v;
    int keep = 0;
    for (auto it : mp)
    {
        v.pb(it.first);
        keep++;
        if (keep == k)
            break;
    }

    int cur = 0;
    for (int i = 0; i < k; i++)
        if (v[i] != cur)
        {
            cout << cur;
            return;
        }
        else
            cur++;

    cout << cur;
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
