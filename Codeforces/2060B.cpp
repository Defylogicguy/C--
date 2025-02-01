/*************************
  Author: Defy logic guy
  21:10:46 - 19/01/2025
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
#define NAME "2060B"

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        sort(all(a[i]));
    map<vector<int>, int> mp;
    for (int i = 0; i < n; i++)
        mp[a[i]] = i;
    sort(all(a), [](vector<int> a, vector<int> b)
         { return a[0] < b[0]; });
    int lst = a[0][0];
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            if (a[i][j] < lst)
            {
                cout << -1 << '\n';
                return;
            }
            else
                lst = a[i][j];
    for (int i = 0; i < n; i++)
        cout << mp[a[i]] + 1 << ' ';
    cout << '\n';
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
