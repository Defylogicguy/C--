/*************************
  Author: Defy logic guy
  22:05:30 - 09/05/2025
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
#define endl '\n'
#define NAME "BONAM"

void solve()
{
    int n, w1, w2;
    cin >> n >> w1 >> w2;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> l1(n, LLONG_MIN), l2(n, LLONG_MIN), r1(n, LLONG_MIN), r2(n, LLONG_MIN);
    int one = LLONG_MIN, two = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        if (i >= 1)
        {
            l1[i] = one;
            l2[i] = two;
        }

        one = max(one, w1 * a[i]);
        if (i >= 1)
            two = max(two, l1[i] + w2 * a[i]);
    }

    one = two = LLONG_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i <= n - 2)
        {
            r1[i] = one;
            r2[i] = two;
        }

        one = max(one, w1 * a[i]);
        if (i <= n - 2)
            two = max(two, r1[i] + w2 * a[i]);
    }

    int ans = LLONG_MIN;
    for (int i = 2; i < n - 2; i++)
        if (l2[i] != LLONG_MIN && r2[i] != LLONG_MIN)
            ans = max(ans, l2[i] + a[i] + r2[i]);
    cout << ans;
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
