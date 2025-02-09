/*************************
  Author: Defy logic guy
  20:59:02 - 08/02/2025
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
#define NAME "K_EVEN"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> even(k, 0), odd(k, 0);
    for (int i = 0; i < n; i++)
        if (a[i] & 1)
            odd[i % k]++;
        else
            even[i % k]++;

    int idk = 0, cost = 0;
    for (int i = 0; i < k; i++)
    {
        idk += (even[i] < odd[i]);
        cost += min(even[i], odd[i]);
    }

    if (idk & 1)
    {
        int _min = LLONG_MAX;
        for (int i = 0; i < k; i++)
            _min = min(_min, abs(even[i] - odd[i]));
        cost += _min;
    }

    cout << cost << endl;
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
