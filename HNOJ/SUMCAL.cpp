/*************************
  Author: Defy logic guy
  23:48:21 - 16/08/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "SUMCAL"

int mulmod(int b, int e, int m)
{
    b %= m;
    e %= m;
    int res = 0;
    while (e)
    {
        if (e & 1)
        {
            res += b;
            if (res >= m)
                res -= m;
        }
        b += b;
        if (b >= m)
            b -= m;
        e >>= 1;
    }
    return res;
}

void solve()
{
    int n, k, m;
    cin >> n >> k >> m;
    if (n < k or m == 1)
    {
        cout << 0;
        return;
    }

    int d = k + 1;
    vector<int> a(k + 1);
    for (int i = 0; i <= k; i++)
        a[i] = n + 1 - i;

    for (int i = 2; i * i <= d; i++)
        while (d % i == 0)
        {
            for (int j = 0; j <= k; j++)
                if (a[j] % i == 0)
                {
                    a[j] /= i;
                    break;
                }
            d /= i;
        }

    if (d > 1)
    {
        int p = d;
        for (int j = 0; j <= k; j++)
            if (a[j] % p == 0)
            {
                a[j] /= p;
                break;
            }
    }

    int ans = 1 % m;
    for (int i = 0; i <= k; i++)
        ans = mulmod(ans, a[i] % m, m);

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
