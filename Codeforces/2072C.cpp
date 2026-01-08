/*************************
  Author: Defy logic guy
  21:46:14 - 25/02/2025
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
#define NAME "2072C"

int find(int n)
{
    if (n <= 1)
        return 0;
    int m = n - 1;
    int idk = 31 - __builtin_clzll(m);
    int one = (1 << idk);
    if (n != (1 << idk))
        one *= 2;
    return one - 1;
}

void solve()
{
    int n, x;
    cin >> n >> x;

    int gud = 0;
    for (int i = 0; i <= n; i++)
    {
        int idk = find(i);
        if ((idk & (~x)) != 0)
            continue;
        int ned = i + (idk != x);
        if (ned <= n)
            gud = i;
    }

    vector<int> a;
    if (gud == 0)
        a.pb(x);
    else
    {
        for (int i = 0; i < gud; i++)
            a.pb(i);
        int idk = find(gud);
        if (idk != x)
        {
            int one = x & (~idk);
            a.pb(one);
        }
    }

    vector<int> res(all(a));
    int idk = (gud > 0 ? 0 : x);
    while (res.size() < n)
        res.pb(idk);

    for (int i : res)
        cout << i << ' ';
    cout << endl;
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
