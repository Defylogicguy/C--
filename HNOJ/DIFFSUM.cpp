/*************************
  Author: Defy logic guy
  18:53:19 - 24/10/2025
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
#define NAME "DIFFSUM"

int n;
int f(const set<int> &s, int i)
{
    auto it = s.find(i);
    if (it == s.end())
        return 0;
    int l = (it == s.begin() ? 0 : *prev(it));
    return (i - l) * (n - i + 1);
}

void solve()
{
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    map<int, set<int>> pos;
    for (int i = 1; i <= n; i++)
        pos[a[i]].insert(i);

    int ans = 0;
    for (auto &i : pos)
    {
        auto &s = i.second;
        for (int j : s)
            ans += f(s, j);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int i, x;
        cin >> i >> x;
        if (a[i] == x)
        {
            cout << ans << '\n';
            continue;
        }

        auto &old = pos[a[i]];
        auto it = old.find(i), itn = next(it);
        bool flag = (itn != old.end());
        int t = flag ? *itn : -1;

        ans -= f(old, i);
        if (flag)
            ans -= f(old, t);

        old.erase(it);

        if (flag)
            ans += f(old, t);

        a[i] = x;
        auto &nw = pos[x];
        auto ir = nw.lower_bound(i);
        bool flag2 = (ir != nw.end());
        int t2 = flag2 ? *ir : -1;

        if (flag2)
            ans -= f(nw, t2);

        nw.insert(i);

        ans += f(nw, i);
        if (flag2)
            ans += f(nw, t2);

        cout << ans << '\n';
    }
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
