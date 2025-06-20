/*************************
  Author: Defy logic guy
  22:50:10 - 20/06/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "ABC081B"

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        flag &= (a[i] % 2 == 0);
    }
    int ans = 0;
    while (flag)
    {
        ans++;
        for (int i = 0; i < n; i++)
        {
            a[i] /= 2;
            flag &= (a[i] % 2 == 0);
        }
    }
    cout << ans << '\n' ;
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
