/*
 Author: Defy logic guy
 23:47:21 - 28/12/2024
*/
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
#define NAME "Skibidi"

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        if (a[i].first == a[i].second)
            mp[a[i].first]++;
    }

    vector<int> keys;
    for (const auto &it : mp)
        keys.pb(it.first);
    sort(all(keys));

    string res;
    res.reserve(n);
    for (const auto &[one, two] : a)
    {
        if (one < two)
        {
            int lower = lower_bound(all(keys), one) - keys.begin();
            int upper = upper_bound(all(keys), two) - keys.begin();
            int cnt = upper - lower;

            res += (cnt < (two - one + 1)) ? '1' : '0';
        }
        else
            res += (mp[one] <= 1) ? '1' : '0';
    }

    cout << res << endl;
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

    int tt = 1;
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
