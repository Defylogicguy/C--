/*************************
  Author: Defy logic guy
  09:09:08 - 26/04/2025
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
#define NAME "NOBITA"
int n, k;
vector<int> a;

int f(int x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            int l = i + 1, r = n - 1, ans = n;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (a[i] * a[mid] <= x)
                {
                    ans = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            cnt += (n - ans);
        }
        else if (a[i] > 0)
        {
            int l = i + 1, r = n - 1, ans = i;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (a[i] * a[mid] <= x)
                {
                    ans = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            cnt += (ans - i);
        }
        else if (x >= 0)
            cnt += (n - i - 1);
    }
    return cnt;
}

void solve()
{
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));

    int l = -1e18, r = 1e18, ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (f(mid) >= k)
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
