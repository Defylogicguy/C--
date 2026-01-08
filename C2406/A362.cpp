/*************************
  Author: Defy logic guy
  14:38:44 - 03/05/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "A362"

void solve()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    if (a < b)
        swap(a, b);
    if (a < c)
        swap(a, c);
    if (a < d)
        swap(a, d);
    if (a < e)
        swap(a, e);
    if (b < c)
        swap(b, c);
    if (b < d)
        swap(b, d);
    if (b < e)
        swap(b, e);
    if (c < d)
        swap(c, d);
    if (c < e)
        swap(c, e);
    if (d < e)
        swap(d, e);
    cout << ((a == b and b == c and d == e) or (a == b and c == d and d == e) ? "Yes\n" : "No\n");
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
