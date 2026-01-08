/*************************
  Author: Defy logic guy
  21:03:10 - 15/02/2025
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
#define NAME "D052"

const int maxn = 1e6 + 7;

void solve()
{
    int n;
    cin >> n;

    vector<bool> isPrime(maxn + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= maxn; i++)
        if (isPrime[i])
        {
            primes.pb(i);
            for (int j = i * i; j <= maxn; j += i)
                isPrime[j] = false;
        }

    vector<int> pf(maxn + 1, 0);
    int cnt = 0;
    for (int i = 2; i <= maxn; i++)
    {
        if (isPrime[i])
            cnt++;
        pf[i] = cnt;
    }

    int l = 1, r = maxn;
    int cr = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int cube = mid * mid * mid;
        if (cube <= n)
        {
            cr = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    auto it = upper_bound(all(primes), cr);
    vector<int> qPrimes(primes.begin(), it);

    int result = 0;
    for (int q : qPrimes)
    {
        int qCubed = q * q * q;
        if (qCubed > n)
            continue;
        int x = n / qCubed;
        int up = min(x, q - 1);
        if (up < 2)
            continue;
        if (up <= maxn)
            result += pf[up];
        else
            result += pf[maxn];
    }

    cout << result << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();
    return 0;
}
