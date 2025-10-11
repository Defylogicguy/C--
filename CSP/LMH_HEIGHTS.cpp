/*************************
  Author: Defy logic guy
  14:18:22 - 04/10/2025
*************************/
#include <bits/stdc++.h>
using namespace std;
ostream &operator<<(ostream &os, const string &s)
{
    os.write(s.data(), s.size());
    return os;
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T>
auto operator<<(ostream &os, const T &c) -> typename enable_if<!is_same<T, string>::value, decltype(c.begin(), c.end(), os)>::type
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
#define NAME "LMH_HEIGHTS"

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> res(n + 1), a(n + 1);
    res[k] = x;
    for (int i = 2; i <= n; i++)
        cin >> a[i];
    int t = k;
    while (k)
    {
        int j = 0;
        for (int i = k - 1; i >= 1; i--)
            if (a[i] >= 0)
            {
                j = i;
                break;
            }
        res[j] = x - a[k];
        for (int i = j + 1; i <= k - 1; i++)
            res[i] = res[j] + a[i];
        k = j;
        x = res[k];
    }
    int cur = 0;
    for (int i = 1; i <= t; i++)
        cur = max(cur, res[i]);
    for (int i = t + 1; i <= n; i++)
        res[i] = a[i] + cur, cur = max(cur, res[i]);
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' '; 
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
