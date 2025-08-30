/*************************
  Author: Defy logic guy
  20:27:18 - 10/09/2025
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
#define NAME "1370D"

int n, k;
vector<int> a;

bool ok(int x)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt % 2 == 0)
            cnt++;
        else if (a[i] <= x)
            cnt++;
    }
    if (cnt >= k)
        return true;
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt % 2 == 1)
            cnt++;
        else if (a[i] <= x)
            cnt++;
    }
    return cnt >= k;
}

void solve()
{
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 1, r = 1e9, ans = r;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (ok(mid))
            ans = mid, r = mid - 1;
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
