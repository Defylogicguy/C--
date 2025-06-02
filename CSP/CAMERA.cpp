/*************************
  Author: Defy logic guy
  14:27:45 - 02/06/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float double
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define maxall(a) *max_element(all(a))
#define minall(a) *min_element(all(a))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define endl '\n'
#define NAME "CAMERA"

bool f(int mid, const vector<int> &a, int m)
{
    int cnt = 0;
    int i = 0;

    while (i < a.size())
    {
        int j = upper_bound(i + all(a), a[i] + mid) - a.begin() - 1;
        cnt++;
        if (cnt > m)
            return false;
        i = upper_bound(j + all(a), a[j] + mid) - a.begin();
    }

    return cnt <= m;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = a.back() - a.front(), ans = 0;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (f(mid, a, m))
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
