/*************************
  Author: Defy logic guy
  23:49:10 - 14/08/2025
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
#define NAME "1869A"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n & 1)
    {
        cout << 4 << '\n'
             << 1 << ' ' << n - 1 << '\n'
             << 1 << ' ' << n - 1 << '\n'
             << n - 1 << ' ' << n << '\n'
             << n - 1 << ' ' << n << '\n';
    }
    else
        cout << 2 << '\n'
             << 1 << ' ' << n << '\n'
             << 1 << ' ' << n << '\n';
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
