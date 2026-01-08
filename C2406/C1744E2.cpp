/*************************
  Author: Defy logic guy
  21:46:39 - 11/01/2025
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
#define NAME "C1744E2"

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<int> diva;
    for (int i = 1; i * i <= a; i++)
        if (a % i == 0)
        {
            diva.pb(i);
            if (a / i != i)
                diva.pb(a / i);
        }
    vector<int> divb;
    for (int i = 1; i * i <= b; i++)
        if (b % i == 0)
        {
            divb.pb(i);
            if (b / i != i)
                divb.pb(b / i);
        }

    for (int i : diva)
        for (int j : divb)
        {
            int idk = i * j;
            int x = c - c % idk, y = d - d % (a * b / idk);
            if (x > a and y > b)
            {
                cout << x << ' ' << y << endl;
                return;
            }
        }
    cout << "-1 -1\n";
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
