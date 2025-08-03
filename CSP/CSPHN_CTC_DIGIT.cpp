/*************************
  Author: Defy logic guy
  15:19:44 - 02/08/2025
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
#define NAME "CSPHN_CTC_DIGIT"

int one(int b, int c, int d)
{
    if (!c )
        return 0;
    int t = one(b, c / 2, d);
    t = (t + t) % d;
    if (c & 1)
        t = (t + b) % d;
    return t;
}

int two(int b, int c, int d)
{
    if (!c)
        return 1;
    int t = two(b, c / 2, d);
    t = one(t, t, d) % d;
    if (c & 1)
        t = one(t, b, d) % d;
    return t;
}

void solve()
{
    int a, b, k;
    cin >> a >> b >> k;
    a %= b;
    a = one(a, two(10, k - 1, b), b);
    cout << a * 10 / b << '\n';
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
