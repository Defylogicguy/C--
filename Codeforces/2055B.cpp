/*************************
  Author: Defy logic guy
  21:32:19 - 12/01/2025
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
#define NAME "2055B"

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    int idk = 0;
    for (int i = 0; i < n; i++)
        idk += (b[i] > a[i]);
    if (idk >= 2)
    {
        cout << "NO\n";
        return;
    }
    else if (idk == 0)
    {
        cout << "YES\n";
        return;
    }

    for (int i = 0; i < n; i++)
        if (a[i] == b[i])
        {
            cout << "NO\n";
            return;
        }
    idk = LLONG_MAX;
    int idk1 = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < b[i])
            idk1 = max(idk1, b[i] - a[i]);
        else
            idk = min(idk, a[i] - b[i]);

    if (idk >= idk1)
        cout << "YES\n";
    else
        cout << "NO\n";
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
