/*************************
  Author: Defy logic guy
  19:51:12 - 24/09/2025
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
#define NAME "1486C2"

void solve()
{
    int n;
    cin >> n;
    auto ask = [](int l, int r) -> int
    {
        if (l == r)
            return -1;
        cout << "? " << l << ' ' << r << endl;
        int x;
        cin >> x;
        return x;
    };
    int smx = ask(1, n);
    int t = ask(1, smx);
    if (smx == 1 or t != smx)
    {
        int l = smx, r = n;
        while (l + 1 < r)
        {
            int mid = l + r >> 1;
            if (ask(smx, mid) == smx)
                r = mid;
            else
                l = mid;
        }
        cout << "! " << r << endl;
    }
    else
    {
        int l = 1, r = smx;
        while (l + 1 < r)
        {
            int mid = l + r >> 1;
            if (ask(mid, smx) == smx)
                l = mid;
            else
                r = mid;
        }
        cout << "! " << l << endl;
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
