/*************************
  Author: Defy logic guy
  22:19:18 - 08/02/2025
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
#define NAME "C1285C"

int lcm(int a, int b) { return (a / __gcd(a, b)) * b; }
void solve()
{
    int n;
    cin >> n;
    int ans = 1;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0 and lcm(i, n / i) == n)
            ans = i;
    cout << ans << ' ' << n / ans << endl;
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
