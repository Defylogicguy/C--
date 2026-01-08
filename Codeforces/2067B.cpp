/*************************
  Author: Defy logic guy
  13:07:28 - 13/02/2025
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
#define NAME "2067B"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]]++;

    for (auto it : mp)
        if (it.second == 1)
        {
            cout << "No\n";
            return;
        }

    vector<int> cnt;
    for (auto it : mp)
        if (it.second % 2 == 1)
            cnt.pb(it.first);

    if (cnt.size() % 2)
    {
        cout << "No\n";
        return;
    }
    for (int i = 1; i < cnt.size(); i++)
        if (cnt[i - 1] + 1 == cnt[i])
            i += 2;
        else
        {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
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
