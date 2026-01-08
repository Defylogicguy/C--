/*************************
  Author: Defy logic guy
  13:32:16 - 30/08/2025
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
#define NAME "2132B"

void solve()
{
    int n;
    cin >> n;
    int cur = 1;
    vector<int> v;
    for (int i = 1; cur + 1 <= n; i++)
    {
        cur *= 10;
        if (n % (cur + 1) == 0)
            v.pb(n / (cur + 1));
    }
    sort(all(v));
    cout << v.size() << '\n';
    for (int i : v)
        cout << i << ' ';
    if (v.size())
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
