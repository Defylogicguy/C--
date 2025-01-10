/*************************
  Author: Defy logic guy
  21:28:21 - 07/01/2025
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
#define NAME "C1379B"

void solve()
{
    int l, r, m;
    cin >> l >> r >> m;
    for (int i = l; i <= r; i++)
    {
        int md = m % i;
        if (m >= i and md <= r - l)
        {
            cout << i << ' ' << l + md << ' '<< l << endl;
            return;
        }

        if (i - md <= r - l)
        {
            cout << i <<  ' ' << l << ' ' << l + i - md << endl;
            return;
        }
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
    cin >> tt;

    while (tt--)
        solve();
    return 0;
}
