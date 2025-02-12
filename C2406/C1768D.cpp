/*************************
  Author: Defy logic guy
  20:49:20 - 11/02/2025
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
#define NAME "C1768D"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i]--;

    vector<int> loopy(n, 0);
    int cur = 1, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (loopy[i])
            continue;

        int tmp = i;
        while (!loopy[tmp])
        {
            loopy[tmp] = cur;
            tmp = a[tmp];
            ans++;
        }
        cur++, ans--;
    }

    for (int i = 1; i < n; i++)
        if (loopy[i] == loopy[i - 1])
        {
            cout << ans - 1 << endl;
            return;
        }
    cout << ans + 1 << endl;
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