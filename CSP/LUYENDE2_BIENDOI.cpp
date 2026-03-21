/*************************
  Author: Defy logic guy
  14:51:18 - 14/03/2026
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
    for (auto it = c.begin(); it != c.end(); it++)
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
#define NAME "BIENDOI"

const int maxn = 2e6 + 5;
bool p[maxn];
int d[maxn];
void pre()
{
    fill(p, p + maxn, true);
    fill(d, d + maxn, LLONG_MAX);
    p[0] = p[1] = false;
    for (int i = 2; i * i < maxn; i++)
        if (p[i])
            for (int j = i * i; j < maxn; j += i)
                p[j] = false;
    int lst = -1;
    for (int i = 0; i < maxn; i++)
    {
        if (p[i])
            lst = i;
        if (lst != -1)
            d[i] = i - lst;
    }
    lst = -1;
    for (int i = maxn - 1; i >= 0; i--)
    {
        if (p[i])
            lst = i;
        if (lst != -1)
            d[i] = min(d[i], lst - i);
    }
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        a[i] = d[x];
    }
    int cur = 0;
    for (int i = 0; i < k; i++)
        cur += a[i];
    int ans = cur;
    for (int i = k; i < n; i++)
        cur = cur - a[i - k] + a[i], ans = min(ans, cur);
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

    int tt = 1;
    // cin >> tt;

    pre();

    while (tt--)
        solve();

    return 0;
}
