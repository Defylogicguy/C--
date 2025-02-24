/*************************
  Author: Defy logic guy
  21:18:27 - 22/02/2025
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
#define NAME "C2026D"

vector<int> a, b, c, d;
int n;
int f(int x)
{
    if (x == 0)
        return 0;

    int l = 0, r = n + 1, ans = 0;
    while (l + 1 < r)
    {
        int mid = l + (r - l) / 2;
        if ((2 * n - mid + 1) * mid / 2 <= x)
        {
            ans = mid;
            l = mid;
        }
        else
            r = mid;
    }

    return d[ans] + c[ans + x - (2 * n - ans + 1) * ans / 2] - c[ans] - (x - (2 * n - ans + 1) * ans / 2) * b[ans];
}
void solve()
{
    cin >> n;
    a.resize(n + 1), b.resize(n + 1), c.resize(n + 1), d.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
        c[i] = c[i - 1] + b[i];
    }

    for (int i = 1; i <= n; i++)
        d[i] = d[i - 1] + (c[n] - c[i - 1]) - b[i - 1] * (n - i + 1);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << f(r) - f(l - 1) << endl;
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
