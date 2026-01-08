/*************************
  Author: Defy logic guy
  22:33:22 - 11/02/2025
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
#define NAME "A183D"

vector<int> a(200005, 0);
void solve()
{
    int n, w;
    cin >> n >> w;

    for (int i = 0; i < n; i++)
    {
        int s, t, p;
        cin >> s >> t >> p;
        a[s] += p;
        a[t] -= p;
    }

    for (int i = 0; i < 200005; i++)
    {
        a[i + 1] += a[i];
        if (a[i] > w)
        {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
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
