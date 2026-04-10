/*************************
  Author: Defy logic guy
  19:08:44 - 03/04/2026
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
#define NAME "BOS_TAMGIAC"

void solve()
{
    int n, t;
    cin >> n >> t;
    vector<int> sq(n), a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    for (int i = 0; i < n; i++)
        sq[i] = a[i] * a[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int t1 = lower_bound(all(a), a[i] + a[j]) - a.begin() - 1;
            if (t1 <= j)
                continue;
            int tmp = sq[i] + sq[j];
            if (t == 2)
                ans += upper_bound(sq.begin() + j + 1, sq.begin() + t1 + 1, tmp) - lower_bound(sq.begin() + j + 1, sq.begin() + t1 + 1, tmp);
            else if (t == 1)
            {
                auto it = lower_bound(sq.begin() + j + 1, sq.begin() + t1 + 1, tmp);
                ans += it - (sq.begin() + j + 1);
            }
            else if (t == 3)
            {
                auto it = upper_bound(sq.begin() + j + 1, sq.begin() + t1 + 1, tmp);
                ans += t1 - (it - sq.begin()) + 1;
            }
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
