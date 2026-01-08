/*************************
  Author: Defy logic guy
  21:45:06 - 14/01/2025
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
#define NAME "C1443D"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 1e7 + 5, r = 0;
    for (int i = 0; i < n; i++)
    {
        a[i] -= r;
        if (a[i] < 0)
        {
            cout << "No\n";
            return;
        }
        l = min(l, a[i]);
        a[i] -= l;
        if (a[i] > 0)
            r += a[i];
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
