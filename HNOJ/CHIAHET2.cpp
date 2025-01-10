/*************************
  Author: Defy logic guy
  10:09:26 - 04/01/2025
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
#define NAME "CHIAHET2"

void solve()
{
    int n, x;
    cin >> n >> x;

    int l = pow(10, n - 1);
    int r = pow(10, n) - 1;
    int two = (1LL << x);
    int _min = (l + two - 1) / two * two;
    int _max = (r / two) * two;
    if (_min > r or _max < l)
        cout << 0 << endl;
    else
        cout << (_max - _min) / two + 1 << endl;
}ư

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
