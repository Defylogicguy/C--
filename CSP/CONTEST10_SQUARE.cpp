/*************************
  Author: Defy logic guy
  16:10:56 - 10/05/2025
*************************/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
#define endl '\n'
#define NAME "CONTEST10_SQUARE"

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0 ; i < n; i++)
        cin >> a[i];
    reverse(all(a));
    vector<int> d(n + 3, 0), d1(n + 3, 0), d2(n + 3, 0);
    while (q--)
    {
        int x, l;
        cin >> x >> l;
        int one = n - x - l + 2, two = one + l - 1, tri = -2ll * (one - 1), fur = (one - 1)* (one - 1); 
        d2[one]++;
        d2[two + 1]--;
        d1[one ] += tri;
        d1[two + 1] -= tri;
        d[one] += fur;
        d[two + 1] -= fur;
    }

    int cur = 0, cur1 = 0, cur2 = 0;
    for (int i = 1; i <= n; i++)
    {
        cur2 += d2[i];
        cur1 += d1[i];
        cur += d[i];
        a[i - 1] += cur2 * i * i + cur1 * i + cur;
    }

    reverse(all(a));
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
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
