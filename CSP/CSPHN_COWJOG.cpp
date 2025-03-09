/*************************
  Author: Defy logic guy
  14:21:48 - 08/03/2025
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
#define NAME "CSPHN_COWJOG"

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int x;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> a[i];

    int lst = a[n - 1], ans = 1;
    for (int i = n - 2; i >= 0; i--)
        if (a[i] <= lst)
        {
            lst = a[i];
            ans++;
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
