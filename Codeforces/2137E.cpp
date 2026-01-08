/*************************
  Author: Defy logic guy
  22:06:08 - 07/09/2025
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
#define NAME "2137E"

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (k == 0)
    {
        cout << accumulate(all(a), 0ll) << '\n';
        return;
    }
    auto fmex = [](const vector<int> &f) -> int
    {
        for (int i = 0; i < f.size(); i++)
            if (!f[i])
                return i;
        return f.size();
    };
    auto next = [n, fmex](const vector<int> &a) -> vector<int>
    {
        vector<int> f(n + 2, 0);
        for (int i : a)
            f[i]++;
        int mex = fmex(f);
        vector<int> b(n);
        for (int i = 0; i < n; i++)
            if (a[i] < mex and f[a[i]] == 1)
                b[i] = a[i];
            else
                b[i] = mex;
        return b;
    };
    vector<int> a1 = next(a);
    if (k == 1)
    {
        cout << accumulate(all(a1), 0ll) << '\n';
        return;
    }
    vector<int> a2 = next(a1);
    if (k == 2)
    {
        cout << accumulate(all(a2), 0ll) << '\n';
        return;
    }
    vector<int> a3 = next(a2);
    cout << (a3 == a2 ? accumulate(all(a2), 0ll) : (k & 1 ? accumulate(all(a3), 0ll) : accumulate(all(a2), 0ll))) << '\n';
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
