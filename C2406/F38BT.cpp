/*************************
  Author: Defy logic guy
  23:32:34 - 11/04/2025
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
#define NAME "F38BT"

void solve()
{
    int n, u, v;
    cin >> n >> u >> v;

    int maxx = 0, l = u, r = u;
    int cur = u;
    while (cur <= v)
    {
        int q = n / cur;
        int idk = n / q;
        if (idk > v)
            idk = v;

        int len = idk - cur + 1;
        if (len > maxx or (len == maxx and cur < l))
        {
            maxx = len;
            l = cur;
            r = idk;
        }

        cur = idk + 1;
    }
    cout << l << ' ' << r;
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
