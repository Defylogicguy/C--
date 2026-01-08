/*************************
  Author: Defy logic guy
  20:12:01 - 15/02/2025
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
#define NAME "FC136_SPLITTING"
bool f(vector<int> &a, int mid, int k)
{
    int n = a.size();
    int cur = 0, cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if (cur + a[i] > mid)
        {
            cur = a[i];
            cnt++;
        }
        else
            cur += a[i];
    }

    return cnt <= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 0;
    int l = *max_element(all(a)), r = accumulate(all(a), 0ll);
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (f(a, mid, k))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << endl;
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
