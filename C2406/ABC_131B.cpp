/*************************
  Author: Defy logic guy
  22:37:49 - 10/01/2025
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
#define NAME "ABC_131B"

void solve()
{
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    iota(all(a), 1);
    for (int i = 0; i < n; i++)
        a[i] = l + a[i] - 1;
    sort(all(a), [](int a, int b)
         { return abs(a) < abs(b); });
    int ans = 0;
    for (int i = 1; i < n; i++)
        ans += a[i];
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
