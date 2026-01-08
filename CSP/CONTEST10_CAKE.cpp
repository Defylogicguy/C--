/*************************
  Author: Defy logic guy
  15:05:37 - 29/03/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "CONTEST10_CAKE"

bool f(int mid, vector<int> &a, vector<int> &b, int p)
{
    int i = 0, j = 0, n = a.size(), k = b.size();
    while (i < n and j < k)
    {
        if (abs(a[i] - b[j]) + abs(b[j] - p) <= mid)
            i++;
        j++;
    }
    return i == n;
}


void solve()
{
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> a(n), b(k);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
        cin >> b[i];
    sort(all(a));
    sort(all(b));

    int l = 0, r = 2e9, ans = r + 1;
    while (l <= r)
    {
        int mid = (r + l) / 2;
        if (f(mid, a, b, p))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
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
