/*************************
  Author: Defy logic guy
  21:23:31 - 30/05/2025
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
#define NAME "ABC149C"

void solve()
{
    int x;
    cin >> x;
    auto isPrime = [](int n) {
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0)
                return false;
        return n > 1;
    };

    for (int i = x;; i++)
    {
        if (isPrime(i))
        {
            cout << i << endl;
            return;
        }
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
