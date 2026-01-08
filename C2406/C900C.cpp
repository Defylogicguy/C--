/*************************
  Author: Defy logic guy
  20:41:41 - 25/02/2025
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
#define NAME "C900C"

void solve()
{
    int n;
    cin >> n;

    int m = 0, t = 0;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        if (k > m)
        {
            a[k] = 1;
            t = m;
            m = k;
        }
        else if (k > t)
        {
            a[m]--;
            t = k;
        }
    }

    int ans = 1;
    for (int i = 1; i <= n; i++)
        if (a[i] < a[ans])
            ans = i;
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
