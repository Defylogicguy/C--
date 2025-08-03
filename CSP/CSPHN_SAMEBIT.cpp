/*************************
  Author: Defy logic guy
  16:14:39 - 02/08/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 123456789
#define NAME "CSPHN_SAMEBIT"

int exp(int a, int b, int m)
{
    int res = 1 % m;
    a %= m;
    while (b)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>=1;
    }
    return res;
}

const int mod = 3 * MOD;
void solve()
{
    int n;
    cin >> n;
    int ans, k;
    if (n % 2 == 0)
    {
        k = n / 2;
        int p = exp(4, k, mod);
        ans = (p - 1) / 3;
    }
    else
    {
        k = (n - 1) / 2;
        int p = exp(4, k, mod);
        ans = (2 * ((p - 1) / 3)) % MOD;
    }
    cout << ans % MOD << "\n";
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
