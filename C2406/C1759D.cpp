/*************************
  Author: Defy logic guy
  20:20:34 - 08/02/2025
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
#define NAME "C1759D"

void solve()
{
    int n, m;
    cin >> n >> m;
    int tmp = n;
    int two = 0, fiv = 0;

    int k = 1;
    while (n % 2 == 0 and n > 0)
    {
        n /= 2;
        two++;
    }
    while (n % 5 == 0 and n > 0)
    {
        n /= 5;
        fiv++;
    }

    while (two < fiv and k * 2 <= m)
    {
        k *= 2;
        two++;
    }
    while (fiv < two and k * 5 <= m)
    {
        k *= 5;
        fiv++;
    }

    while (k * 10 <= m)
        k *= 10;
    if (k == 1)
        cout << tmp * m << '\n';
    else
    {
        k *= m / k;
        cout << tmp * k << '\n';
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
