/*************************
  Author: Defy logic guy
  21:59:53 - 13/09/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> decltype(c.begin(), c.end(), os)
{
    for (auto it = c.begin(); it != c.end(); ++it)
        os << (it == c.begin() ? "{" : ", ") << *it;
    return os << "}";
}
#define dbg(x) cerr << #x << " = " << (x) << '\n';
#define int long long
#define float double
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define maxall(x) *max_element(all(x))
#define minall(x) *min_element(all(x))
#define heap priority_queue
#define pb push_back
#define MOD 1000000007
#define NAME "2148E"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n ;i++)
        cin >> a[i];
    vector<int> cnt(n + 1, 0);
    for (int i : a)
        cnt[i]++;
    for (int i = 1; i <= n;i++)
        if (cnt[i] % k != 0)
        {
            cout << 0 << '\n';
            return;
        }
    vector<int> f(n + 1, 0);
    int i = 0, ans = 0;
    for (int j = 0; j < n; j++)
    {
        f[a[j]]++;
        while (f[a[j]] > cnt[a[j]] / k)
        {
            f[a[i]]--;
            i++;
        }
        ans += j - i + 1;
    }
    cout << ans << '\n';
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
    cin >> tt;

    while (tt--)
        solve();

    return 0;
}
