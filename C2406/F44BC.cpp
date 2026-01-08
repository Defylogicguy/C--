/*************************
  Author: Defy logic guy
  20:05:05 - 22/02/2025
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
#define NAME "F44BC"

void solve()
{
    int m, k, a, b;
    cin >> m >> k >> a >> b;

    int dif = abs(a - b);
    int idk = min(m, dif / k);
    m -= idk;
    if (a < b)
        a += idk * k;
    else
        b += idk * k;

    dif = abs(a - b);
    if (m > 0)
    {
        int remain = m % 2;
        if (remain == 1)
        {
            if (a < b)
                a += k;
            else
                b += k;
        }
    }
    cout << abs(a - b) << endl;
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
