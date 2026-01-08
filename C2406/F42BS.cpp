/*************************
  Author: Defy logic guy
  20:02:43 - 25/02/2025
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
#define NAME "F42BS"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = a[n - 1];
    int cur = a[n - 1], prev = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (cur > 0)
        {
            int x = min(a[i], prev - 1);
            if (x >= 1)
            {
                cur += x;
                prev = x;
            }
            else
                cur = 0;
        }
        else
            cur = 0;

        ans = max(ans, cur);
    }

    cout << ans;
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
