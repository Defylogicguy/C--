/*************************
  Author: Defy logic guy
  23:00:39 - 19/05/2025
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
#define endl '\n'
#define NAME "CHIAKEOEASY"

const int maxn = 2e6 + 5;
vector<int> f(maxn), invf(maxn);

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void pre()
{
    f[0] = invf[0] = 1;
    for (int i = 1; i < maxn; ++i)
    {
        f[i] = f[i - 1] * i % MOD;
        invf[i] = power(f[i], MOD - 2);
    }
}

int Cnk(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return f[n] * invf[k] % MOD * invf[n - k] % MOD;
}

void solve()
{
    pre();
    int n, k;
    cin >> n >> k;
    cout << Cnk(n + k - 1, k - 1) << endl;
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
