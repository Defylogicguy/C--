/*************************
  Author: Defy logic guy
  11:06:24 - 29/08/2025
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
#define MOD 1000000007
#define NAME "POWERMATRIX"

int binmul(int a, int b, int m)
{
    // int res = 0;
    a %= m;
    b %= m;
    return (a * b) % m;
    // while (b)
    // {
    //     if (b & 1)
    //         (res += a) %= m;
    //     (a += a) %= m;
    //     b >>= 1;
    // }
    // return res;
}


int binpow(int b, int e, int m)
{
    int res = 1 % m;
    b %= m;
    while (e)
    {
        if (e & 1)
            res = binmul(res, b, m);
        b = binmul(b, b, m);
        e >>= 1;
    }
    return res;
}

pair<int, int> powseg(int a, int n, int mod)
{
    if (n == 0)
        return {1 % mod, 0};
    if (n == 1)
        return {a % mod, 1 % mod};
    if (n & 1)
    {
        auto prv = powseg(a, n - 1, mod);
        return {binmul(prv.first, a % mod, mod), (prv.second + prv.first) % mod};
    }
    else
    {
        auto prv = powseg(a, n / 2, mod);
        return {binmul(prv.first, prv.first, mod), binmul(prv.second, (prv.first + 1) % mod, mod)};
    }
}

void solve()
{
    int n, m, k, mod;
    if (!(cin >> n >> m >> k >> mod))
        return;
    k %= mod;
    int q;
    cin >> q;
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << binmul(binmul(binpow(k, y1, mod), powseg(k, y2 - y1 + 1, mod).second, mod), binmul(binpow(binpow(k, m, mod), x1 - 1, mod), powseg(binpow(k, m, mod), x2 - x1 + 1, mod).second, mod), mod) << '\n';
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
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
