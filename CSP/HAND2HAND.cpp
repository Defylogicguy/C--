/*************************
  Author: Defy logic guy
  15:34:08 - 29/11/2025
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
#define NAME "HAND2HAND"

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], pos[a[i]] = i;

    int cnt = 0;
    auto f = [&](int i) -> int
    {
        if (i < 1 or i >= n)
            return 0;
        return pos[i + 1] < pos[i];
    };

    for (int i = 1; i <= n - 1; i++)
        cnt += f(i);

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        
        if (x == y)
        {
            cout << (cnt <= 1 ? "YES\n" : "NO\n");
            continue;
        }

        vector<int> t = {x - 1, x, y - 1, y};
        sort(all(t));
        t.erase(unique(all(t)), t.end());

        for (int i : t)
            cnt -= f(i);

        swap(pos[x], pos[y]);

        for (int i : t)
            cnt += f(i);

        cout << (cnt <= 1 ? "YES\n" : "NO\n");
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

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
