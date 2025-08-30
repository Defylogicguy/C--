/*************************
  Author: Defy logic guy
  23:26:12 - 04/09/2025
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
#define NAME "1366D"

const int maxn = 1e7 + 5;
int spf[maxn];

void pre()
{
    iota(spf, spf + maxn, 0);
    for (int i = 2; i * i < maxn; i++)
        if (spf[i] == i)
            for (int j = i * i; j < maxn; j += i)
                if (spf[j] == j)
                    spf[j] = i;
}

void solve()
{
    pre();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<int, int>> ans(n);
    for (int i = 0; i < n; i++)
    {
        int num = a[i];
        vector<int> f;
        while (num > 1)
        {
            int p = spf[num];
            f.pb(p);
            while (num % p == 0)
                num /= p;
        }
        if (f.size() == 1)
            ans[i] = {-1, -1};
        else
        {
            int one = 1;
            for (int j = 1; j < f.size(); j++)
                one *= f[j];
            ans[i] = {f[0], one};
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i].first << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << ans[i].second << ' ';
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
