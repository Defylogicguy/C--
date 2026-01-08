/*************************
  Author: Defy logic guy
  22:58:56 - 10/08/2025
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
#define NAME "2131F"

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    vector<int> one(n), two(n);

    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += a[i] - '0';
        one[i] = 2 * cur - i - 1;
    }

    cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += b[i] - '0';
        two[i] = 2 * cur - i - 1;
    }

    sort(all(two));
    vector<int> pf(n + 1, 0);
    partial_sum(all(two), pf.begin() + 1);

    int sum = 0;
    for (int x : one)
    {
        auto it = lower_bound(all(two), -x);
        int t = it - two.begin();
        sum += (-x * t - pf[t]) + (x * (n - t) + pf[n] - pf[t]);
    }

    cout << (n * n * (n + 1) - sum) / 2 << '\n';
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
