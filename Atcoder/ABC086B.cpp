/*************************
  Author: Defy logic guy
  22:22:17 - 12/05/2025
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
#define NAME "ABC086B"

void solve()
{
    int a, b;
    cin >> a >> b;
    int c = 0;
    if (0 <= b and b < 10)
        c = a * 10 + b;
    if (10 <= b and b < 100)
        c = a * 100 + b;
    if (b == 100)
        c = a * 1000 + b;
    int s = sqrt(c);
    cout << (s * s == c ? "Yes\n" : "No\n");
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
