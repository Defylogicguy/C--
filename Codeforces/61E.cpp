/*************************
  Author: Defy logic guy
  14:19:07 - 03/09/2025
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
#define NAME "61E"

const int maxn = 1e6 + 5;
struct Fen
{
    vector<int> a;
    Fen(int n) : a(n + 2, 0) {}
    inline void add(int i, int x)
    {
        while (i < a.size())
        {
            a[i] += x;
            i += i & -i;
        }
    }
    inline int sum(int i)
    {
        int ans = 0;
        while (i)
        {
            ans += a[i];
            i -= i & -i;
        }
        return ans;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    cin >> a[i];
    vector<int> sa = a;
    sort(all(sa));
    sa.erase(unique(all(sa)), sa.end());
    for (int &x : a)
    x = lower_bound(all(sa), x) - sa.begin() + 1;
    Fen one(sa.size()), two(sa.size());
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
    {
        l[i] = i - one.sum(a[i] - 1);
        one.add(a[i], 1);
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans += l[i] * two.sum(a[i] - 1);
        two.add(a[i], 1);
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
