/*************************
  Author: Defy logic guy
  22:13:06 - 25/02/2025
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
#define NAME "2072D"

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 1, r = 1, _min = 0;
    for (int i = 0; i < n; i++)
    {
        int one = 0, two = 0;
        for (int j = i + 1; j < n; j++)
        {
            one += (a[j] > a[i]);
            two += (a[j] < a[i]);
            if (_min > one - two)
            {
                _min = one - two;
                l = i + 1;
                r = j + 1;
            }
        }
    }
    cout << l << ' ' << r << endl;
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
