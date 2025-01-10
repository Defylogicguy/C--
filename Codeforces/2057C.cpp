/*************************
  Author: Defy logic guy
  21:32:23 - 04/01/2025
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
#define NAME "2057C"

void solve()
{
    int l, r;
    cin >> l >> r;
    int ans = 0;
    int iter = 30, idk = 0;
    while (iter >= 0)
    {
        idk = (1 << iter);
        if ((l & idk) == (r & idk))
        {
            if (l & idk)
                ans += idk;
        }
        else
            break;
        iter--;
    }
    if (r > ans + idk)
        cout << ans + idk - 1 << ' ' << ans + idk << ' ' << ans + idk + 1 << endl;
    else
        cout << ans + idk - 2 << ' ' << ans + idk - 1 << ' ' << ans + idk << endl;
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
