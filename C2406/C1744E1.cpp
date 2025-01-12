/*************************
  Author: Defy logic guy
  20:43:35 - 11/01/2025
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
#define NAME "C1744E1"

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int div = a * b;
    for (int i = a + 1; i <= c; i++)
    {
        int idk = div / __gcd(div, i);
        int need = d/idk*idk;
        if (need > b)
        {
            cout << i << ' ' << need << endl;
            return;
        }
    }
    cout << "-1 -1\n";
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

