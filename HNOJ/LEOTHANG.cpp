/*************************
  Author: Defy logic guy
  10:17:30 - 26/04/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "LEOTHANG"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.pb(make_pair(a[i], i + 1));
    sort(all(v), [](pair<int, int> &a, pair<int, int> &b)
         { return a.first < b.first; });

    vector<int> suf(n);
    suf[n - 1] = v[n - 1].second;
    for (int i = n - 2; i >= 0; i--)
        suf[i] = min(suf[i + 1], v[i].second);

    while (m--)
    {
        int t;
        cin >> t;
        int pos = upper_bound(all(v), make_pair(t, 0ll), [](auto &a, auto &b)
                              { return a.first < b.first; }) -
                  v.begin();
        if (pos == n)
            cout << n << '\n';
        else
            cout << suf[pos] - 1 << '\n';
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
