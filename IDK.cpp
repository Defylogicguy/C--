/*************************
  Author: Defy logic guy
  10:51:17 - 02/03/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define heap priority_queue
#define pb push_back
#define MOD 998244353
#define endl '\n'
#define NAME "IDK"

int n;
vector<pair<int, int>> a;
set<int> p, q;

int s(int x) { return (x > 0) - (x < 0); }
int d(int x, int y, int z) { return 1 + abs(s(x - y)) + abs(s(x * y - x * z + z * z - y * z)); }

int binPow(int x, int y)
{
    if (y == 0)
        return 1;
    int ans = binPow((x * x) % MOD, y >> 1);
    if (y & 1)
        ans = (ans * x) % MOD;
    return ans;
}

void s1()
{
    int ans = 0;
    sort(all(a));
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
            {
                if (a[i].first + a[j].first <= a[k].first)
                    break;
                int idk = binPow(a[i].first + a[j].first + a[k].first, d(a[i].second, a[j].second, a[k].second));
                ans = (ans + idk) % MOD;
            }
    cout << ans << endl;
}

void s2()
{
    vector<int> b(n), pf(n + 1, 0);
    int ans = 0;
    sort(all(a));
    for (int i = 0; i < n; i++)
        b[i] = a[i].first;
    for (int i = 1; i <= n; i++)
        pf[i] = (pf[i - 1] + b[i - 1]) % MOD;
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
        {
            int it = lower_bound(j + 1 + all(b), b[i] + b[j]) - b.begin() - 1;
            ans = (ans + (b[i] % MOD + b[j] % MOD) % MOD * (it - j) % MOD + (pf[it + 1] - pf[j + 1]) % MOD) % MOD;
        }
    cout << ans << endl;
}

void solve()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
        p.insert(a[i].first);
        q.insert(a[i].second);
    }
    if (n <= 200)
        s1();
    else if (q.size() == 1)
        s2();
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