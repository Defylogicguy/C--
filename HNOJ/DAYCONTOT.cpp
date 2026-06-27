/*************************
  Author: Defy logic guy
  19:33:32 - 19/06/2026
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
#define NAME "DAYCONTOT"

const int N = 1e5 + 5;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> mx(maxall(a) + 1, 0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        vector<int> p;
        for (int j = 2; j * j <= x; j++)
            if (x % j == 0)
            {
                p.pb(j);
                while (x % j == 0)
                    x /= j;
            }
        if (x > 1)
            p.pb(x);
        int cur = 0;
        for (int pp : p)
            cur = max(cur, mx[pp]);
        ans = max(ans, cur + 1);
        for (int p : p)
            mx[p] = max(mx[p], cur + 1);
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

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
