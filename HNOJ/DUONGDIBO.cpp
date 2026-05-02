/*************************
  Author: Defy logic guy
  00:30:14 - 21/04/2026
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
#define NAME "DUONGDIBO"

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<pair<int, int>> a(q);
    for (int i = 0; i < q; i++)
        cin >> a[i].first >> a[i].second;
    sort(all(a));
    vector<int> pfmn(q), pfmx(q), sfmn(q), sfmx(q);
    pfmn[0] = pfmx[0] = a[0].second;
    for (int i = 1; i < q; i++)
        pfmn[i] = min(pfmn[i - 1], a[i].second), pfmx[i] = max(pfmx[i - 1], a[i].second);
    sfmn[q - 1] = sfmx[q - 1] = a[q - 1].second;
    for (int i = q - 2; i >= 0; i--)
        sfmn[i] = min(sfmn[i + 1], a[i].second), sfmx[i] = max(sfmx[i + 1], a[i].second);
    int l = 1, r = min(m, n);
    int ans = r;
    while (l <= r)
    {
        int mid = l + r >> 1;
        auto f = [&](int x) -> bool
        {
            int i = 0;
            for (int j = 0; j < q; j++)
            {
                while (i <= j and a[j].first - a[i].first + 1 > x)
                    i++;
                int mn = LLONG_MAX, mx = LLONG_MIN;
                if (i >= 1)
                    mn = min(mn, pfmn[i - 1]), mx = max(mx, pfmx[i - 1]);
                if (j + 1 < q)
                    mn = min(mn, sfmn[j + 1]), mx = max(mx, sfmx[j + 1]);
                if (mn == LLONG_MAX)
                    return true;
                if (mx - mn + 1 <= x)
                    return true;
            }
            return false;
        };
        if (f(mid))
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

    int tt = 1;
    // cin >> tt;

    while (tt--)
        solve();

    return 0;
}
