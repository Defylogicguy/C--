/*************************
  Author: Defy logic guy
  09:20:38 - 26/04/2025
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
#define NAME "AVERAGEMAX"

bool f(float mid, const vector<int> &a, int k)
{
    int n = a.size();
    vector<float> b(n);
    for (int i = 0; i < n; i++)
        b[i] = a[i] - mid;

    vector<float> pf(n + 1, 0);
    for (int i = 0; i < n; i++)
        pf[i + 1] = pf[i] + b[i];

    float idk = 0;
    for (int i = k; i <= n; i++)
    {
        if (pf[i] - idk >= 0)
            return true;
        idk = min(idk, pf[i - k + 1]);
    }
    return false;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    float l = -1e9, r = 1e9;
    float ans = 0;
    const float dif = 1e-6;

    while (r - l > dif)
    {
        float mid = (l + r) / 2;
        if (f(mid, a, k))
        {
            ans = mid;
            l = mid;
        }
        else
            r = mid;
    }

    cout << fixed << setprecision(3) << ans << endl;
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
